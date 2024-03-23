import os
import subprocess

PAGES_DIR = "../../pages"

keyword_note = {
'tutorials': '',
'demos': '',
'quizzes': '',
'mathematics': 'Also, I\'m currently writing a book called <a href="https://www.manning.com/books/geometry-for-programmers">Geometry for&nbsp;Programmers</a> for Manning. Not an&nbsp;advertisement, I\'m&nbsp;just bragging.',
'algorithms': '',
'programming': 'By the way, if you prefer books to blogs, <a href="https://wordsandbuttons.online/SYTYKC.pdf">there is a&nbsp;free book</a> that was originally made from this section.'
}

index_title = 'Hello, world!'
index_description = 'This is <i>Words and Buttons Online</i> — a collection of&nbsp;interactive <a href="all_tutorials.html">#tutorials</a>, <a href="all_demos.html">#demos<a/>, and <a href="all_quizzes.html">#quizzes</a> about <a href="all_mathematics.html">#mathematics</a>, <a href="all_algorithms.html">#algorithms</a> and <a href="all_programming.html">#programming</a>.'

keyword_description = {
'tutorials':   'This is <a href="index.html">Words and Buttons Online</a> — a collection of&nbsp;interactive <span style="color: #777;">#tutorials</span>, <a href="all_demos.html">#demos<a/>, and <a href="all_quizzes.html">#quizzes</a> about <a href="all_mathematics.html">#mathematics</a>, <a href="all_algorithms.html">#algorithms</a> and <a href="all_programming.html">#programming</a>.',
'demos':       'This is <a href="index.html">Words and Buttons Online</a> — a collection of&nbsp;interactive <a href="all_tutorials.html">#tutorials</a>, <span style="color: #777;">#demos</span>, and <a href="all_quizzes.html">#quizzes</a> about <a href="all_mathematics.html">#mathematics</a>, <a href="all_algorithms.html">#algorithms</a> and <a href="all_programming.html">#programming</a>.',
'quizzes':     'This is <a href="index.html">Words and Buttons Online</a> — a collection of&nbsp;interactive <a href="all_tutorials.html">#tutorials</a>, <a href="all_demos.html">#demos<a/>, and <span style="color: #777;">#quizzes</span> about <a href="all_mathematics.html">#mathematics</a>, <a href="all_algorithms.html">#algorithms</a> and <a href="all_programming.html">#programming</a>.',
'mathematics': 'This is <a href="index.html">Words and Buttons Online</a> — a collection of&nbsp;interactive <a href="all_tutorials.html">#tutorials</a>, <a href="all_demos.html">#demos<a/>, and <a href="all_quizzes.html">#quizzes</a> about <span style="color: #777;">#mathematics</span>, <a href="all_algorithms.html">#algorithms</a> and <a href="all_programming.html">#programming</a>.',
'algorithms':  'This is <a href="index.html">Words and Buttons Online</a> — a collection of&nbsp;interactive <a href="all_tutorials.html">#tutorials</a>, <a href="all_demos.html">#demos<a/>, and <a href="all_quizzes.html">#quizzes</a> about <a href="all_mathematics.html">#mathematics</a>, <span style="color: #777;">#algorithms</span> and <a href="all_programming.html">#programming</a>.',
'programming': 'This is <a href="index.html">Words and Buttons Online</a> — a collection of&nbsp;interactive <a href="all_tutorials.html">#tutorials</a>, <a href="all_demos.html">#demos<a/>, and <a href="all_quizzes.html">#quizzes</a> about <a href="all_mathematics.html">#mathematics</a>, <a href="all_algorithms.html">#algorithms</a> and <span style="color: #777;">#programming</span>.'
}

all_span_ids = []
def read_index_spans(path):
	global all_span_ids
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
				for span_id in span_ids:
					if span_id in all_span_ids:
						print('Duplicated index span id: ' + span_id + " in " + file_name)
					all_span_ids += [span_id]
	return index_spans

date_link_title_description_keywords = []
all_keywords = set()

