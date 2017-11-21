import sys


if len(sys.argv) != 2:
    print("Usage: tooltipize_asm.py some_asm.s [> some_asm.html]")
    sys.exit(1)

i_and_m = []
for line in open('instructions.txt'):
    i = line.split(' ')[0]
    m = ' '.join(line.split(' ')[1:]).strip()
    i_and_m += [(i, m)]

for line in open(sys.argv[1]):
    first = True
    res = []
    for chunk in line.rstrip().split(' '):
        if first and chunk != '':
            first = False
            for i,m in i_and_m:
                if (i[-1] == '*' and chunk.upper().startswith(i[:-1])) or chunk.upper() == i:
                    chunk = '<a title="' + m + '">' + chunk + '</a>'
        res += [chunk]
    print(' '.join(res))

