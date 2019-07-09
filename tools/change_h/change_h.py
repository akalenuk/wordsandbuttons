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
            h1 = False
            h2 = False
            for line in lines:
                if line.strip() == 'h1 {':
                    h1 = True
                if line.strip() == 'h2 {':
                    h2 = True
                if line.strip() == '}':
                    h1 = False
                    h2 = False
                if h1 and line.strip() == 'padding-top: 32pt;':
                    new_lines += ['    padding-top: 36pt;']
                elif h2 and line.strip() == 'padding-top: 16pt;':
                    new_lines += ['    padding-top: 20pt;']
                else:
                     new_lines += [line]
            new_text = '\n'.join(new_lines)
            html = open(path + file_name, 'w')
            html.write(new_text)
            html.close()
