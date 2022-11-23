import csv
from typing import Optional
from xml.dom.minidom import CharacterData
from xml.dom.pulldom import CHARACTERS

# titles = []

# with open("favorites.csv", "r") as file:
#     reader = csv.reader(file)
#     next(reader) # Says to ignore the first row, start with actual data
#     for row in reader:
#         print(row[1]) # Prints out show names

#     reader = csv.DictReader(file) # Gives a dictionary instead of a list of threads, key values
#     for row in reader:
#         title = row["title"].strip().upper() # strip gets rid of white space to right and left
#         if not title in titles:
#             titles.append(title) # If title not in titles list, append

#     # To get rid of duplicate values: can use a list, 
# for title in titles:
#     print(title)

# titles = set() # Doing it with a set
# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         title = row["title"].strip().upper() 
#         titles.add(title)

# for title in sorted(titles): # Sorted function takes care of sorting 
#     print(title)

# titles = {} # Doing it with a dict
# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         title = row["title"].strip().upper() 
#         if title in titles:
#             titles[title] += 1
#         else:
#             titles[title] = 1

# def get_value(title):
#     return titles[title]

# # for title in sorted(titles, key = get_value, reverse = True): # Sorted function takes care of sorting 
# #     print(title, titles[title])

# for title in sorted(titles, key = lambda title: titles[title], reverse = True): # Can also use a lambda function, basically an anonmyous funtion. Why make function if only using in one place
#     print(title, titles[title])

# counter = 0

# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         title = row["title"].strip().upper()
#         if "OFFICE" in title:
#             counter += 1
# print(f"Number of people who like The Office is {counter}.")

# General expressions
# . any Character
# .* 0 or more characters
# .+ 1 or more CHARACTERS
# ? Optional
# ^ start of input
# $ end of input

# import re
# counter = 0

# with open("favorites.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         title = row["title"].strip().upper()
#         if re.search("^(OFFICE|THE.OFFICE)$", title): # THE.OFFICE to account for Thevoffice
#             counter += 1
# print(f"Number of people who like The Office is {counter}.")

counter = 0

title = input("Title: ").strip().upper()

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        if row["title"].strip().upper() == title:
            counter += 1
print(f"Number of people who like The Office is {counter}.")

# so much code to do something simple, must be an easier way... relational databases!
# sqlite3 favorites.db
# .mode csv
# .import favorites.csv favorites ### importing the csv file into a table and calling it favorites.db
# close out and go back into sqlite3 favorites.db
# .schema shows us the column names, this was automated from our approach
# SELECT title FROM favorites;  ### This shows us all titles ### SELECT columns from table;
# SQL is optimized for CRUD - creating, reading, updating and deleting data
# SELECT title FROM favorites WHERE title = "%Office%";
# SELECT title FROM favorites WHERE title LIKE "%friends%";
# SELECT COUNT(title) FROM favorites WHERE title LIKE "%friends%";
# DELETE FROM favorites WHERE title LIKE "%friends%";       #### Deleted friends entries from database/table
# SELECT COUNT(title) FROM favorites WHERE title LIKE "%friends%";
# SELECT genres FROM favorites WHERE title = "Game of Thrones";
# UPDATE favorites SET genres = "Action, Adventure, Drama, Fantasy, Thriller, War" WHERE title = "Game of Thrones";
