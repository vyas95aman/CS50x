from cs50 import get_int

while True:
    n = get_int("Height of column: ")
    if n > 0 and n <= 8:
        break

for row in range(n):
    space_num = n - row

    for j in range(space_num - 1):
        print(" ", end="")

    for k in range(row + 1):
        print("#", end="")

    print("\n", end="")