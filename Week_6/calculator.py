# x = int(input("x: ")) #cast the input as a int, it is string by default
# y = int(input("y: "))
# print(x + y)

from multiprocessing.sharedctypes import Value
from cs50 import get_int

# try:
#     x = int(input("x: "))
# except:
#      print("That is not an int!")
#      exit()
# try:
#     y = int(input("y: "))
# except ValueError:
#     print("That is not an int!")
#     exit()
# print(x+y)

x = get_int("X: ")
y = get_int("Y: ")

z = x / y # // floor division drops decimals
print(f"{z:.50f}")