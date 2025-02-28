def Ex15a():
    with open('../Text Files/File3.txt', 'r') as f:
        lines = [line.strip() for line in f.readlines()]
        s = ';'.join(lines)
    print(s)


def Ex15b():
    converter = lambda c_temp: (9 / 5) * c_temp + 32
    f1 = open('../Text Files/File4.txt', 'r')
    f2 = open('../Text Files/File5.txt', 'w')
    for line in f1.readlines():
        f2.write(str(converter(int(line))) + '\n')
    f1.close()
    f2.close()
    print('Converted SuccessFully')


if __name__ == '__main__':
    Ex15a()
    # Ex15b()
