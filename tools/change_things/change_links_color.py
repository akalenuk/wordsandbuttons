import os

def change_recursively(path):
    for file_name in os.listdir(path):
        if os.path.isfile(path + '/' + file_name):
            if file_name.endswith('.html'):
                print (file_name)
                html = open(path + '/' + file_name, 'r')
                text = html.read()
                html.close()
                new_text = text.replace('a:link, a:visited {\n	color: blue;', 'a:link, a:visited {\n	color: #3d79cf;')
                html = open(path + '/' + file_name, 'w')
                html.write(new_text)
                html.close()
        if os.path.isdir(path + '/' + file_name):
            change_recursively(path + '/' + file_name)

change_recursively('../../pages')
