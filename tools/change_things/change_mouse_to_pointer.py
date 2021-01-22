import os

path = '../../pages/'
for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html'):
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
			if text.find("<canvas") == -1:
				continue
			print (file_name)
			lines = text.split('\n')
			new_lines = []
			for line in lines:
				if line.strip() == '</style>' and text.find("canvas { touch-action: none; }") == -1:
					new_lines += ["", "canvas { touch-action: none; }"]
				new_line = line
				new_line = new_line.replace(".addEventListener('mousemove'", ".addEventListener('pointermove'")
				new_line = new_line.replace(".addEventListener('mousedown'", ".addEventListener('pointerdown'")
				new_line = new_line.replace(".addEventListener('mouseup'", ".addEventListener('pointerup'")
				new_line = new_line.replace(".addEventListener('mouseleave'", ".addEventListener('pointerleave'")
				new_lines += [new_line]
				if new_line != line:
					print(new_line)
			new_text = '\n'.join(new_lines)
			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()
