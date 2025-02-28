def Ex01a():
    a, b, c, d, e = 10, 0b111, 0x12, 0o45, 123_456_789
    print(a, b, c, d, e)
    for i in [a, b, c, d, e]:
        print(type(i), end=' ')
    print()

    a, b, c, d = 4.566, 10.56e5, 1e5, 123_42.222_013
    print(a, b, c, d)
    for i in [a, b, c, d]:
        print(type(i), end=' ')
    print()

    a, b, c, d = 5 + 4J, 5-4J, 4J, 6.45J
    print(a, b, c, d)
    for i in [a, b, c, d]:
        print(type(i), end=' ')
    print()


def Ex01b():
    a, b = 10, 6
    print(a+b, a-b, a*b, a/b, a//b)
    a, b = 10.3456, 3.235
    print(a+b, a-b, a*b, a/b, a//b)
    a, b = 10+5J, 6J
    print(a+b, a-b, a*b, a/b)


def Ex01c():
    string1 = 'abcdefghijklm'
    string2 = 'nopqrstuvxyz'
    alpha = string1 + string2
    print('String 1 is', string1)
    print('String 2 is ', string2)
    print(alpha)
    print('First 5 Alphabets :', string1[:5])


if __name__ == '__main__':
    Ex01c()
