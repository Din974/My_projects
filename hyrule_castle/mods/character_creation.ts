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
    else if (encounter === false && match_number === 10) {
      options = options + "WARNING BOSS APPEARS!!!!!!!\n" + "You encounter a " + enemy.name + "\n\n";
    }
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

export function choose_name() : Promise<string> {
    return new Promise(async (resolve) => {
        rl.question(`What is your name ?\n`, async (userInput) => {
            resolve(userInput)
        })
    })
}

export function add_points_of_competences(to_allocate:number) : Promise<number> {
    return new Promise(async (resolve) => {
        rl.question(`You have again ` + to_allocate + ` points to award\nEnter please a number enter 0 and ` + to_allocate + `\n`, async (userInput) => {
            let hp:number = parseInt(userInput);
            if (hp >= 0 && hp <= to_allocate)
                resolve(hp)
            else {
                const result = await add_points_of_competences(to_allocate);
                resolve(result);
            }
        })
    })
}

export function ask_race() : Promise<number> {
    return new Promise(async (resolve) => {
        rl.question(`WHICH RACE DO YOU WANT ?\n
        1.Hylian\n
        2.Sheikah\n
        3.Gerudo\n
        4.Zora\n
        5.Goron\n
        6.Kokiri\n
        7.Twili\n
        8.Minish\n
        9.Humain\n
        10.Reptilian\n
        11.Avian\n
        12.Monster\n
        13.Demon\n
        14.Divine\n
        15.Undead\n
        16.Insect\n
        17.Machine\n`, async (userInput) => {
            let race:number = parseInt(userInput);
            if (race > 0 && race <= 17)
                resolve(race)
            else {
                const result = await ask_race();
                resolve(result);
            }
        })
    })
}

export function ask_class() : Promise<number> {
    return new Promise(async (resolve) => {
        rl.question(`WHICH CLASS DO YOU WANT ?\n
        1.Hero\n
        2.Warrior\n
        3.Mage\n
        4.Dark Mage\n
        5.Assassin\n
        6.Priest\n
        7.Monk\n
        8.Death Knight\n
        9.Necromancer\n`, async (userInput) => {
            let my_class:number = parseInt(userInput);
            if (my_class > 0 && my_class <= 17)
                resolve(my_class)
            else {
                const result = await ask_class();
                resolve(result);
            }
        })
    })
}

export function confirm_choice() : Promise<boolean> {
    return new Promise(async (resolve) => {
        rl.question(`ARE YOU SURE YOU WANT TO PLAY WITH THIS CHARACTER ? [y/n]\n`, async (userInput) => {
            if (userInput.toLowerCase() === "y")
                resolve(true)
            else if (userInput.toLowerCase() === "n")
                resolve(false)
            else {
                const result = await confirm_choice();
                resolve(result);
            }
        })
    })
}

async function create_charactere() : Promise<charactere> {
    let pc:number = 50
    let mp:number = 0;
    let str:number = 0;
    let int:number = 0;
    let def:number = 0;
    let res:number = 0;
    let spd:number = 0;
    let luck:number = 0;
    let name:string = await choose_name();
    console.log(`How many points to award to HP? (You have actually 40 HP)`)
    let hp = await add_points_of_competences(pc);
    pc -= hp;
    hp += 40;
    if (pc > 0) {
        console.log(`How many points to award to MP? (You have actually 30 MP)`)
        mp = await add_points_of_competences(pc);
        pc -= mp;
    }
    if (pc > 0) {
        console.log(`How many points to award to STR? (You have actually 15 STR)`)
        str = await add_points_of_competences(pc);
        pc -= str;
    }
    if (pc > 0) {
        console.log(`How many points to award to INT? (You have actually 10 INT)`)
        int = await add_points_of_competences(pc);
        pc -= int;
    }
    if (pc > 0) {
        console.log(`How many points to award to DEF? (You have actually 5 DEF)`)
        def = await add_points_of_competences(pc);
        pc -= def;
    }
    if (pc > 0) {
        console.log(`How many points to award to RES? (You have actually 5 RES)`)
        res = await add_points_of_competences(pc);
        pc -= res;
    }
    if (pc > 0) {
        console.log(`How many points to award to SPD? (You have actually 10 SPD)`)
        spd = await add_points_of_competences(pc);
        pc -= spd;
    }
    if (pc > 0) {
        console.log(`How many points to award to LUCK? (You have actually 25 LUCK)`)
        luck = await add_points_of_competences(pc);
        pc -= luck;
    }
    mp += 30
    str += 15;
    int += 10;
    def += 5;
    res += 5;
    spd += 10;
    luck += 25;
    let race = await ask_race();
    let my_class = await ask_class();
    let hero = {id:1, name:name, hp_max:hp, current_hp:hp, mp:mp, strength:str,
        int:int, def:def, res:res, spd:spd, luck:luck, race:race, class:my_class,
        rarity:0}
    console.log(hero)
    const confirm = await confirm_choice()
    if (confirm === true)
        return hero;
    else
        return create_charactere();
}


export async function charactere_creation()
{
    let link:charactere = await create_charactere();
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