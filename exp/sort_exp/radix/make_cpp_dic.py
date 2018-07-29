body = ''
n = 0
for line in open('en-US.dic'):
	n += 1
	body += ('"' + line.strip() + '", ')
	if n % 16 == 0:
		body += '\n'
		
body = body[:-2]

print 'vector<string> dic = {'
print body
print '};'
print
print 'int dic_length =', n, ';'