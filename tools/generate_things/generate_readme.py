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
markdown += '\n\nThe pages are now tagged by these tags: '
for kw in sorted(list(all_keywords)):
	markdown += '[#' + kw + '](https://wordsandbuttons.online/' + kw + ') '
markdown += '\n\nThe pages themselves are:\n\n'

for (_, l, t, desc, kwds) in date_link_title_description_keywords[::-1]:
	markdown += '[' + t + '](https://wordsandbuttons.online/' + l + ') ' + desc + '\n'
	for kw in sorted(list(kwds)):
		markdown += '[#' + kw + '](https://wordsandbuttons.online/' + kw + ') '
	markdown += '\n\n'

markdown += """---

All the code is licensed under [The Unlicense](http://unlicense.org/)."""

f = open('../../README.md', 'w')
f.write(markdown)
f.close()
