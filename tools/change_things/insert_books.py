import os

last_good = '<td class="footer" style="vertical-align: middle; text-align: right; width: 300pt; padding: 0; margin: 0; border: 0;">'
first_good = '<a href="https://github.com/akalenuk/wordsandbuttons">Github</a>'

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html') and file_name != 'index.html' and not file_name.startswith('all_'):
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
            
			if text.find(last_good) == -1 or text.find(first_good) == -1:
				continue
			print(file_name)

			first_part = text.split(last_good)[0] + last_good
			last_part = first_good + text.split(first_good)[1]

			new_text = first_part + """
			<nobr>+
		<a href="https://wordsandbuttons.online/SYTYKC.pdf">Free book</a></nobr><br>
			<nobr>+
		<a href="https://www.manning.com/books/geometry-for-programmers">Paid book</a></nobr><br>
			+
		""" + last_part;

			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()

