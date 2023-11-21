export interface charactere {
    id:number,
    name:string,
    hp_max:number,
    current_hp:number,
    strength:number,
    encounter:boolean
}

export interface actions {
    link:charactere,
    enemy:charactere,
}