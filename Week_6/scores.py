from cs50 import get_int

# scores = [72, 73, 33]

scores = []
for i in range(3):
    score = get_int("Score: ")
    # scores.append(score)
    scores += [score] # can also do this

average = sum(scores)/len(scores)
print(f"Average: {average}")