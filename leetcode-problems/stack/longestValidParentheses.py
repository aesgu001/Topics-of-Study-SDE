# 32. Longest Valid Parentheses
# https://leetcode.com/problems/longest-valid-parentheses/

# Time complexity:  O(N) to search the entire string
# Space complexity: O(N) to store scores of valid parentheses substrings

def longestValidParentheses(s):
    myStack = [0]
    max_score = 0

    for c in s:
        if c == '(':
            myStack.append(0)
        # c == ')'
        else:
            # Pop last score from stack;
            # Add last score to top of the stack
            # +2 for finding a valid parenthesis;
            # Get the overall max score
            if len(myStack) > 1:
                score = myStack.pop()
                myStack[-1] += score + 2
                max_score = max(max_score, myStack[-1])
            # Reset stack if no open parenthesis found
            else:
                myStack = [0]

    return max_score

# Test cases
print(longestValidParentheses("(()"))       # 2
print(longestValidParentheses(")()())"))    # 4
print(longestValidParentheses(""))          # 0
print(longestValidParentheses("()(()"))     # 2
print(longestValidParentheses("()(())"))    # 6
