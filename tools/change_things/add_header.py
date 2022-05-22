import os

header = '<p style="width: 600pt; padding: 36pt 0pt 64pt 0pt;">This is <a href="index.html">Words and Buttons Online</a> — a collection of&nbsp;interactive <a href="all_tutorials.html">#tutorials</a>, <a href="all_demos.html">#demos<a/>, and <a href="all_quizzes.html">#quizzes</a> about <a href="all_mathematics.html">#mathematics</a>, <a href="all_algorithms.html">#algorithms</a> and <a href="all_programming.html">#programming</a>.</p>'

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html') and file_name != 'index.html' and not file_name.startswith('all_'):
			print(file_name)
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()

			byh1 = text.split('<h1>')
			new_text = byh1[0] + header + '\n\t' + '<h1>' + byh1[1]

			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()

