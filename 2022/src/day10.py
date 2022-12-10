import sys

def part1():
    file = [l.rstrip() for l in open(sys.argv[1])]
    cycle, value, strength = 1, 1, 0
    target = 20
    for line in file:
        if cycle == target:
            strength += cycle*value
            target += 40
        if line[0] == 'n':
            cycle += 1
        else:
            cycle += 2
            if (cycle-1) == target:
                strength += (cycle-1)*value
                target += 40
            parts = line.split(" ")
            value += int(parts[1])
    print(strength)
            

def build_CRT():
    crt = []
    for i in range(6):
        crt.append([])
        for _ in range(40):
            crt[i].append('.')
    return crt

def print_CRT(crt):
    for i in range(6):
        s = ""
        for j in range(40):
            s += crt[i][j]
        print(s)

def draw_CRT(crt, value, position, i):
    if value > 0 and abs(position - value) <= 1:
        crt[i][position] = '#'

def part2():
    crt = build_CRT()
    file = [l.rstrip() for l in open(sys.argv[1])]
    i, cycle, value = 0, 0, 1
    for line in file:
        if cycle % 40 == 0 and cycle >= 40:
            i += 1
            cycle = 0 
        if line[0] == 'n':
            draw_CRT(crt,value, cycle, i)
            cycle += 1
        else:
            draw_CRT(crt,value, cycle, i)
            cycle += 1
            if cycle % 40 == 0:
                i += 1
                cycle = 0 
            draw_CRT(crt,value, cycle, i)
            cycle += 1
            parts = line.split(" ")
            value += int(parts[1])

    print_CRT(crt)

if __name__ == "__main__":
    part1()
    part2()