for filename in os.listdir(PAGES_DIR):
	if filename == 'index.html':
		continue
	if filename == 'faq.html':
		continue
	if filename.endswith(".html"):
		f = open(PAGES_DIR + "/" + filename, 'rt')
		content = f.read()
		f.close
		if content.find("meta name=\"keywords\"") == -1:
			continue
		date_from_git = subprocess.run(["git", "log", "--reverse", "--date=iso", "--format=%cd", "--", filename], \
		cwd=PAGES_DIR, \
		stdout=subprocess.PIPE)
		full_date = date_from_git.stdout.decode('utf-8')
		date = full_date.split(' ')[0]
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

f = open('links.txt')
links = f.readlines()
f.close()
links_html = '<span id="links"><h1>More interactive learning</h1></span>'
for link in links:
	if link.strip().find(' ') != -1:
		url = link.split(' ')[0]
		title_chunks = link.split(' ')[1:]
		title = title_chunks[0]
		for chunk in title_chunks[1:]: # no hanging short words
			if len(chunk) < 2:
				title += '&nbsp;' + chunk
			else:
				title += ' ' + chunk
		links_html += '<p style="margin-bottom: 12pt;">'+title+'<br><a href="'+url+'">'+url+'</a></p>\n'


# index is now real index not a timeline
the_index = '<span id="index"><h1 title="A real index on index.html! How cool is that!">Index</h1></span>'
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


# here is the timeline too
timeline = '<span id="timeline"><h1>All the pages</h1></span>'
n = 0
total = len(date_link_title_description_keywords)
for (d, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
    timeline += '<p class="title" title="' + d + ' (#' + str(total - n) + ')">' + '<a href="' + l + '">' + t + '</a></p>\n'
    timeline += '<p class="description">' + desc + '</p>\n'
    timeline += '<p class="links">'
    for kw in sorted(list(kwds)):
        timeline += '<a style="padding-right: 8pt;" href="all_' + kw + '.html">#' + kw + '</a> '
    timeline += '</p>\n'
    n += 1


index = index.replace('<h1>Title</h1>', '<h1>' + index_title + '</h1>')
index = index.replace('<p>Description</p>', '<p style="width: 600pt;">' + index_description + '</p>')
index = index.replace('<p>Note</p>', '')
index = index.replace('<div id="index"></div>', '\n' + the_index + '\n')
index = index.replace('<div id="timeline"></div>', '\n' + timeline + '\n')
index = index.replace('<div id="links"></div>', '\n' + links_html + '\n')

f = open('../../pages/' + 'index.html', 'w')
f.write(index)
f.close


# tag's all_* pages
for title in list(all_keywords):
	page = '%s' % template
	timeline = ''

	for (d, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
		if not title in kwds:
			continue
		timeline += '<p class="title">' + '<a href="' + l + '">' + t + '</a></p>\n'
		timeline += '<p class="description">' + desc + '</p>\n'
		timeline += '<p class="links">'
		for kw in sorted(list(kwds)):
			if kw == title:
				timeline += '<span style="padding-right: 8pt; color: #777;">#' + kw + '</span> '
			else:
				timeline += '<a style="padding-right: 8pt;" href="all_' + kw + '.html">#' + kw + '</a> '
		timeline += '</p>\n'
	page = page.replace('<h1>Title</h1>', '<h1>'+title[0].upper()+title[1:]+'</h1>')
	page = page.replace('<p>Description</p>', '<p style="width: 600pt;">'+keyword_description[title])+'</p>'
	page = page.replace('<div id="menu"></div>', '')
	page = page.replace('<p>Note</p>', '<p style="width: 600pt;">' + keyword_note[title] + '</p>')
	page = page.replace('<div id="index"></div>', '')
	page = page.replace('<div id="timeline"></div>', '\n' + timeline + '\n')
	page = page.replace('<div id="links"></div>', '')

	f = open('../../pages/all_' + title + '.html', 'w')
	f.write(page)
	f.close
