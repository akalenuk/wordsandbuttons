import os
import subprocess

PAGES_DIR = "../../pages"

keyword_description = {
'tutorials': 'Tutorials with clickable, draggable, and discoverable things. As brief as possible while as comprehensive as necessary.',
'demos': 'Clickable explanations of curious things.',
'quizzes': 'Challenge yourself, learn stuff, and have fun.',
'mathematics': 'Interactive explanations of mathematical concepts written with practicing programmers in mind.',
'algorithms': 'Playable essays on algorithms.',
'programming': 'Interactive essays on non-trivial programming ideas and languages.</p><p style="width: 555pt;">By the way, if you prefer books to blogs, <a href="https://wordsandbuttons.online/SYTYKC.pdf">there is a free book</a> that was originally made from this section.'
}

index_title = 'Hello, world!'
index_description = 'This is <i>Words and Buttons Online</i> — a growing collection of&nbsp;interactive tutorials, demos, and quizzes about maths, algorithms, and programming.'

def read_index_spans(path):
	index_spans = []
	for file_name in os.listdir(path):
		if os.path.isfile(path + '/' + file_name):
			if file_name.endswith('.html'):
				html = open(path + '/' + file_name, 'r')
				text = html.read()
				html.close()
				spans = text.split('<span id="index_')
				if spans != []:
					spans = spans[1:]
				Spans = text.split('<Span id="index_')
				if Spans != []:
					Spans = Spans[1:]
				span_ids = ['index_' + s.split('"')[0] for s in spans]
				span_titles = [s.split('>')[1].split('<')[0].lower() for s in spans]
				span_ids += ['index_' + s.split('"')[0] for s in Spans]
				span_titles += [s.split('>')[1].split('<')[0] for s in Spans]
				for i in range(0, len(span_ids)):
					index_spans += [ (file_name, span_ids[i], span_titles[i]) ]
	return index_spans

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

menu = '<p class="links" style="width: 555pt;">'
for (kw, _) in keyword_description.items():
	menu += '<nobr><a style="padding-right: 4pt;" href="all_' + kw + '.html">#' + kw + '</a></nobr> '
menu += '</p>'

# index is now real index not a timeline
the_index = '<h1 title="A real index on index.html! How cool is that!">Index</h1>'
spans = read_index_spans(PAGES_DIR)
cur_letter = ''
for (f, i, t) in sorted(spans, key = lambda fit: fit[2].upper()):
	letter = t[0].upper()
	if cur_letter != letter:
		if cur_letter != '':
			the_index += '</p>\n'
		the_index += '<h2>'+letter+'</h2>\n'
		the_index += '<p class="index_items">\n'
		cur_letter = letter
	the_index += '<nobr><a style="padding-right: 24pt;" href="' + f + '#' + i + '">' + t + '</a></nobr>\n'
the_index += '</p>\n'


index = index.replace('<h1>Title</h1>', '<h1>' + index_title + '</h1>')
index = index.replace('<p>Description</p>', '<p style="width: 555pt;">' + index_description + '</p>')
index = index.replace('<div id="menu"></div>', '\n' + menu + '\n')
index = index.replace('<div id="timeline"></div>', '\n' + the_index + '\n')

f = open('../../pages/' + 'index.html', 'w')
f.write(index)
f.close


for title in list(all_keywords):
	page = '%s' % template
	timeline = ''

	menu = '<p class="links" style="width: 555pt;">'
	for (kw, _) in keyword_description.items():
		if kw == title:
			menu += '<nobr><span style="padding-right: 4pt; color: #999;">#' + kw + '</span></nobr> '
		else:
			menu += '<nobr><a style="padding-right: 4pt;" href="all_' + kw + '.html">#' + kw + '</a></nobr> '
	menu += '</p>'

	for (d, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
		if not title in kwds:
			continue
		timeline += '<p class="title">' + '<a href="' + l + '">' + t + '</a></p>\n'
		timeline += '<p class="description">' + desc + '</p>\n'
		timeline += '<p class="links">'
		for kw in sorted(list(kwds)):
			if kw == title:
				timeline += '<span style="padding-right: 8pt; color: #999;">#' + kw + '</span> '
			else:
				timeline += '<a style="padding-right: 8pt;" href="all_' + kw + '.html">#' + kw + '</a> '
		timeline += '</p>\n'
	page = page.replace('<h1>Title</h1>', '<h1><a href="index.html">Words and Buttons</a>: ' + title + '</h1>')
	page = page.replace('<p>Description</p>', '<p style="width: 555pt;">' + keyword_description[title] + '</p>')
	page = page.replace('<div id="menu"></div>', '\n' + menu + '\n')
	page = page.replace('<div id="timeline"></div>', '\n' + timeline + '\n')

	f = open('../../pages/all_' + title + '.html', 'w')
	f.write(page)
	f.close
