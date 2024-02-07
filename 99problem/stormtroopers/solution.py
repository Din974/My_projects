from typing import List

def stormtroopers(numbers: List[int]) -> List[int]:
    res = list()

    for i in range(len(numbers)):
        if numbers.count(numbers[i]) == 1 and res.count(numbers[i]) == 0:
            res.append(numbers[i])
    return res