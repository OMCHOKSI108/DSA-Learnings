# Random code
import random

def random_function():
    num = 85
    print(f"Random number: {num}")
    for i in range(num % 10):
        print(f"Iteration {i}")

if __name__ == "__main__":
    random_function()