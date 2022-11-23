# from cs50 import get_string

# people = {
#     "Carter": "523-123-5432",
#     "Aman": "214-235-1314"
# }

# name = get_string("Name: ")
# if name in people:
#     print(f"Number: {people[name]}")

import csv
from cs50 import get_string
# file = open("phonebook.csv", "a") # open in append format, can add to it

# name = get_string("Name: ")
# number = get_string("Number: ")

# writer = csv.writer(file)
# writer.writerow([name, number])

# file.close() # each time this is run, more data is added to csv

with open("phonebook.csv", "a") as file:
    name = get_string("Name: ")
    number = get_string("Number: ")

    writer = csv.writer(file)
    writer.writerow([name, number])


# houses = {
#     "Gryffindor": 0,
#     "Huffelpuff": 0,
#     "Ravenclaw": 0,
#     "Slytherin": 0,
# }

# with open("hogwarts.csv", "r") as file:
#     reader = csv.DictReader(file)
#     # next(reader) # Don't need this with dictreader
#     for row in reader:
#         house = row["House"] # speciy name of data "House" with dictreader
#         houses[house] += 1

# for house in houses:
#     count = houses[house]
#     print(f"{house}: {count}")