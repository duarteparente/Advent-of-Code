
import sys, random
from collections import defaultdict


def get_answer1(sizes):
    counter = 0
    for i in sizes.values():
        if i <= 100000:
            counter += i
    return counter


def get_answer2(sizes):
    total = 30000000 - (70000000 - sizes["/"])
    pin = sizes["/"]
    for i in sizes.values():
        if i > total and i < pin:
            pin= i
    return pin
                

def part12():
    file = [l.rstrip() for l in open(sys.argv[1])]
    filepath = []
    sizes = defaultdict(int)
    for line in file:
        parts = line.split(" ")
        if parts[1] == "cd":
            if parts[2] == "..":
                filepath.pop()
            else:
                if parts[2] not in sizes:
                    filepath.append(parts[2])
                else:
                    aux = parts[2] + str(random.randint(1, 100000))
                    filepath.append(aux)
              
        elif parts[0] != "$" and parts[0] != "dir":
                for fp in filepath:
                    sizes[fp] += int(parts[0])

    print(get_answer1(sizes))
    print(get_answer2(sizes))


            
if __name__ == "__main__":
    part12()