# 13. Roman Integer
# https://leetcode.com/problems/roman-to-integer/

def romanToInt(s):
    out = 0
    prev = 0
    numerals = {
        'I' : 1,
        'V' : 5,
        'X' : 10,
        'L' : 50,
        'C' : 100,
        'D' : 500,
        'M' : 1000
    }

    for symbol in reversed(s):
        # Get numerical value from map
        number = numerals[symbol]
        # Subtract by number if number < prev
        # Else add by number
        if number < prev:
            out -= number
        else:
            out += number
        prev = number

    return out

# Test cases
print(romanToInt("III"))        # 3
print(romanToInt("LVIII"))      # 58
print(romanToInt("MCMXCIV"))    # 1994
