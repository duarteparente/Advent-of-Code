import sys

def get_letters(s):
    res = []
    j = 0
    for i in range(1,len(s)-1,4):
        if s[i].isalpha():
            res.append((j,s[i]))
        j += 1
    return res


def fill_stack(cranes, pos):
    for i,j in pos:
        if i >= len(cranes):
            for _ in range((i+1) - len(cranes)):
                cranes.append([])
        cranes[i].insert(0,j)

          
def part1():
    file = [l.rstrip() for l in open(sys.argv[1])]
    cranes = []
    for line in file:
        if "[" in line:
            pos = get_letters(line)
            fill_stack(cranes,pos)
        elif "move" in line:
            moves = line.split(" ")
            for _ in range(int(moves[1])):
                cranes[int(moves[5])-1].append(cranes[int(moves[3])-1].pop())
    res = ""
    for stack in cranes:
        res += str(stack[-1])
    print(res)


def part2():
    file = [l.rstrip() for l in open(sys.argv[1])]
    cranes = []
    for line in file:
        if "[" in line:
            pos = get_letters(line)
            fill_stack(cranes,pos)
        elif "move" in line:
            moves = line.split(" ")
            for i in range(int(moves[1])):
                cranes[int(moves[5])-1].insert(len(cranes[int(moves[5])-1])-i,cranes[int(moves[3])-1].pop())
    res = ""
    for stack in cranes:
        res += str(stack[-1])
    print(res)


if __name__ == "__main__":
    part1()
    part2()

