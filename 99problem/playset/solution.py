def playset(s: str) -> bool:
    for i in range(len(s)):
        char = s[i]
        if char in s[:i] + s[i + 1:]:
            return True
    return False