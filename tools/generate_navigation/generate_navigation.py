import os
import subprocess

PAGES_DIR = "../../pages"

keyword_description = {'mathematics': 'Interactive explanations of mathematical concepts mostly witten with the practicing programmers in mind.',
'programming': 'Interactive explanations of non-trivial programming ideas.',
'performance': 'Quizes and demos touching the topic of software performance.',
'languages': 'Interactive essays about programming languages. By the way, if you prefer books to blogs, <a href="https://wordsandbuttons.online/SYTYKC.pdf">there is a free book</a> that was originally made from this section.',
'tutorials': 'Tutorials with clickable, draggable, and discoverable things. These usually cover broad topics but they still tend to keep as brief as possible while as comprehensive as necessery.',
'algorithms': 'Playable demos of different algorithms.',
'show-and-tell': 'Interactive essays on different math and programming curiosities. Unlike tutorials, these are more focused. Also the topics they cover are generally more obscure. Tutorials are meant to explain well known things to people who do not know them just yet. Show and tell is for showing interesting and unusual things and telling about them.'}

index_title = 'Hello, world!'
index_description = 'This is <i>Words and Buttons Online</i> — a growing collection of&nbsp;interactive tutorials, guides and quizzes about maths, algorithms, and programming.'

date_link_title_description_keywords = []
all_keywords = set()

for filename in os.listdir(PAGES_DIR):
	if filename == 'index.html':
		continue
	if filename == 'faq.html':
		continue
	if filename.endswith(".html"):
		date_from_git = subprocess.run(["git", "log", "--reverse", "--date=iso", "--format=%cd", "--", filename], \
		cwd=PAGES_DIR, \
		stdout=subprocess.PIPE)
		full_date = date_from_git.stdout.decode('utf-8')
		date = full_date.split(' ')[0]
		f = open(PAGES_DIR + "/" + filename, 'rt')
		content = f.read()
		f.close
		title = content.split("<title>")[1].split("</title>")[0]
		description = content.split('<meta name="description" content="')[1].split('">')[0]
		keywords = content.split('<meta name="keywords" content="')[1].split('">')[0].split(', ')
		if keywords[0] == "":
			continue
		date_link_title_description_keywords  += [(date, filename, title, description, keywords)]
		all_keywords.update(keywords)

date_link_title_description_keywords.sort()


# index
f = open('index.template')
template = f.read()
f.close()

index = '%s' % template

menu = '<p class="links">'
for kw in sorted(list(all_keywords)):
	menu += '<nobr><a style="padding-right: 12pt;" href="' + kw + '.html">#' + kw + '</a></nobr> '
menu += '</p>'

timeline = ''
for (d, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
	timeline += '<p class="title">' + '<a href="' + l + '">' + t + '</a><sup><span class="timestamp">' + d.replace('-', '/') + '</span></p>\n'
	timeline += '<p class="description">' + desc + '</p>\n'
	timeline += '<p class="links">'
	for kw in sorted(list(kwds)):
		timeline += '<a style="padding-right: 12pt;" href="' + kw + '.html">#' + kw + '</a> '
	timeline += '</p>\n'

index = index.replace('<h1>Title</h1>', '<h1>' + index_title + '</h1>')
index = index.replace('<p>Description</p>', '<p>' + index_description + '</p>')
index = index.replace('<div id="menu"></div>', '\n' + menu + '\n')
index = index.replace('<div id="timeline"></div>', '\n' + timeline + '\n')

f = open('../../pages/' + 'index.html', 'w')
f.write(index)
f.close

for title in list(all_keywords):
	page = '%s' % template
	timeline = ''
	for (d, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
		if not title in kwds:
			continue
		timeline += '<p class="title">' + '<a href="' + l + '">' + t + '</a><sup><span class="timestamp">' + d.replace('-', '/') + '</span></p>\n'
		timeline += '<p class="description">' + desc + '</p>\n'
		timeline += '<p class="links">'
		for kw in sorted(list(kwds)):
			if kw == title:
				timeline += '<span style="padding-right: 12pt; color: #999;">#' + kw + '</span> '
			else:
				timeline += '<a style="padding-right: 12pt;" href="' + kw + '.html">#' + kw + '</a> '
		timeline += '</p>\n'
	page = page.replace('<h1>Title</h1>', '<h1><a href="index.html">Words and Buttons</a>: ' + title + '</h1>')
	page = page.replace('<p>Description</p>', '<p>' + keyword_description[title] + '</p>')
	page = page.replace('<div id="menu"></div>', '\n' + menu + '\n')
	page = page.replace('<div id="timeline"></div>', '\n' + timeline + '\n')

	f = open('../../pages/' + title + '.html', 'w')
	f.write(page)
	f.close
