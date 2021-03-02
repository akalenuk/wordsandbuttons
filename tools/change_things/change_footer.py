import os

for_index = '<td class="footer" style="vertical-align: middle; text-align: left; width: 64px; padding: 0; margin: 0; border: 0;">'
for_twitter = '<a href="https://github.com/akalenuk/wordsandbuttons">Github</a> &'

with_index = '<td class="footer" style="vertical-align: middle; text-align: left; width: 64px; padding: 0; margin: 0; border: 0;">\n\
		<a href="index.html">Index</a>'

with_twitter = '<a href="https://github.com/akalenuk/wordsandbuttons">Github</a> &\n\
		<a href="https://twitter.com/wordsandbuttons">Twitter</a> &'

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html') and file_name != 'index.html':
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()

			if text.find(for_index) == -1 or text.find(for_twitter) == -1:
				continue
			print(file_name)

			new_text = text.replace(for_index, with_index).replace(for_twitter, with_twitter)

			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()

