import os

path = '../../pages/'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print file_name
            html = open(path + file_name, 'r')
            text = html.read()
            html.close()
            lines = text.split('\n')
            new_lines = []
            for line in lines:
                new_lines += [line]
                if line.strip() == 'p {':
                    new_lines += ['    line-height: 1.42;']
            new_text = '\n'.join(new_lines)
            html = open(path + file_name, 'w')
            html.write(new_text)
            html.close()
