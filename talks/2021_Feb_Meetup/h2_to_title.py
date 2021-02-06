import os

for n in os.listdir('.'):
	if n[-4:] == 'html' and n[:4] == 'atan':
		print (n)
		f = open(n)
		text = f.read()
		f.close()
		title = text.split('<h2>')[1].split('</h2>')[0]
		title = title.strip()
		text = text.split('<title>')[0] + '<title>' + title + '</title>' + text.split('</title>')[1]
		f = open(n, 'w')
		f.write(text)
		f.close()

