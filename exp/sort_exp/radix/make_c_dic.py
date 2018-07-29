print 'char* dic[] = {'
n = 0
for line in open('en-US.dic'):
	n += 1
	print '"' + line.strip() + '",',
	if n % 16 == 0:
		print

print '""};'
print
print 'int dic_length =', n+1, ';'