import { press_any_key, rl } from "./getInput";
import { getRandomPlayer, getRandomEnemy, getRandomBoss } from "./get_values_from_json";
import { charactere } from "./interfaces";

export interface actions {
    link:charactere,
    enemy:charactere,
    encounter:boolean
}

export function getInputGameCustomization(enemy:charactere, link:charactere, encounter:boolean, combatCount:number) : Promise<actions> { // recuperer l'entrée utilisateur pour soit attaquer ou soit se heal
  let options:string = '1.Attack   2.Heal\n\n';

  if (encounter === false && combatCount % 10 !== 0)
    options = options + "You encounter a " + enemy.name + "\n\n";
  else if (encounter === false && combatCount % 10 === 0) {
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
                const result = await getInputGameCustomization(enemy, link, encounter, combatCount);
                resolve(result);
            }
        });
    } else {
        resolve({ enemy, link, encounter});
    }
  });
}

function launch_or_quit() : Promise<boolean> {
    return new Promise(async (resolve) => {
        rl.question("=======================   THE HYRULE CASTLE   =======================\n\n1.NEW GAME    2.QUIT\n\n", async (userInput) => {
            if (userInput === "1") {
                return resolve(true);
            }else if (userInput === "2") {
                return resolve(false)
            }else {
                const result = await launch_or_quit();
                resolve(result);
            }
        })
    })
}

function choose_difficulty() : Promise<number> {
    return new Promise(async (resolve) => {
        rl.question("\nChoose a difficulty:\n1.NORMAL    2.DIFFICULT    3.INSANE\n\n", async (userInput) => {
            if (userInput === "1") {
                return resolve(1);
            }else if (userInput === "2")
                return resolve(2)
            else if (userInput === "3")
                return resolve(3)
            else {
                const result = await choose_difficulty();
                resolve(result);
            }
        })
    })
}

function choose_numbers_of_fights() : Promise<number> {
    return new Promise(async (resolve) => {
        rl.question("\nHow much fights do you want ?\n1.10    2.20    3.50   4.100\n\n", async (userInput) => {
            if (userInput === "1") {
                return resolve(10);
            }else if (userInput === "2")
                return resolve(20)
            else if (userInput === "3")
                return resolve(50)
            else if (userInput === "4")
                return resolve(100)
            else {
                const result = await choose_numbers_of_fights();
                resolve(result);
            }
        })
    })
}

export function display_game(enemy: charactere, link:charactere, i:number, coins:number) {
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
        console.log("You have actually " + coins + " coins !!!\n")
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

function enemy_states_up(enemy:charactere, difficulty:number, id:number) : charactere {
    if (difficulty === 2) {
        enemy = {id:id , name: enemy.name, hp_max: Math.round(enemy.hp_max * 1.5), current_hp: Math.round(enemy.current_hp * 1.5), mp: Math.round(enemy.mp * 1.5),
        strength: Math.round(enemy.strength * 1.5), int: Math.round(enemy.int * 1.5), def: Math.round(enemy.def * 1.5), res: Math.round(enemy.res * 1.5), spd: Math.round(enemy.spd * 1.5),
        luck: Math.round(enemy.luck * 1.5), race: enemy.race, class: enemy.class, rarity: enemy.rarity}
    }
    if (difficulty === 3) {
        enemy = {id:id , name: enemy.name, hp_max: enemy.hp_max * 2, current_hp: enemy.current_hp * 2, mp: enemy.mp * 2,
        strength: enemy.strength * 2, int: enemy.int * 2, def: enemy.def * 2, res: enemy.res * 2, spd: enemy.spd * 2,
        luck: enemy.luck * 2, race: enemy.race, class: enemy.class, rarity: enemy.rarity}
    }
    return enemy;
}

export async function main_basic_game_customization(difficulty:number, number_of_fights:number)
{
    try {
        let link:charactere = getRandomPlayer();
        let id = 1;
        let current_ennemy:boolean = false;
        let linkDied: boolean = false;
        let combatCount: number = 1;
        let coins:number = 12;

        for (let i = 0; (id <= number_of_fights); i++) {
            let encounter:boolean = false;
            let enemy: charactere = {   id:id, name: "", hp_max: NaN, current_hp: NaN, mp:NaN,
                                        strength: NaN, int: NaN, def: NaN, res: NaN, spd: NaN,
                                        luck: NaN, race: NaN, class: NaN, rarity: NaN};

            if (combatCount % 10 === 0) {
                enemy = getRandomBoss();
                enemy.id = id;
            }
            else {
                enemy = getRandomEnemy();
                enemy.id = id
            }
            if (difficulty === 2 || difficulty === 3)
                enemy = enemy_states_up(enemy, difficulty, id);
            current_ennemy = true;
            while (current_ennemy === true && !linkDied) {
                if (id <= number_of_fights && link.current_hp > 0) {
                    display_game(enemy, link, i, coins);
                    let action: actions = await getInputGameCustomization(enemy, link, encounter, combatCount);
                    action = enemy_attack(action);
                    link = action.link; // actualisation
                    enemy = action.enemy;
                    encounter = action.encounter;
                }else if (link.current_hp <= 0 && !linkDied) {  // si Link meurt je casse ma boucle et j'arrive directement a la fin de mon programme
                    console.log(link.name + " died!");
                    console.log("You lose :( Maybe next time")
                    linkDied = true;
                    break;
                }
                if (enemy.current_hp <= 0) {
                    current_ennemy = false;
                    display_game(enemy, link, i, coins + 1)
                    console.log("\n" + enemy.name + " died!")
                    console.log("\nYou found 1 coin !!")
                    coins++;
                    if (id < number_of_fights)
                        await press_any_key();
                    else {
                        console.log("\nYou won !!!!!!!!");
                        break;
                    }
                }else
                    i++;
            }
            combatCount++;
            id++;
        }
        rl.close();
    } catch (error) {
        console.error("error")
    }
}

export async function basic_game_customization() {
    try {
        let launch:boolean = await launch_or_quit();

        if (launch === true) {
            let difficulty:number = await choose_difficulty();
            let number_of_fights:number = await choose_numbers_of_fights();
            console.log();
            main_basic_game_customization(difficulty, number_of_fights)
        }
        else {
            rl.close();
        }
    } catch (error) {
        console.error("error")
    }
}