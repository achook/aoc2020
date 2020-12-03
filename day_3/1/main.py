STEPS_RIGHT = 3

def is_tree(square):
    return square == '#'

file = open('input.txt')
slope_map = file.readlines()

pos = 0
trees_hit = 0

for tree_row in slope_map[1:]:
    length = len(tree_row)
    pos = (pos + STEPS_RIGHT) % (length - 1)

    if is_tree(tree_row[pos]):
        trees_hit += 1

file.close()
print('Trees hit:', trees_hit)