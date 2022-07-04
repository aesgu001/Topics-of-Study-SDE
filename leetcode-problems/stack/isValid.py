# 20. Valid Parentheses
# https://leetcode.com/problems/valid-parentheses/

# Time complexity:  O(N) to search the entire string
# Space complexity: O(N) to store its characters

def isValid(s):
    myStack = []
    for c in s:
        if c == '(' or c == '[' or c == '{':
            myStack.append(c)
        else:
            if len(myStack) == 0:
                return False
            top = myStack.pop()
            if (top == '(' and c != ')') or (top == '[' and c != ']') or (top == '{' and c != '}'):
                return False
    return len(myStack) == 0

# Test cases
print(isValid("()"))        # True
print(isValid("()[]{}"))    # True
print(isValid("(]"))        # False
