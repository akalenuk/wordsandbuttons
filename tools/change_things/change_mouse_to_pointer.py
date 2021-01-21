import os

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html'):
			print (file_name)
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
			if text.find("<canvas") == -1:
				continue
			lines = text.split('\n')
			new_lines = []
			for line in lines:
				if line.strip() == '</style>':
					new_lines += ["canvas { touch-action: none; }"]
				line = line.replace(".addEventListener('mousemove')", ".addEventListener('pointermove')")
				line = line.replace(".addEventListener('mousedown')", ".addEventListener('pointerdown')")
				line = line.replace(".addEventListener('mouseup')", ".addEventListener('pointerup')")
				line = line.replace(".addEventListener('mouseleave')", ".addEventListener('pointerleave')")
				new_lines += [line]
			new_text = '\n'.join(new_lines)
			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()
