import sys

def part1():
    file = [l.rstrip() for l in open(sys.argv[1])]
    counter = 0
    for line in file:
        comp1, comp2 = line[:len(line)//2], line[len(line)//2:]
        common = list(set(comp1) & set(comp2))
        for i in common:
            if i.islower():
                counter += ord(i) - 96
            elif i.isupper():
                counter += ord(i) - 38
    print(counter)
                

    
def part2():
    file = [l.rstrip() for l in open(sys.argv[1])]
    counter = 0
    for line_index in range(0,len(file),3):
        sack1, sack2, sack3 = file[line_index], file[line_index+1], file[line_index+2]
        common = list(set(sack1) & set(sack2) & set(sack3))
        for i in common:
            if i.islower():
                counter += ord(i) - 96
            elif i.isupper():
                counter += ord(i) - 38
    print(counter)



if __name__ == "__main__":
    part1()
    part2()
