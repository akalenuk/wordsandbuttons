import os

path = '../../pages/'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print (file_name)
            html = open(path + file_name, 'r')
            text = html.read()
            html.close()
            before1 = '<a href="https://wordsandbuttons.online/SYTYKC.pdf">Free book</a>'
            after1 = '<a href="https://wordsandbuttons.online/SYTYKC.pdf">So You Think You Know C</a> <span style="color:#888; font-size: 12pt;">(free book)</span>'
            before2 = '<a href="https://www.manning.com/books/geometry-for-programmers">Paid book</a>'
            after2 = '<a href="https://www.amazon.com/Geometry-Programmers-Oleksandr-Kaleniuk/dp/1633439607">Geometry for Programmers</a> <span style="color:#888; font-size: 12pt;">(paid book)</span>'
            new_text = text.replace(before1, after1).replace(before2, after2)
            html = open(path + file_name, 'w')
            html.write(new_text)
            html.close()
