import { getRandomNumber } from "./getRandomNumber";
import { charactere } from "./interfaces"

export function getRandomPlayer() : charactere {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/players.json', 'utf8');
    const player = JSON.parse(data);

    return player[getRandomNumber(0, player.length - 1)];
}

export function getRandomEnemy() : charactere {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/enemies.json', 'utf8');
    const enemy = JSON.parse(data);

    return enemy[getRandomNumber(0, enemy.length - 1)];
}

export function getRandomBoss() : charactere {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/bosses.json', 'utf8');
    const boss = JSON.parse(data);

    return boss[getRandomNumber(0, boss.length - 1)];
}

export function get_race_from_json(which:number) : string {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/races.json', 'utf8');
    const race = JSON.parse(data);

    return race[which - 1].name;
}

export function get_class_from_json(which:number) : string {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/classes.json', 'utf8');
    const my_class = JSON.parse(data);

    return my_class[which - 1].name;
}

export function get_weakness_class(which:number) : number[] {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/classes.json', 'utf8');
    const my_class = JSON.parse(data);

    return my_class[which - 1].weaknesses;
}

export function get_weakness_race(which:number) : number[] {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/races.json', 'utf8');
    const race = JSON.parse(data);

    return race[which - 1].weaknesses;
}

export function get_strength_race(which:number) : number[] {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/races.json', 'utf8');
    const race = JSON.parse(data);

    return race[which - 1].strength;
}

export function get_strength_class(which:number) : number[] {
    const fs = require('fs');
    const data:string = fs.readFileSync('../json_files/classes.json', 'utf8');
    const my_class = JSON.parse(data);

    return my_class[which - 1].strength;
}