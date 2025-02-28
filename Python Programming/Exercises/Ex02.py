def Ex02a():
    from datetime import datetime as dt
    now = dt.now()
    print(now.strftime('%a %m %H:%M:%S IST %Y'))


def Ex02b():
    print('----MENU----\n1) C to F\n2) F to C')
    ch = int(input('Enter Your Choice : '))
    if ch == 1:
        c_temp = int(input('Enter Celsius Temp : '))
        f_temp = (9 / 5) * c_temp + 32
        print(f_temp)
    elif ch == 2:
        f_temp = int(input('Enter Fahrenheit Temp : '))
        c_temp = (5 * f_temp - 160) / 9
        print(c_temp)
    else:
        print('Choose from 1-2')


def Ex02c():
    for prime in range(2, 20):
        if all(prime % i != 0 for i in range(2, prime)):
            print(prime, end=' ')


def Fibonacci(n):
    fib = lambda f: f if f <= 1 else fib(f - 1) + fib(f - 2)
    return [fib(i) for i in range(n)]


if __name__ == '__main__':
    Ex02b()
