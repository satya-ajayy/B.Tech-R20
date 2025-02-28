def Ex10a():
    rows, cols = map(int, input('Enter rows and cols :').split())
    matrix = [[0 for _ in range(rows)]for _ in range(cols)]
    for i in range(rows):
        for j in range(cols):
            matrix[i][j] = int(input('Enter Element :'))
    print(matrix)


def Ex10b():
    order = int(input('Enter Order :'))
    matrix1 = [[0 for _ in range(order)] for _ in range(order)]
    matrix2 = [[0 for _ in range(order)] for _ in range(order)]
    matrix3 = [[0 for _ in range(order)] for _ in range(order)]
    for i in range(order):
        for j in range(order):
            matrix1[i][j] = int(input('Enter Element :'))
    print('Matrix A:', matrix1)
    for i in range(order):
        for j in range(order):
            matrix2[i][j] = int(input('Enter Element :'))
    print('Matrix B:', matrix2)
    for i in range(order):
        for j in range(order):
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j]
    print('Matrix A+B:', matrix3)


def Ex10c():
    order = int(input('Enter Order :'))
    matrix1 = [[0 for _ in range(order)] for _ in range(order)]
    matrix2 = [[0 for _ in range(order)] for _ in range(order)]
    matrix3 = [[0 for _ in range(order)] for _ in range(order)]
    for i in range(order):
        for j in range(order):
            matrix1[i][j] = int(input('Enter Element :'))
    print('Matrix A:', matrix1)
    for i in range(order):
        for j in range(order):
            matrix2[i][j] = int(input('Enter Element :'))
    print('Matrix B:', matrix2)
    for i in range(order):
        for j in range(order):
            matrix3[i][j] = 0
            for k in range(order):
                matrix3[i][j] += matrix1[i][k] + matrix2[k][j]
    print('Matrix A*B:', matrix3)


if __name__ == '__main__':
    Ex10c()
