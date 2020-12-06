file = open('input.txt')
answers = file.readlines()
yes_sum = 0
yeses = []

for line in answers:
    line = line.rstrip()

    if len(line) == 0:
        yes_sum += len(yeses)
        yeses = []
        continue

    for answer in line:
        if answer not in yeses:
            yeses.append(answer)

yes_sum += len(yeses)

file.close()
print("Yeses: ", yes_sum)