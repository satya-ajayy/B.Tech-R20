import requests


def Ex11a():
    print('To Install requests, flask')
    print('Open Your Terminal')
    print('Type pip install requests and hit enter')
    print('Type pip install flask and hit enter')


def Ex11b():
    url = 'https://en.wikipedia.org/wiki/Docker_(software)'
    content = requests.get(url).content
    print(content)


if __name__ == '__main__':
    Ex11a()
    # Ex11b()
