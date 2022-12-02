import sys


score = {
        "A X": [4, "Z"],
        "A Y": [8, "X"],
        "A Z": [3, "Y"],
        "B X": [1, "X"],
        "B Y": [5, "Y"],
        "B Z": [9, "Z"],
        "C X": [7, "Y"],
        "C Y": [2, "Z"],
        "C Z": [6, "X"]   
    }

def part1():
    file = [l.rstrip() for l in open(sys.argv[1])]
    counter = 0
    for line in file:
        counter += score[line][0]
    print(counter)

    
def part2():
    file = [l.rstrip() for l in open(sys.argv[1])]
    counter = 0
    for line in file:
        new_line = line.replace(line[2], score[line][1], 1)
        counter += score[new_line][0]
    print(counter)



if __name__ == "__main__":
    part1()
    part2()