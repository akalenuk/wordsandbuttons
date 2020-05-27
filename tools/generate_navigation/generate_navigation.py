import os
import subprocess

PAGES_DIR = "../../pages"

keyword_description = {'mathematics': 'Interactive explanations of mathematical concepts mostly witten with the practicing programmers in mind.',
'programming': 'Interactive explanations of non-trivial programming ideas.',
'performance': 'Quizes and demos touching the topic of software performance.',
'languages': 'Interactive essays about programming languages.',
'tutorials': 'Interactive tutorials with discoverables.',
'algorithms': 'Playable demos of different algorithms.',
'show-and-tell': 'Interactive essays on different math and programming curiosities.'}

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
		date_link_title_description_keywords  += [(date, filename, title, description, keywords)]
		all_keywords.update(keywords)

date_link_title_description_keywords.sort()


# index
f = open('index.html')
index = f.read()
f.close()

timeline = ""
for (d, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
	timeline += '<h3>' + '<a href="' + l + '">' + t + '</a><sup><span class="timestamp">' + d + '</span></h3>\n'
	timeline += '<p class="description">' + desc + '</p>\n'
	timeline += '<p class="links">'
	for kw in kwds:
		timeline += '<a href="' + kw + '.html">#' + kw + '</a> '
	timeline += '</p>\n'

index = index.replace('<div id="timeline"></div>', '\n' + timeline + '\n')
f = open('_index.html', 'w')
f.write(index)
f.close
