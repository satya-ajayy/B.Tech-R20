def Ex07a(lst1, lst2):
    d = {}
    for key, val in zip(lst1, lst2):
        d[key] = val
    print('Dict :', d)


def Ex07b():
    d = {}
    with open('../Text Files/File1.txt', 'r') as f:
        for line in f:
            for i in line:
                if i in d:
                    d[i] += 1
                else:
                    d[i] = 1
    print(d)


if __name__ == '__main__':
    Ex07a([1, 2, 3], ['Ajay', 'Afia', 'Paddu'])
    Ex07b()
