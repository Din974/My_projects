import { press_any_key, rl } from "./getInput";
import { getRandomNumber } from "./getRandomNumber";
import { getRandomPlayer, getRandomEnemy, getRandomBoss } from "./get_values_from_json";
import { charactere } from "./interfaces";

export interface actions {
    link:charactere,
    enemy:charactere,
    encounter:boolean
}

export function getInputLevelandExperience(enemy:charactere, link:charactere, encounter:boolean) : Promise<actions> { // recuperer l'entrée utilisateur pour soit attaquer ou soit se heal
    let options:string = '1.Attack   2.Heal\n\n';

    if (encounter === false && enemy.id < 9)
      options = options + "You encounter a " + enemy.name + "\n\n";
    else if (encounter === false && enemy.id === 9) {
      options = options + "WARNING BOSS APPEARS!!!!!!!\n" + "You encounter a " + enemy.name + "\n\n";
    }
    return new Promise(async (resolve) => {
      if (enemy.current_hp > 0) {
          rl.question(options, async (userInput) => {
              if (userInput === "1") {
                  console.log("\nYou attacked and dealt " + link.strength + " damages!");
                  if (encounter === false)
                    resolve({ enemy: { ...enemy, current_hp: enemy.current_hp - link.strength}, link , encounter: true});
                  else
                    resolve({ enemy: { ...enemy, current_hp: enemy.current_hp - link.strength }, link, encounter });
              } else if (userInput === "2") {
                  console.log("You used Heal!");
                  if (encounter === false)
                    resolve({ enemy, link: { ...link, current_hp: (link.current_hp + (link.hp_max / 2) > link.hp_max) ? link.hp_max : link.current_hp += (link.hp_max / 2)}, encounter:true });
                  else
                    resolve({ enemy, link: { ...link, current_hp: (link.current_hp + (link.hp_max / 2) > link.hp_max) ? link.hp_max : link.current_hp += (link.hp_max / 2) }, encounter });
              } else {
                  const result = await getInputLevelandExperience(enemy, link, encounter);
                  resolve(result);
              }
          });
      } else {
          resolve({ enemy, link, encounter});
      }
    });
  }

export function display_game(enemy: charactere, link:charactere, i:number, experience:number, level_up:boolean, level:number) {
        console.log("============ TURN " + (i + 1) + " ============");
        console.log('\x1b[31m%s\x1b[0m', enemy.name); // couleur rouge
        process.stdout.write("HP: "); // console.log pour ne pas passer a la ligne
        if (enemy.current_hp > 0)
            for (let i = 0; i < enemy.hp_max; i++)
                if (i < enemy.current_hp)
                    process.stdout.write('❤️');
                else
                    process.stdout.write('♡');
        else
            for (let i = 0; i < enemy.hp_max; i++)
                process.stdout.write('♡');
        if (enemy.current_hp <= 0)
            enemy.current_hp = 0;
        console.log(" " + enemy.current_hp + "/" + enemy.hp_max + "\n");
        console.log('\x1b[32m%s\x1b[0m', link.name) ;
        process.stdout.write("HP: ");
        for (let i = 0; i < link.hp_max; i++)
            if (i < link.current_hp)
                process.stdout.write('❤️');
            else
                process.stdout.write('♡');
        if (link.current_hp <= 0)
            link.current_hp = 0;
        console.log(" " + link.current_hp + "/" + link.hp_max + "\n");
        if (level_up === false)
            console.log("You are actually level " + level)
        else
            console.log("You are actually level " + (level + 1))
        process.stdout.write("XP: ");
        for (let i = 0; i <= 50; i++) {
            if (i < experience)
                process.stdout.write('|');
            else
                process.stdout.write('.');
        }
        console.log(" " + experience + "/50\n");
        if (link.current_hp > 0 && enemy.current_hp > 0) // si link et l'ennemi est encore en vie
            console.log("---------- Options --------");
}

export function enemy_attack(action:actions) : actions {
    if (action.enemy.current_hp > 0) { // si l'ennemi est encore en vie
        action.link.current_hp -= action.enemy.strength; // la vie actuelle de link = la vie actuelle de link - la force de l'ennemi
        console.log("\n" + action.enemy.name + " attacked and dealt " + action.enemy.strength + " damages!\n")
    }
    return action;
}

function link_states_up(link:charactere) : charactere {
    link = {id:link.id, name:link.name, hp_max:link.hp_max + 2, current_hp:link.current_hp,
        mp:link.mp + 2, strength:link.strength + 2, int:link.int + 2, def:link.def + 2,
        res:link.res + 2, spd:link.spd + 2, luck:link.luck + 2, race:link.race, class:link.class,
        rarity:link.rarity}
    return link;
}

export async function level_and_experience()
{
    let link:charactere = getRandomPlayer();
    let id = 1;
    let current_ennemy:boolean = false;
    let linkDied: boolean = false;
    let experience: number = 0;
    let level:number = 1;
    let level_up:boolean = false;

    for (let i = 0; (id <= 10); i++) {
        let encounter:boolean = false;
        let enemy: charactere = {   id:id, name: "", hp_max: NaN, current_hp: NaN, mp:NaN,
                                    strength: NaN, int: NaN, def: NaN, res: NaN, spd: NaN,
                                    luck: NaN, race: NaN, class: NaN, rarity: NaN};

        if (id < 9) {
            enemy = getRandomEnemy();
            enemy.id = id;
        }
        else {
            enemy = getRandomBoss();
            enemy.id = id
        }
        current_ennemy = true;
        while (current_ennemy === true && !linkDied) {
            if (id < 10 && link.current_hp > 0) {
                display_game(enemy, link, i, experience, level_up, level);
                let action: actions = await getInputLevelandExperience(enemy, link, encounter);
                action = enemy_attack(action);
                link = action.link; // actualisation
                enemy = action.enemy;
                encounter = action.encounter;
            }else if (link.current_hp <= 0 && !linkDied) {  // si Link meurt je casse ma boucle et j'arrive directement a la fin de mon programme
                console.log(link.name + " died!");
                linkDied = true;
                break;
            }else if (id === 10) { // si le boss meurt je casse ma boucle et j'arrive directement a la fin de mon programme
                console.log("\nYou won");
                break;
            }
            if (enemy.current_hp <= 0) {
                let experience_obtained = 0
                if (id < 9)
                    experience_obtained += getRandomNumber(15, 50);
                else
                    experience_obtained += 50;
                console.log("You have gained " + experience_obtained + " xp")
                experience += experience_obtained;
                current_ennemy = false;
                if (id < 9) {
                    if (experience >= 50) {
                        level_up = true;
                        display_game(enemy, link, i, experience - 50, level_up, level)
                    }
                    else
                        display_game(enemy, link, i, experience, level_up, level)
                    console.log("\n" + enemy.name + " died!")
                    if (experience >= 50) {
                        console.log("LEVEL UP !!! YOU GAINED 2 STATS POINTS ON EACH STATS");
                        experience -= 50;
                        link = link_states_up(link);
                        level++;
                    }
                    level_up = false;
                    await press_any_key();
                }else {
                    display_game(enemy, link, i, experience, level_up, level)
                    console.log("\n" + enemy.name + " died!")
                    break;
                }
            }else
                i++;
        }
        id++;
    }
    rl.close();
}