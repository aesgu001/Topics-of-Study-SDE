# 71. Simplify Path
# https://leetcode.com/problems/simplify-path/

# Time complexity:  O(N) to search and simplify entire path
# Space complexity: O(N) to store and return canonical path

def simplifyPath(path):
    myStack = []
    canonPath = ""
    
    # First index of sub path
    i = 0
    # Last index of sub path
    j = 0
    for _ in range(0, len(path)):
        if path[j] == '/':
            if j > i:
                # Remove top sub path 
                if path[i:j] == "..":
                    if len(myStack) > 0:
                        myStack.pop()
                # Add sub path
                elif path[i:j] != ".":
                    myStack.append(path[i:j])
            i = j + 1
        j += 1

    # Handle last sub path
    if j > i:
        if path[i:j] == "..":
            if len(myStack) > 0:
                myStack.pop()
        elif path[i:j] != ".":
            myStack.append(path[i:j])
    
    # Return root directory
    if len(myStack) == 0:
        return "/"

    # Prepend sub path to canon path
    while len(myStack) > 0:
        canonPath = "/" + myStack.pop() + canonPath
    
    # Return simplified path
    return canonPath

# Test cases
print(simplifyPath("/home/"))                   # "/home"
print(simplifyPath("/../"))                     # "/"
print(simplifyPath("/home//foo/"))              # "/home/foo"
print(simplifyPath("/a//b////c/d//././/.."))    # "/a/b/c"
