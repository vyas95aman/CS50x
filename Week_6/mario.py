
# while True:
#     n = int(input("Height of column: "))
#     if n > 0:
#         break 


# for i in range(n):
#     print("#")

### Vertical hashes
# def main():
#     height = get_height()
#     for i in range(height):
#         print("#")

# def get_height():
#     while True:
#         try:
#             n = int(input("Height of column: "))
#             if n > 0:
#                 break
#         except ValueError:
#             print("That is not an int!")
#     return n

# main()

# for i in range(4):
#     print("?", end = "") # setting an end, replaces the default \n at the end 
# print() # need new  line

# print("?" * 4) # can also do it this way, not mult, but says do this and concatenate it over

# for i in range(3):
#     for j in range(3):
#         print("#", end = "")
#     print()

for i in range(3):
    print("#" * 3)