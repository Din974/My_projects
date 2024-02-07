from typing import List

def falafel(s: str) -> bool:
    unpair = ''
    check = False

    for char in s:
        if s.count(char) % 2 != 0 and check == True and char != unpair:
            return False
        if s.count(char) % 2 != 0 and check == False:
            unpair = char
            check = True
    return True

