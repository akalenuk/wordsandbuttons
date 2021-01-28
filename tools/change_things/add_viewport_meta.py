import os

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html'):
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
			if text.find('<meta name="viewport"') != -1:
				continue
			print (file_name)
			lines = text.split('\n')
			new_lines = []
			for line in lines:
				if line.strip().startswith('<title>'):
					new_lines += ['	<meta name="viewport" content="width=device-width, initial-scale=0.84">']
				new_lines += [line]
			new_text = '\n'.join(new_lines)
			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()
