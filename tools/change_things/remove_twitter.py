import os

twitter = '		<a href="https://twitter.com/wordsandbuttons">Twitter</a> &'

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html') and file_name != 'index.html':
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()

			if text.find(twitter) == -1:
				continue
			print(file_name)

			new_text = text.replace(twitter, '')

			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()

