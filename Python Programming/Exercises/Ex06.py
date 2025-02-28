def Ex06a(st):
    d = {}
    for i in st:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
    print(d)


def Ex06b():
    lst = list('1 2 3 4 5'.split(' '))
    print(lst)
    print('+'.join(lst))
    print(','.join(lst))

    bdays = {'Ajay': {'Birthday': '24-06-2003'},
             'Lavanya': {'Birthday': '07-02-2003'},
             'Paddu': {'Birthday': '18-03-2003'},
             'Gowthami': {'Birthday': '10-12-2002'}}
    template = '{}\'s Birth Date is {}'
    name = input('Enter Name : ').title()
    if name in bdays:
        print(template.format(name, bdays[name]['Birthday']))


if __name__ == '__main__':
    Ex06a('pavan kalyan')
    # Ex06b()
