import os
import subprocess

PAGES_DIR = "../../pages"

keyword_note = {
'tutorials': '',
'demos': '',
'quizzes': '',
'mathematics': '',
'algorithms': '',
'programming': 'By the way, if you prefer books to blogs, <a href="https://wordsandbuttons.online/SYTYKC.pdf">there is a free book</a> that was originally made from this section.'
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

f = open('links.txt')
links = f.readlines()
f.close()
links_html = '<h2>More interactive learning</h2>'
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

menu = '<p class="links" style="width: 555pt;">'
for (kw, _) in keyword_note.items():
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
index = index.replace('<p>Note</p>', '')
index = index.replace('<div id="timeline"></div>', '\n' + the_index + '\n')
index = index.replace('<div id="links"></div>', '\n' + links_html + '\n')

f = open('../../pages/' + 'index.html', 'w')
f.write(index)
f.close


# tag's all_* pages
for title in list(all_keywords):
	page = '%s' % template
	timeline = ''

	menu = '<p class="links" style="width: 555pt;">'
	for (kw, _) in keyword_note.items():
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
	page = page.replace('<p>Description</p>', '')
	page = page.replace('<div id="menu"></div>', '\n' + menu + '\n')
	page = page.replace('<p>Note</p>', '<p style="width: 555pt;">' + keyword_note[title] + '</p>')
	page = page.replace('<div id="timeline"></div>', '\n' + timeline + '\n')
	page = page.replace('<div id="links"></div>', '')

	f = open('../../pages/all_' + title + '.html', 'w')
	f.write(page)
	f.close
