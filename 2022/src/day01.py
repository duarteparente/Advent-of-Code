
import sys


def part1():
    file = open(sys.argv[1]).readlines()
    counter = 0
    max_counter = 0
    for line in file:
        if line == '\n':
            if counter > max_counter:
                max_counter = counter
            counter = 0
        else:
            counter += int(line)
    print(max_counter)


def part2():
    file = open(sys.argv[1]).readlines()
    res = [0,0,0]
    counter = 0
    for line in file:
        if line == '\n':
            if counter > res[0]:
                res[0] = counter
                res.sort()
            counter = 0
        else:
            counter += int(line)
    print(sum(res))



if __name__ == "__main__":
    part1()
    part2()