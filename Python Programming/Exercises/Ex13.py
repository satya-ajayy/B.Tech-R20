def isEvenLst(lst):
    if all(even % 2 == 0 for even in lst):
        return True
    return False


def reverseString(string):
    if type(string) is not str:
        raise TypeError('This Function Only Used To Reverse The Strings')
    return string[::-1]
