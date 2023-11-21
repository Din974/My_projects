import { press_any_key, rl } from "./getInput";
import { getRandomPlayer, getRandomEnemy, getRandomBoss, get_race_from_json, get_class_from_json, get_weakness_class, get_weakness_race, get_strength_class, get_strength_race } from "./get_values_from_json";
import { charactere } from "./interfaces";

export interface actions {
    link:charactere,
    enemy:charactere,
    encounter:boolean,
    info:boolean
}

export function getInput_basicCharacteristics(enemy:charactere, link:charactere, encounter:boolean, info:boolean, match_number:number) : Promise<actions> { // recuperer l'entrée utilisateur pour soit attaquer ou soit se heal
    let options:string = '1.Attack   2.Heal   3.Character\n\n';

    if (encounter === false && match_number < 10)
      options = options + "You encounter a " + enemy.name + "\n\n";
    else if (encounter === false && match_number === 10)
      options = options + "WARNING BOSS APPEARS!!!!!!!\n" + "You encounter a " + enemy.name + "\n\n";
    return new Promise(async (resolve) => {
      if (enemy.current_hp > 0) {
          rl.question(options, async (userInput) => {
              if (userInput === "1") {
                let dmg_mult = compare_class(link.class, enemy.class, link.race, enemy.race);
                let dmg = set_dmg_mult(dmg_mult, link.strength, link.name);
                console.log("\nYou attacked and dealt " + dmg + " damages!");
              if (encounter === false)
                resolve({ enemy: { ...enemy, current_hp: enemy.current_hp - dmg}, link , encounter: true, info});
              else
                resolve({ enemy: { ...enemy, current_hp: enemy.current_hp - dmg }, link, encounter , info});
            } else if (userInput === "2") {
              console.log("You used Heal!");
              if (encounter === false)
                  resolve({ enemy, link: { ...link, current_hp: (link.current_hp + (link.hp_max / 2) > link.hp_max) ? link.hp_max : link.current_hp += (link.hp_max / 2)}, encounter:true , info});
              else
                resolve({ enemy, link: { ...link, current_hp: (link.current_hp + (link.hp_max / 2) > link.hp_max) ? link.hp_max : link.current_hp += (link.hp_max / 2)}, encounter , info});
          } else if (userInput === "3") {
                    console.log(`YOUR CHARACTER:
                    NAME : ` + link.name + `\n-STATS-\n\n
                    MP: ` + link.mp + `\n
                    STR: ` + link.strength + `\n
                    INT: ` + link.int + `\n
                    DEF: ` + link.def + `\n
                    RES: ` + link.res + `\n
                    SPD: ` + link.spd + `\n
                    LUCK: ` + link.luck + `\n
                    RACE: ` + get_race_from_json(link.race) + `\n
                    CLASS: ` + get_class_from_json(link.class) + `\n`);
                    resolve({ enemy, link, encounter, info : true});
              } else {
                  const result = await getInput_basicCharacteristics(enemy, link, encounter, info, match_number);
                  resolve(result);
              }
          });
      } else {
          resolve({ enemy, link, encounter, info});
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
        let dmg_mult = compare_class(action.enemy.class, action.link.class, action.enemy.race, action.enemy.race)
        let dmg = set_dmg_mult(dmg_mult, action.enemy.strength, action.enemy.name)
        action.link.current_hp -= dmg; // la vie actuelle de link = la vie actuelle de link - la force de l'ennemi
        console.log("\n" + action.enemy.name + " attacked and dealt " + dmg + " damages!\n")
    }
    return action;
}

export function check_for_atq_class(class_atq:number, class_def:number) : number {
    let check:number[] = get_weakness_class(class_def)

    if (check) {
        for (let i = 0; i < check.length; i++) {
            if (class_atq === check[i])
                return 1;
        }
    }
    check = get_strength_class(class_def)
    if (check) {
        for (let i = 0; i < check.length; i++) {
            if (class_atq === check[i])
                return -1;
        }
    }
    return 0;
}

export function check_for_atq_race(race_atq:number, race_def:number) : number {
    let check:number[] = get_weakness_race(race_def)

    if (check) {
        for (let i = 0; i < check.length; i++) {
            if (race_atq === check[i])
                return 1;
        }
    }
    check = get_strength_race(race_def)
    if (check) {
        for (let i = 0; i < check.length; i++) {
            if (race_atq === check[i])
                return -1;
        }
    }
    return 0;
}

export function compare_class(atq_class:number, def_class:number, atq_race:number, def_race:number) : number {
    if (check_for_atq_class(atq_class, def_class) === 1 && check_for_atq_race(atq_race, def_race) === 1)
        return 2;
    else if (check_for_atq_class(atq_class, def_class) === -1 && check_for_atq_race(atq_race, def_race) === -1)
        return -2;
    else if ((check_for_atq_class(atq_class, def_class) === 1 && check_for_atq_race(atq_race, def_race) === 0) || (check_for_atq_class(atq_class, def_class) === 0 && check_for_atq_race(atq_race, def_race) === 1))
        return 1;
    else if ((check_for_atq_class(atq_class, def_class) === -1 && check_for_atq_race(atq_race, def_race) === 0) || (check_for_atq_class(atq_class, def_class) === 0 && check_for_atq_race(atq_race, def_race) === -1))
        return -1;
    else
        return 0;
}

export function set_dmg_mult(mult:number, dmg:number, name:string) : number {
    if (mult === 2) {
        dmg *= 4;
        console.log("\nCrushing hit by " + name + "! Damages x 4");
    }
    if (mult === 1) {
        dmg *= 2;
        console.log("\nCrushing hit by " + name + "! Damages x 2");
    }
    if (mult === -1) {
        dmg = Math.floor(dmg / 2)
        console.log("\nGlancing hit by" + name + "! Damages / 2");
    }
    if (mult === -2) {
        dmg = Math.floor(dmg / 4)
        console.log("\nGlancing hit by" + name + "! Damages / 2");
    }
    return dmg;
}

export async function basic_characteristics()
{
    let link:charactere = getRandomPlayer();
    let match_number = 1;
    let current_ennemy:boolean = false;
    let linkDied: boolean = false;

    for (let i = 0; (match_number <= 11); i++) {
        let encounter:boolean = false;
        let enemy: charactere = {   id:NaN, name: "", hp_max: NaN, current_hp: NaN, mp:NaN,
                                    strength: NaN, int: NaN, def: NaN, res: NaN, spd: NaN,
                                    luck: NaN, race: NaN, class: NaN, rarity: NaN};

        if (match_number < 10)
            enemy = getRandomEnemy();
        else
            enemy = getRandomBoss();
        current_ennemy = true;
        while (current_ennemy === true && !linkDied) {
            let info:boolean = false;
            if (match_number < 11 && link.current_hp > 0) {
                display_game(enemy, link, i);
                let action: actions = await getInput_basicCharacteristics(enemy, link, encounter, info, match_number);
                if (action.info === false)
                    action = enemy_attack(action);
                link = action.link; // actualisation
                enemy = action.enemy;
                encounter = action.encounter;
                info = action.info;
            }else if (link.current_hp <= 0 && !linkDied) {  // si Link meurt je casse ma boucle et j'arrive directement a la fin de mon programme
                console.log(link.name + " died!");
                linkDied = true;
                break;
            }else if (match_number === 11) { // si le boss meurt je casse ma boucle et j'arrive directement a la fin de mon programme
                console.log("\nYou won");
                break;
            }
            if (enemy.current_hp <= 0) {
                current_ennemy = false;
                if (match_number < 10) {
                    display_game(enemy, link, i)
                    console.log("\n" + enemy.name + " died!")
                    await press_any_key();
                }else {
                    display_game(enemy, link, i)
                    console.log("\n" + enemy.name + " died!")
                    break;
                }
            }else
                if (info === false)
                    i++;
        }
        match_number++;
    }
    rl.close();
}