f = open('../../pages/index.html')
index = f.read()
f.close()

hs = index.split('<h2')[1:]
for h in hs:
    h_name = h.split('</h2>')[0].split('>')[1].strip()
    print('\n## ' + h_name)
    lis = h.split('<li>')[1:]
    for li in lis:
        link = li.split('href="')[1].split('"')[0].strip()
        title = li.split('</a>')[0].split('>')[-1].strip()
        comment = li.split('</a>')[1].split('</li>')[0].strip()
        print('- ['+title+'](https://wordsandbuttons.online/'+link+') '+comment)
