import os

path = '../../pages/'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print (file_name)
            html = open(path + file_name, 'r')
            lines = html.readlines()
            html.close()
            rstripped = [line.rstrip() + '\n' for line in lines]
            html = open(path + file_name, 'w')
            html.writelines(rstripped)
            html.close()
