def Ex03a(n):
    if n in [0, 1]:
        return 1
    return n * Ex03a(n - 1)


def Ex03b(a, b, c):
    l = [a, b, c]
    l.sort()
    if l[-1]**2 == l[0]**2 + l[1]**2:
        print('Right Angled Triangle')
    else:
        print('Not A Right Angled Triangle')


def Ex03c(n):
    from Ex02 import Fibonacci
    print('Fibonacci Series :', *Fibonacci(n))


if __name__ == '__main__':
    Ex03c(16)
