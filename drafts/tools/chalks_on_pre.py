import os
import random

def color_of(word):
    if ord(word[0]) >= 128:
        return "909090"
    def to_ff(x):
        y = hex( int(x) )[2:]
        if len(y) == 1:
            return "0"+y
        else:
            return y
    random.seed(word)
    word_n = random.random() * 2147483648
    r = (word_n % 128);
    g = (word_n / 128 % 128);
    b = (word_n / 128 / 128 % 128);
    return to_ff(r) + to_ff(g) + to_ff(b)

# this is a two-step process, first we redo the symbols for not to mix them up them after colorization
def deunhtmlize(text): 
    return text.replace('<', '&<;').replace('>', '&>;')

# then, after the colorization, we turn them into entities
def htmlize(text):
    return text.replace('&<;', '&lt;').replace('&>;', '&gt;')

def not_a_word_material():
    return " @(){}[],.:;\"\'`<>=+-*/\t\n\\?|&#%!0123456789"

def colorize_line(line):
    chunk = ''
    new_line = ''
    for c in line + ' ':
        if c in not_a_word_material():
            if chunk != '':
                new_line += '<span style="color: #' + color_of(chunk) + '">' + chunk + '</span>'
                chunk = ''
            new_line += c
        else:
            chunk += c
    return new_line[:-1]

def colorize_outside(quotes, line):
    if quotes == '':
        return colorize_line(line)
    quote = quotes[0]
    bits = line.split(quote)
    new_bits = []
    for bit, i in zip(bits, range(len(bits))):
        if i % 2 == 1:
            new_bits += [bit]
        else:
            new_bits += [colorize_outside(quotes[1:], bit)]
    return quote.join(new_bits)

def colorize_text(text):
    new_lines = []
    for line in text.split('\n'):
        if line.lstrip().startswith('!') or line.lstrip().startswith('//') or line.lstrip().startswith('--') or line.lstrip().startswith('#'):
            new_lines += ['<span style="color: #778877">' + line + '</span>']
        else:
            new_lines += [colorize_outside('\"\'', line)]
    return '\n'.join(new_lines)


path = '../'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print ('++++ ' + file_name)
            html = open(path + file_name, 'r')
            text = html.read()
            html.close()
            if text.find('<pre>') == -1:
                break
            for piece in text.split('<pre>')[1:]:
                pre_text = piece.split('</pre>')[0]
                print ('----')
                print (htmlize(colorize_text(deunhtmlize(pre_text))))
                print ('----')
            
