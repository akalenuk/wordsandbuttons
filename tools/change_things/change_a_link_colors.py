import os

old_a1 = """
a{
	text-decoration: none;
}
"""

old_a2 = """
a {
	text-decoration: none;
}
"""

new_a = """
a {
	text-decoration: none;
}

a:link, a:visited {
	color: blue;
}
"""

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html') and file_name != 'index.html' and not file_name.startswith('all_'):
			print(file_name)
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()

			if text.find(old_a1) != -1:
				new_text = text.replace(old_a1, new_a)
			elif text.find(old_a2) != -1:
				new_text = text.replace(old_a2, new_a)

			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()

