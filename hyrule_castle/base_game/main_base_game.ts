import { getInput, press_any_key, rl } from "./getInput";
import { actions, charactere } from "./interfaces";

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

export async function main_base_game()
{
    let link:charactere = {id: 1, name:"Link", hp_max : 60, current_hp : 60, strength : 500, encounter: true};
    let id = 1;
    let current_ennemy:boolean = false;
    let linkDied:boolean = false;

    for (let i = 0; (id <= 10); i++) {
        let enemy: charactere = {id:id, name: "", hp_max: NaN, current_hp: NaN, strength: NaN, encounter: false};

        if (id < 9) // initialiser les stats
            enemy = { id:id, name:"Boboklin", hp_max: 30, current_hp: 30, strength: 5 , encounter: false};
        else
            enemy = { id:id, name: "Ganon", hp_max: 150, current_hp: 150, strength: 20, encounter: false };
        current_ennemy = true;
        while (current_ennemy === true && !linkDied) {
            if (id < 10 && link.current_hp > 0) {
                display_game(enemy, link, i);
                let action: actions = await getInput(enemy, link, id);
                action = enemy_attack(action);
                link = action.link; // actualisation
                enemy = action.enemy;
            }else if (link.current_hp <= 0 && !linkDied) {  // si Link meurt je casse ma boucle et j'arrive directement a la fin de mon programme
                console.log(link.name + " died!\nYou lose :( Maybe next time!");
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