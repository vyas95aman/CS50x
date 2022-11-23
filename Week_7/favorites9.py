import csv
from cs50 import SQL 

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

rows = db.execute("SELECT COUNT(*) as counter FROM favorites WHERE title LIKE ?", title) # plugging in function to the command at ?. Using counter as alias. Returns two rows and one column, counter and number

row = rows[0]

print(row["counter"]) # row is a dict, so we can pull this info