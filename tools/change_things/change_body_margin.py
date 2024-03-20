import os

def change_recursively(path):
    for file_name in os.listdir(path):
        if os.path.isfile(path + '/' + file_name):
            if file_name.endswith('.html'):
                print (file_name)
                html = open(path + '/' + file_name, 'r')
                text = html.read()
                html.close()
                new_text = text.replace('body {\n\tmargin: 12pt;', 'body {\n\tmargin: 2em;')
                new_text = new_text.replace('body {\r\n\tmargin: 12pt;', 'body {\n\tmargin: 2em;')
                new_text = new_text.replace('body {\n    margin: 12pt;', 'body {\n\tmargin: 2em;')
                new_text = new_text.replace('body {\r\n    margin: 12pt;', 'body {\n\tmargin: 2em;')
                new_text = new_text.replace('body{\n\tmargin: 12pt;', 'body {\n\tmargin: 2em;')
                new_text = new_text.replace('body{\r\n\tmargin: 12pt;', 'body {\n\tmargin: 2em;')
                new_text = new_text.replace('body{\n    margin: 12pt;', 'body {\n\tmargin: 2em;')
                new_text = new_text.replace('body{\r\n    margin: 12pt;', 'body {\n\tmargin: 2em;')
                html = open(path + '/' + file_name, 'w')
                html.write(new_text)
                html.close()
        if os.path.isdir(path + '/' + file_name):
            change_recursively(path + '/' + file_name)

change_recursively('../..')
