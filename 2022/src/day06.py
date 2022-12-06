import sys


def uniqueCharacters(marker, nr):
    s = sorted(marker)
    for i in range(nr-1):
        if (s[i] == s[i+1]):
            return False
    return True


def part12(nr):
    file = [l.rstrip() for l in open(sys.argv[1])]
    line = file[0]
    marker = []
    for i in range(nr):
        marker.append(line[i])
    if uniqueCharacters(marker,nr):
        print(nr)
    else:
        for j in range(nr,len(line)):
            marker.pop(0)
            marker.append(line[j])
            if uniqueCharacters(marker,nr):
                print(j+1)
                break



if __name__ == "__main__":
    part12(4)
    part12(14)