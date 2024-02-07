from typing import List

def conv_to_bin(nb: int) -> str:
    binary = ""
    while nb > 0:
        binary = str(nb % 2) + binary
        nb //= 2
    return binary

def roger_rabbit(n: int) -> List[str]:
    res = []

    for i in range(1, n + 1):
        res.append(conv_to_bin(i))
    return res