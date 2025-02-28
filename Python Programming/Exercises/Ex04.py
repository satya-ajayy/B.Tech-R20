def Ex04a():
    file1 = input('Enter 1st File Name : ')
    file2 = input('Enter 2nd File Name : ')
    text = input('Enter The Text To File1:')
    f1 = open(f'../Text Files/{file1}', 'w')
    f1.write(text)
    f1.close()
    f1 = open(f'../Text Files/{file1}', 'r')
    f2 = open(f'../Text Files/{file2}', 'w')
    f2.write(f1.read())
    f1.close()
    f2.close()
    print('Text Copied SuccessFully')


def Ex04b():
    file = input('Enter File Name : ')
    s = set()
    with open(f'../Text Files/{file}', 'r') as f:
        for line in f.readlines():
            s.update(set(line.strip().split(' ')))
    l = list(s)
    l.sort()
    print(l)


class IntToRoman:
    def __init__(self):
        self.mapping = [(1000, 'M'), (900, 'CM'), (500, 'D'),
                        (400, 'CD'), (100, 'C'), (90, 'XC'),
                        (50, 'L'), (40, 'XL'), (10, 'X'),
                        (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I')]

    def Convert(self, num):
        roman = []
        for i, numeral in self.mapping:
            while num >= i:
                num -= i
                roman.append(numeral)
        print(''.join(roman))


if __name__ == '__main__':
    Ex04a()
    # Ex04b()
    # IntToRoman().Convert(1995)
