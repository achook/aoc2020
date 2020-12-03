STEPS = [(1,1), (3,1), (5,1), (7,1), (1,2)]

def is_tree(square):
    return square == '#'

file = open('input.txt')
slope_map = file.readlines()

trees_multi = 1
line_len = len(slope_map[0])

for step in STEPS:
    pos = 0
    trees_hit = 0

    for tree_row in slope_map[step[1]::step[1]]:
        pos = (pos + step[0]) % (line_len - 1)

        if is_tree(tree_row[pos]):
            trees_hit += 1

    trees_multi *= trees_hit

file.close()
print('Trees multiplied:', trees_multi)