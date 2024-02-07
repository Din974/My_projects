def yulaw(s: str) -> str:
    res = ""

    for i in range(len(s)):
        if res.count(s[i]) == 0:
            res += s[i]
    return res