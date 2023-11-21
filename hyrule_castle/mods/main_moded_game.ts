import { press_any_key, rl } from "./getInput";
import { getRandomPlayer, getRandomEnemy, getRandomBoss } from "./get_values_from_json";
import { charactere } from "./interfaces";

export interface actions {
    link:charactere,
    enemy:charactere,
    encounter:boolean
}

export function getInput(enemy:charactere, link:charactere, encounter:boolean) : Promise<actions> { // recuperer l'entrée utilisateur pour soit attaquer ou soit se heal
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
                    resolve({ enemy, link: { ...link, current_hp: (link.current_hp + (link.hp_max / 2) > link.hp_max) ? link.hp_max : link.current_hp += (link.hp_max / 2)}, encounter });
              } else {
                  const result = await getInput(enemy, link, encounter);
                  resolve(result);
              }
          });
      } else {
          resolve({ enemy, link, encounter});
      }
    });
  }

export function display_game(enemy: charactere, link:charactere, i:number) {
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

export async function main_moded_game()
{
    let link:charactere = getRandomPlayer();
    let id = 1;
    let current_ennemy:boolean = false;
    let linkDied: boolean = false;

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
                display_game(enemy, link, i);
                let action: actions = await getInput(enemy, link, encounter);
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
                current_ennemy = false;
                if (id < 9) {
                    display_game(enemy, link, i)
                    console.log("\n" + enemy.name + " died!")
                    await press_any_key();
                }else {
                    display_game(enemy, link, i)
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