import os


path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html') and file_name != 'index.html':
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
			
			if text.find('<meta name="keywords"') == -1:
				continue
			tags = text.split('<meta name="keywords"')[1].split('"')[1].split(', ')
			print(file_name, tags)
			tag_line = ' '.join(['<a href="all_'+tag+'.html">#'+tag+'</a>' for tag in tags])
			text = text.replace('<a href="index.html"><img src="favicon.svg"></a>', tag_line)
			
			html = open(path + file_name, 'w')
			html.write(text)
			html.close()
			break

