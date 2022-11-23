from cs50 import get_string
# from str import isalpha

text = get_string("Text: ")
letters = 0
sentences = 0
spaces = 1

for x in text:
    if str.isalpha(x) == True:
        letters += 1
    elif str.isspace(x) == True:
        spaces += 1
    elif x in [".", "!", "?"]:
        sentences += 1

l = letters/spaces * 100
s = sentences/spaces * 100
index = round(0.0588 * l - 0.296 * s - 15.8)

if (index < 1):
    print("Before Grade 1")
elif (index >= 16):
    print("Grade 16+")
else:
    print(f"Grade {index}")