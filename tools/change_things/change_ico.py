import os

path = '../../pages/'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print (file_name)
            html = open(path + file_name, 'r')
            text = html.read()
            html.close()
			new_text = text.replace('favicon.ico', 'favicon.svg')
            html = open(path + file_name, 'w')
            html.write(new_text)
            html.close()
