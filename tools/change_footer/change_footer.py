import os

new_footer = """
    <table class="footer">
    <tr>
    <td class="footer" align="left"><a href="index.html">Home</a></td>
    <td class="footer" align="center"><a href="https://github.com/akalenuk/wordsandbuttons">Github</a></td>
    <td class="footer" align="right"><a href="https://twitter.com/wordsandbuttons">Twitter</a></td>
    </tr>
    </table>
"""

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
