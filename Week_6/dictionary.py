# assume already have speller.py

words = set() # AKA Hash table, set bc no duplicates

def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        word = line.rstrip()
        words.add(word)
    file.close()
    return True

def size():
    return len(words)

def unload():
    return True

# Comparing this code vs C, C was faster (3 seconds) Python took 10 seconds
# Python is easier for programmer, but C was faster to run

