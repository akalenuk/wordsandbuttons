import os

new_footer = """<table class="footer" style="width: 555pt; padding: 64pt 0pt 32pt 0pt; background-color: transparent; font-family: sans-serif; font-size: 16pt; font-style: normal;">
	<tr>
	<td class="footer" style="vertical-align: middle; text-align: left; width: 64px; padding: 0; margin: 0; border: 0;">
		<a href="index.html"><img src="favicon.svg"></a> 
	</td>
	<td class="footer" style="vertical-align: middle; text-align: left; width: 200pt; padding: 0; margin: 0; border: 0;">
		&nbsp;&larr; there's more.
	</td>
	<td class="footer" style="vertical-align: middle; text-align: right; width: 300pt; padding: 0; margin: 0; border: 0;">
		+
		<a href="https://github.com/akalenuk/wordsandbuttons">Github</a> &
		<a href="https://wordsandbuttons.online/rss"><span style="letter-spacing: 1pt;">RSS</span></a>
	</td>
	</tr>
	</table>"""

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html') and file_name != 'index.html':
			print(file_name)
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
			before_and_with = text.split('<table class="footer"')
			if len(before_and_with) != 2:
				continue
			before = before_and_with[0]
			after = before_and_with[1].split('</table>')[1]
			new_text = before + new_footer + after
			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()

