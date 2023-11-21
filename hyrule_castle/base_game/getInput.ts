import * as readline from 'readline';
import { actions, charactere } from './interfaces';

export const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

export function getInput(enemy:charactere, link:charactere, id:number) : Promise<actions> { // recuperer l'entrée utilisateur pour soit attaquer ou soit se heal
  let options:string = '1.Attack   2.Heal\n\n';

  if (enemy.encounter === false && id < 9)
    options = options + "You encounter a " + enemy.name + "\n\n";
  else if (enemy.encounter === false && id === 9) {
    options = options + "WARNING BOSS APPEARS!!!!!!!\n" + "You encounter a " + enemy.name + "\n\n";
  }
  return new Promise(async (resolve) => {
    if (enemy.current_hp > 0) {
        rl.question(options, async (userInput) => {
            if (userInput === "1") {
                console.log("You attacked and dealt " + link.strength + " damages!");
                if (enemy.encounter === false)
                  resolve({ enemy: { ...enemy, current_hp: enemy.current_hp - link.strength, encounter:true }, link });
                else
                  resolve({ enemy: { ...enemy, current_hp: enemy.current_hp - link.strength }, link });
            } else if (userInput === "2") {
                if (enemy.encounter === false)
                  resolve({ enemy, link: { ...link, current_hp: (link.current_hp + (link.hp_max / 2) > link.hp_max) ? link.hp_max : link.current_hp += (link.hp_max / 2),  encounter: true} });
                else
                  resolve({ enemy, link: { ...link, current_hp: (link.current_hp + (link.hp_max / 2) > link.hp_max) ? link.hp_max : link.current_hp += (link.hp_max / 2) }, });
            } else {
                const result = await getInput(enemy, link, id);
                resolve(result);
            }
        });
    } else {
        resolve({ enemy, link });
    }
  });
}

export function press_any_key() : Promise<string> {
  return new Promise((resolve) => {
    rl.question('\nPress any key to continue.\n', (userInput) => {
      resolve(userInput);
    });
  });
}
