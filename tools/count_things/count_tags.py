import os

path = '../../pages/'
tags_count = {}

for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            html = open(path + file_name, 'r')
            text = html.read()
            html.close()
            tags_plus = text.split('<')
            for tag_plus in tags_plus[1:]:
                tag = tag_plus.split(' ')[0].split('>')[0]
                if len(tag) == 0 or tag[0] == '/':
                    continue
                if tag in tags_count:
                    tags_count[tag] += 1
                else:
                    tags_count[tag] = 1

for el in sorted(tags_count.items(), key=lambda a: a[1], reverse = True):
    print(el[1], el[0])


