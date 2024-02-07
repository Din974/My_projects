def remove_nested_quotes(s: str) -> str:
    result = ""
    stack = []

    for char in s:
        if char in {'"', "'"}:
            if stack and stack[-1] == char:
                stack.pop()
            else:
                stack.append(char)
                result += char
        elif not stack:
            result += char

    return result

def yin_yang(s: str) -> bool:
    if s.count("'") % 2 != 0 or s.count('"') % 2 != 0:
        return False
    s = remove_nested_quotes(s)
    stack = []
    check = {'(': ')', '{': '}', '[': ']'}

    for char in s:
        if char in check.keys():
            stack.append(char)
        elif char in check.values():
            if not stack or check[stack.pop()] != char:
                return False
    if len(stack) == 0:
        return True
    return False
