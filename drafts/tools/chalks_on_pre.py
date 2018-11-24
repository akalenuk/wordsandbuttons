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
    r = (word_n % 140);
    g = (word_n / 140 % 130);
    b = (word_n / 140 / 130 % 140);
    return to_ff(r) + to_ff(g) + to_ff(b)

def chunks_of(text):
    not_a_word_material = " @(){}[],.:;\"\'`<>=+-*/\t\n\\?|&#%!0123456789"
    lines = text.split('\n')
    lines = [line.rstrip() + "\n" for line in lines]

    chunks = set()
    word = ""
    for line, n in zip(lines, range(1, len(lines)+1)):
        for c in line:
            if c in not_a_word_material:
                if word != "":
                   chunks.add(word)
                word = ""
            else:
                word += c
    return chunks

# this is a two-step process, first we redo the symbols for not to mix them up them after colorization
def deunhtmlize(text): 
    return text.replace('<', '&<;').replace('>', '&>;')

# then, after the colorization, we turn them into entities
def htmlize(text):
    return text.replace('&<;', '&lt;').replace('&>;', '&gt;')

def colorize(text):
    chunks = chunks_of(text)
    for chunk in chunks:
        replacement = '<span style="color: #' + color_of(chunk) + '">' + chunk + '</span>'
        text_without_chunks = text.split(chunk)
        text = replacement.join(text_without_chunks)
    return text

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
                print (htmlize(colorize(deunhtmlize(pre_text))))
                print ('----')
            
