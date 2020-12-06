file = open('input.txt')
lines = file.readlines()
yes_sum = 0

answers = [0] * 26
members = 0

for line in lines:
    line = line.rstrip()

    if len(line) == 0:
        for answer in answers:
            if answer == members:
                yes_sum += 1

        answers = [0] * 26
        members = 0
        continue

    members += 1
    for answer in line:
        answers[ord(answer)-97] += 1
        

for answer in answers:
    if answer == members:
        yes_sum += 1

file.close()
print("Yeses: ", yes_sum)