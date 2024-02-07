from typing import List

def morning_sunshine(numbers: List[int]) -> List[int]:
    if len(numbers) == 0:
        return []

    new = []
    numbers = list(reversed(numbers))
    max_v = numbers[0]

    new.append(max_v)
    for nb in numbers:
        if nb > max_v:
            new.append(nb)
            max_v = nb
    return list(reversed(new))
