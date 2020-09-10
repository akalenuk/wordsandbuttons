import os

path = '../../pages/'

def text_to_id(text):
	allowed = 'qwertyuiopasdfghjklzxcvbnm_'
	return ''.join([c if c in allowed else '_' for c in text.lower()])


for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html'):
			print (file_name)
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
			spans = [s.split('</span>')[0] for s in text.split('<span>')[1:]]
			Spans = [S.split('</Span>')[0] for S in text.split('<Span>')[1:]]
			if len(spans) + len(Spans) == 0:
				continue
			new_text = text
			for span in spans:
				new_text = new_text.replace('<span>' + span, '<span id="index_' + text_to_id(span) + '">' + span)
			for Span in Spans:
				new_text = new_text.replace('<Span>' + Span, '<Span id="index_' + text_to_id(Span) + '">' + Span)
			html = open(path + file_name, 'w')
			html.write(new_text)
			html.close()
