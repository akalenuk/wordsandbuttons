import os

path = '../../pages/'

def text_to_id(text):
	allowed = 'qwertyuiopasdfghjklzxcvbnm_'
	return ''.join([c if c in allowed else '_' for c in text.lower()])


for file_name in os.listdir(path):
	if os.path.isfile(path + file_name):
		if file_name.endswith('.html'):
			html = open(path + file_name, 'r')
			text = html.read()
			html.close()
			spans = text.split('<span id="index_')
			if spans != []:
				spans = spans[1:]
			Spans = text.split('<Span id="index_')
			if Spans != []:
				Spans = Spans[1:]
			span_ids = ['index_' + s.split('"')[0] for s in spans]
			span_titles = [s.split('>')[1].split('<')[0].lower() for s in spans]
			span_ids += ['index_' + s.split('"')[0] for s in Spans]
			span_titles += [s.split('>')[1].split('<')[0].lower() for s in Spans]
			for i in range(0, len(span_ids)):
				print (file_name, span_ids[i], span_titles[i])
