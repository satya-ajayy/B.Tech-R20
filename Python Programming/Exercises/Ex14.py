from collections import deque


def Ex14a():
    req = deque()
    exp = deque(input('Enter a Expression : '))
    print('Giv Expression :', ''.join(exp))

    while len(exp) > 0:
        if len(req) == 0:
            req.append(exp.popleft())
        else:
            a = exp.popleft()
            if a.isdigit() and req[-1].isdigit():
                req.append(a)
            elif a in '(' and req[-1].isalnum():
                req.extend(['*', a])
            elif a in ')' and req[-1].isalnum() and exp:
                req.extend([a, '*'])
            elif a.isalnum() and req[-1].isalnum():
                req.extend(['*', a])
            elif a in '()' and req[-1] in '()':
                req.extend(['*', a])
            else:
                req.append(a)
    print('Req Expression :', ''.join(req))


def Ex14b():
    helper = [[1, 'feets-inches', 12],
              [2, 'feets-yards', 0.33333],
              [3, 'feets-miles', 0.000189393939],
              [4, 'feets-millimeters', 304.8],
              [5, 'feets-centimeters', 30.48],
              [6, 'feets-meters', 0.3048],
              [7, 'feets-kilometers', 0.0003048]]
    feet = int(input('Enter a length in feet: '))
    for lst in helper:
        print(f"{lst[0]}) Convert into {lst[1].split('-')[1]}")
    choice = int(input('Enter Your Choice : '))
    temp1 = feet*helper[choice - 1][2]
    temp2 = helper[choice - 1][1].split('-')[1]
    print(f'{feet} feet = {temp1} {temp2}')


if __name__ == '__main__':
    # Ex14a()
    Ex14b()
