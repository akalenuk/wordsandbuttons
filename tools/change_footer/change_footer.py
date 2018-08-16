import os

new_footer = """<table class="footer" style="">
    <tr>
    <td class="footer" style="vertical-align: middle; text-align: left;">
        <a href="index.html"><img src="favicon.ico"></a> 
    </td>
    <td class="footer" style="vertical-align: middle; text-align: left;">
        &larr; there's more.
    </td>
    <td class="footer" style="vertical-align: middle; text-align: right;">
        + 
        <a href="https://github.com/akalenuk/wordsandbuttons">Github</a> & 
        <a href="https://twitter.com/wordsandbuttons">Twitter</a> & 
        <a href="https://news.ycombinator.com/from?site=wordsandbuttons.online">Hacker News</a>
    </td>
    </tr>
    </table>"""

path = '../../pages/'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print file_name
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
