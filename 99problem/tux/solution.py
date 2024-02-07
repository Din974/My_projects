from typing import List

def tux(numbers: List[int]) -> int:
    if len(numbers) == 0:
        return -1
    if all(num >= numbers[0] for num in numbers[1:]):
        return 0
    for i in range(1, len(numbers)):
        if numbers[i] > numbers[i - 1]:
            if all(num >= numbers[i] for num in numbers[i + 1:]) and all(num < numbers[i] for num in numbers[:i]):
                return i
    return -1