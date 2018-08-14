import os

path = '../../pages/'
for file in os.listdir(path):
	if file.endswith('.html'):
		styles = []
		functions = []
		f = open(path + file, 'r')
		text = f.read()
		if text.find('</style>') != -1:
			styles = text.split('</style>')[0].split('<style>')[1]
			styles = [line for line in styles.split('\n') if len(line) > 0]
			styles = [style for style in styles if style[0] == '.']
			styles = [style.split('{')[0].strip()[1:] for style in styles]
			for style in styles:
				if text.find('"'+style+'"') == -1 and text.find("'"+style+"'") == -1:
					print 'style "' + style + '" is not used in ' + file
		if text.find('</script>') != -1:
			functions = text.split('<script language="JavaScript">')[1].split('</script>')[0]
			functions = [fun.split('(')[0].strip() for fun in functions.split('function ')[1:]]
			for fun in functions:
				if text.count(fun) == 1:
					print 'function "' + fun + '" is not used in ' + file

