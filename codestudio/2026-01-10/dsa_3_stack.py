# Problem: Valid parentheses
# Solution: Use stack
def is_valid(s):
    stack = []
    mapping = {')': '(', ']': '[', '}': '{'}
    for char in s:
        if char in mapping:
            top = stack.pop() if stack else '#'
            if mapping[char] != top:
                return False
        else:
            stack.append(char)
    return not stack

if __name__ == "__main__":
    s = "()[]{}"
    print(f"Valid: {is_valid(s)}")