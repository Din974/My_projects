from typing import List

def daemon(numbers: List[int], k: int) -> bool:
    for i in range(k):
        if numbers[i] >= numbers[k]:
            return False
    for i in range(k, len(numbers)):
        if numbers[i] < numbers[k]:
            return False
    return True