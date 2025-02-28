from tkinter import *


def Buttons(val):
    global equation_text
    if val == '=':
        equation_label.set(answer := str(eval(equation_text)))
        equation_text = answer
    elif val == 'C':
        equation_label.set('')
        equation_text = ''
    elif val == 'D':
        equation_label.set(equation_text[:-1])
        equation_text = equation_text[:-1]
    else:
        equation_text = equation_text + val
        equation_label.set(equation_text)


root = Tk()
root.title('CALCULATOR')

equation_text = ''
equation_label = StringVar()

label = Label(textvariable=equation_label, width='20', font=('consolas', 20))
label.pack()

frame1 = Frame(root)
frame1.pack()

buttons = [['1', '2', '3', '4', '+'], ['5', '6', '7', '8', '-'],
           ['9', '0', '(', ')', '*'], ['.', 'D', 'C', '=', '/']]
b = [[0 for _ in range(5)] for _ in range(4)]
for row, lst in enumerate(buttons):
    for col, value in enumerate(lst):
        b[row][col] = Button(frame1, text=value, height=2, width=7, font=35)
        b[row][col].configure(command=lambda val=value: Buttons(val))
        b[row][col].grid(row=row, column=col)
root.mainloop()
