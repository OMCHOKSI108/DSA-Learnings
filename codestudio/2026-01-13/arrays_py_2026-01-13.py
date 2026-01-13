def find_max(arr):
    m = arr[0]
    for x in arr:
        m = max(m, x)
    return m

if __name__ == "__main__":
    arr = [1, 4, 2, 9, 3]
    print("Max:", find_max(arr))