from typing import List

def set_et_match(numbers: List[int], n: int) -> bool:
    check = []

    for nb in numbers:
        nb_to_search = n - nb
        if nb_to_search in check:
            return True
        check.append(nb)
    return False