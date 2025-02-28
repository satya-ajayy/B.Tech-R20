def Ex09a(s1, s2):
    s1len = len(s1)
    s2len = len(s2)
    if abs(s1len - s2len) > 1:
        return False
    elif s1len == s2len:
        count = 0
        for i, j in zip(s1, s2):
            if i != j:
                count += 1
        if count > 1:
            return False
    else:
        count = 0
        for i, j in zip(s1, s2):
            if i != j:
                count += 1
        if count > 0:
            return False
    return True


def Ex09b(lst):
    dups = [i for i in lst if lst.count(i) > 1]
    print('Duplicates are :', *set(dups))


def Ex09c(lst):
    print('Unique Values  :', *set(lst))


if __name__ == '__main__':
    print(Ex09a('ajay', 'Ajay'))
    Ex09b([1, 2, 3, 4, 2, 1, 4, 7])
    Ex09c([1, 2, 3, 4, 2, 1, 4, 7])
