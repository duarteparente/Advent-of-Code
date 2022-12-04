import sys

def part1():
    file = [l.rstrip() for l in open(sys.argv[1])]
    counter = 0
    for line in file:
        pair1, pair2 = line.split(",")
        num11, num12 = pair1.split("-")
        num21, num22 = pair2.split(("-"))
        seq1, seq2 = list(range(int(num11), int(num12)+1, 1)), list(range(int(num21), int(num22)+1, 1))
        if all(i in seq1 for i in seq2) or all(i in seq2 for i in seq1):
            counter += 1
    print(counter)

def part2():
    file = [l.rstrip() for l in open(sys.argv[1])]
    counter = 0
    for line in file:
        pair1, pair2 = line.split(",")
        num11, num12 = pair1.split("-")
        num21, num22 = pair2.split(("-"))
        seq1, seq2 = list(range(int(num11), int(num12)+1, 1)), list(range(int(num21), int(num22)+1, 1))
        if any(i in seq1 for i in seq2) or any(i in seq2 for i in seq1):
            counter += 1
    print(counter)


if __name__ == "__main__":
    part1()
    part2()