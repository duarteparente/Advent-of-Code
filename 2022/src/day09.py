import sys

moves = {
    'R': (0,1),
    'U': (1,0),
    'L': (0,-1),
    'D': (-1,0),
}

def is_touching(head, tail):
    if head == tail:
        return True
    x = head[0] - tail[0]
    y = head[1] - tail[1]
    if abs(x) <= 1 and abs(y) <= 1:
        return True
    return False


def move(x, y, tail):
    if x == 0:
        if y < 0:
            tail = tuple(map(sum, zip(tail, (0,-1))))
        else:
            tail = tuple(map(sum, zip(tail, (0,1))))
    elif y == 0:
        if x > 0:
            tail = tuple(map(sum, zip(tail, (1,0))))
        else:
            tail = tuple(map(sum, zip(tail, (-1,0))))
    else:
        if x > 0:
            if y > 0:
                tail = tuple(map(sum, zip(tail, (1,1))))
            else:
                tail = tuple(map(sum, zip(tail, (1,-1))))
        elif y > 0:
            tail = tuple(map(sum, zip(tail, (-1,1))))
        else:
            tail = tuple(map(sum, zip(tail, (-1,-1))))
    return tail


def part1():
    file = [l.rstrip() for l in open(sys.argv[1])]
    visited = set()
    head = (0,0)
    tail = (0,0)
    visited.add(tail)
    for line in file:
        parts = line.split(" ")
        for _ in range(int(parts[1])):
            head = tuple(map(sum, zip(head, moves[parts[0]])))
            if not is_touching(head,tail):
                x = head[0] - tail[0]
                y = head[1] - tail[1]
                tail = move(x,y,tail)
                visited.add(tail)
    print(len(visited))


def part2():
    file = [l.rstrip() for l in open(sys.argv[1])]
    visited = set()
    ropes = [(0,0), (0,0), (0,0), (0,0), (0,0), (0,0), (0,0), (0,0), (0,0), (0,0)]
    visited.add(ropes[9])
    for line in file:
        parts = line.split(" ")
        for _ in range(int(parts[1])):
            ropes[0] = tuple(map(sum, zip(ropes[0], moves[parts[0]])))
            for i in range(9):
                if not is_touching(ropes[i],ropes[i+1]):
                    x = ropes[i][0] - ropes[i+1][0]
                    y = ropes[i][1] - ropes[i+1][1]
                    ropes[i+1] = move(x,y,ropes[i+1])
                    if i+1 == 9:
                        visited.add(ropes[i+1])
    print(len(visited))

            

if __name__ == "__main__":
    part1()
    part2()