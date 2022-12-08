import sys

def check_visibility(mat,pin,i,j):
    row = mat[i]
    column = []
    for c in range(len(mat)):
        column.append(mat[c][j])
    
    left = all(x < pin for x in row[:j])
    right = all(x < pin for x in row[j + 1:])
    top = all(x < pin for x in column[:i])
    bottom = all(x < pin for x in column[i + 1:])

    return left or right or top or bottom


def check_score(mat,pin,i,j):
    row = mat[i]
    column = []
    for c in range(len(mat)):
        column.append(mat[c][j])

    left, right, top, bottom = 0, 0, 0, 0

    for x in reversed(row[:j]):
        left += 1
        if x >= pin:
            break
    
    for x in row[j + 1:]:
        right += 1
        if x >= pin:
            break
    
    for x in reversed(column[:i]):
        top += 1
        if x >= pin:
            break
    
    for x in column[i + 1:]:
        bottom += 1
        if x >= pin:
            break
    
    return left * right * top * bottom

   
def part1():
    file = [l.rstrip() for l in open(sys.argv[1])]
    mat = []
    counter = 0
    for line in file:
        mat.append(list(line))
    counter = 2*len(mat) + 2*len(mat[0]) - 4
    
    for i in range(1,len(mat)-1):
        for j in range(1, len(mat[i])-1):
            if check_visibility(mat,mat[i][j],i,j):
                counter += 1

    print(counter)


def part2():
    file = [l.rstrip() for l in open(sys.argv[1])]
    mat = []
    max = 0
    for line in file:
        mat.append(list(line))
    
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if check_score(mat,mat[i][j],i,j) > max:
                max = check_score(mat,mat[i][j],i,j)

    print(max)
            

if __name__ == "__main__":
    part1()
    part2()