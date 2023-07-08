import os

path = '../../pages/'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print (file_name)
            html = open(path + file_name, 'r')
            text = html.read()
            html.close()

            buttons_plus = text.split('</button>')
            for i in range(len(buttons_plus) - 1):
                chunks = buttons_plus[i].split('>')
                if chunks[-1].find(' ') != -1 and chunks[-1].find('<nobr>') == -1:
                    chunks[-1] = '<nobr>' + chunks[-1] + '</nobr>'
                buttons_plus[i] = '>'.join(chunks)
            new_text = '</button>'.join(buttons_plus)
            
            html = open(path + file_name, 'w')
            html.write(new_text)
            html.close()
