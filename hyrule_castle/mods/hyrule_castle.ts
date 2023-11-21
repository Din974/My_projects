import { basic_game_customization } from "./basic_game_customization";
import { better_combat_options } from "./better_combat_options";
import { rl } from "./getInput";
import { level_and_experience } from "./level_and_experience";
import { main_moded_game } from "./main_moded_game";
import { basic_characteristics } from "./basic_characteristics";
import { charactere_creation } from "./character_creation";

function choose_mod() : Promise<number> {
    return new Promise(async (resolve) => {
        rl.question(`\nChoose a mod:\n\n
        ================== BASIC GAME ==========================\n
        0.Base_game_but_random_characteres\n
        ================== GAME CUSTOMIZATION ==================\n
        1.Basic_game_customization\n
        ================== COMBAT OPTIONS ======================\n
        2.Better_combat_options\n
        ================== BASIC CHARACTERISTICS ===============\n
        3.Level_and_Experience\n
        4.Basic_characteristics\n
        5.Character_creation\n
        ================== EXIT ================================\n
        6.Exit\n\n`, async (userInput) => {
            if (userInput === "0")
                return resolve(0);
            else if (userInput === "1") {
                return resolve(1);
            }else if (userInput === "2")
                return resolve(2)
            else if (userInput === "3")
                return resolve(3)
            else if (userInput === "4")
                return resolve(4)
            else if (userInput === "5")
                return resolve(5);
            else if (userInput === "6")
                return resolve(6);
            else {
                const result = await choose_mod();
                resolve(result);
            }
        })
    })
}

export async function hyrule_castle() {
    try {
        let choice = await choose_mod();

        console.log();
        if (choice === 0)
            main_moded_game();
        else if (choice === 1)
            basic_game_customization();
        else if (choice === 2)
            better_combat_options();
        else if (choice === 3)
            level_and_experience();
        else if (choice === 4)
            basic_characteristics();
        else if (choice === 5)
            charactere_creation();
        else if (choice === 6)
            rl.close();
    } catch (error) {
        console.error("error")
    }
}

hyrule_castle()