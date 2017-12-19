import os

for file_name in os.listdir('.'):
    if os.path.isfile(file_name):
        if file_name.endswith('.html'):
            html = open(file_name, 'r')
            lines = html.readlines()
            html.close()
            rstripped = [line.rstrip() + '\n' for line in lines]
            _html = open('_' + file_name, 'w')
            _html.writelines(rstripped)
            _html.close()
