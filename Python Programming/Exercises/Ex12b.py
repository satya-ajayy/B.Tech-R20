import turtle as t
t.speed('fastest')


def Ex12bI():
    t.pensize(2)
    c = ['red', 'light green', 'blue']
    for i in range(12):
        t.color(c[i % 3])
        t.circle(75)
        t.right(30)
    t.mainloop()


def Ex12bII():
    for i in range(45):
        for _ in range(4):
            t.forward(100)
            t.right(90)
        t.right(8)
    t.mainloop()


if __name__ == '__main__':
    Ex12bI()
    # Ex12bII()
