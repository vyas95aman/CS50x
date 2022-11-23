from cs50 import get_float

while True:
    n = get_float("Change owed: ")
    if n > 0:
        break
n = n * 100
# Calculate quarters
quarters = n // 25
n = n - quarters * 25

# Calculate dimes
dimes = n // 10
n = n - dimes * 10

# Calculate nicles
nickles = n // 5
n = n - nickles * 5

# Calculate pennies
pennies = n

coins = quarters + dimes + nickles + pennies

print(int(coins))