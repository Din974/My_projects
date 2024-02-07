def open_closed(s: str) -> bool:
    stack = []
    opening_chars = {'(', '[', '{'}
    closing_chars = {')', ']', '}'}
    matching_pairs = {('(', ')'), ('[', ']'), ('{', '}')}

    for char in s:
        if char in opening_chars:
            stack.append(char)
        elif char in closing_chars:
            if not stack:  # Si la pile est vide
                return False
            last_opening_char = stack.pop()
            if (last_opening_char, char) not in matching_pairs:
                return False

    # Si la pile n'est pas vide à la fin, cela signifie qu'il y a des ouvertures sans fermetures correspondantes
    return True

# Exemple de test
print(open_closed("[(])"))  # True
