from typing import List

def do_a_barrel_roll(numbers: List[int], k: int) -> List[int]:
    size = len(numbers)
    if size == 0:
        return []
    k = k % size

    return numbers[k:] + numbers[:k]