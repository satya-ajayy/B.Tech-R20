import math as m
from collections import namedtuple


def Ex08a(b1, b2):
    d = m.dist([b1.x, b1.y], [b2.x, b2.y])
    if d < b1.r + b2.r:
        return True
    return False


def Ex08b(lst):
    l = len(lst)
    mean = sum(lst)/l
    lst.sort()
    meadian = lst[l//2]
    mode = max(set(lst), key=lst.count)
    print('Mean is :', mean)
    print('Meadian is :', meadian)
    print('Mode is :', mode)


if __name__ == '__main__':
    ball = namedtuple('Ball', ['x', 'y', 'r'])
    ball_one = ball(1, 2, 1)
    ball_two = ball(3, 4, 1)
    if Ex08a(ball_one, ball_two):
        print('Balls Are Colliding')
    else:
        print('Balls Are Not Colliding')
    # Ex08b([1, 2, 2, 3, 4, 5, 2, 1, 5, 8])
