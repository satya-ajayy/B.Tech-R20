class Power2:
    def __init__(self, x, n=2):
        self.x, self.n = x, n

    def Power(self):
        return pow(self.x, self.n)


class Reverse:
    def __init__(self, sentence):
        self.s = sentence

    def rev(self):
        lst = self.s.split(' ')[::-1]
        return ' '.join(lst)


if __name__ == '__main__':
    # print(Power2(5).Power())
    # print(Power2(5, 3).Power())
    statement = 'Ajay Is A Good Boy'
    print(Reverse(statement).rev())
