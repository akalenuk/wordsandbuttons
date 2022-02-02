import os
import subprocess

PAGES_DIR = "../../pages"

the_title = 'Words and Buttons Online'
the_description = 'This is the source code for [Words and Buttons Online](https://wordsandbuttons.online/) — a growing collection of&nbsp;interactive tutorials, guides, and quizzes about maths, algorithms, and programming.'


date_link_title_description_keywords = []
all_keywords = set()

for filename in os.listdir(PAGES_DIR):
	if filename == 'index.html':
		continue
	if filename == 'faq.html':
		continue
	if filename[:4] == 'all_':
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


# markdown
markdown = '# ' + the_title + '\n'
markdown += the_description
markdown += '\n\n## Tags\n\n'
for kw in sorted(list(all_keywords)):
	markdown += '[#' + kw + '](https://wordsandbuttons.online/all_' + kw + '.html) '
markdown += '\n\n## Pages\n\n'

for (_, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
	markdown += '- [' + t + '](https://wordsandbuttons.online/' + l + ') ' + desc + '\n'
	for kw in sorted(list(kwds)):
		markdown += '<sup>[#' + kw + '](https://wordsandbuttons.online/all_' + kw + '.html)</sup> '
	markdown += '\n\n'

markdown += """---

All the code is licensed under [The Unlicense](http://unlicense.org/)."""

markdown += '\n\n## See also\n\n'
f = open('links.txt')
links = f.readlines()
f.close()
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
		markdown += '- ' +title+'['+url+']('+url+')\n'

f = open('../../README.md', 'w')
f.write(markdown)
f.close()
