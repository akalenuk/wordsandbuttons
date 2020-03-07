file = 'helix.pgm'

numbers = []
for line in open(file).readlines():
    if line != "" and line[0] in "1234567890":
        line_n = line.split(' ')
        for n in line_n:
            numbers += [int(n)]
            
pixels = '['
ss = 1
w = numbers[0]
h = numbers[1]
for i in range(h):
    pixels += '['
    for j in range(w):
        increment = str(numbers[3 + i*w + j]) + ','
        pixels += increment
        ss += len(increment)
        if ss > 84:
            pixels += '\n'
            ss = 0
    pixels += '],'
pixels += ']'

print (pixels)            
    
