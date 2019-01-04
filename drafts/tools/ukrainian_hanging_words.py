# -*- coding: utf-8 -*-
import os

def glued_words(line):
    return line.\
        replace(' і ', ' і&nbsp;').\
        replace(' І ', ' І&nbsp;').\
        replace(' та ', ' та&nbsp;').\
        replace(' Та ', ' Та&nbsp;').\
        replace(' на ', ' на&nbsp;').\
        replace(' На ', ' На&nbsp;').\
        replace(' із ', ' із&nbsp;').\
        replace(' Із ', ' Із&nbsp;').\
        replace(' з ', ' з&nbsp;').\
        replace(' З ', ' З&nbsp;').\
        replace(' у ', ' у&nbsp;').\
        replace(' У ', ' У&nbsp;').\
        replace(' в ', ' в&nbsp;').\
        replace(' В ', ' В&nbsp;').\
        replace(' це ', ' це&nbsp;').\
        replace(' Це ', ' Це&nbsp;').\
        replace(' би ', ' би&nbsp;').\
        replace(' Би ', ' Би&nbsp;').\
        replace(' б ', ' б&nbsp;').\
        replace(' Б ', ' Б&nbsp;').\
        replace(' за ', ' за&nbsp;').\
        replace(' За ', ' За&nbsp;').\
        replace(' не ', ' не&nbsp;').\
        replace(' Не ', ' Не&nbsp;').\
        replace(' як ', ' як&nbsp;').\
        replace(' Як ', ' Як&nbsp;').\
        replace(' ми ', ' ми&nbsp;').\
        replace(' Ми ', ' Ми&nbsp;').\
        replace(' ви ', ' ви&nbsp;').\
        replace(' Ви ', ' Ви&nbsp;').\
        replace(' що ', ' що&nbsp;').\
        replace(' Що ', ' Що&nbsp;').\
        replace(' ж ', ' ж&nbsp;').\
        replace(' Ж ', ' Ж&nbsp;').\
        replace(' є ', ' є&nbsp;').\
        replace(' Є ', ' Є&nbsp;').\
        replace(' до ', ' до&nbsp;').\
        replace(' До ', ' До&nbsp;').\
        rstrip()

path = '../'
for file_name in os.listdir(path):
    if os.path.isfile(path + file_name):
        if file_name.endswith('.html'):
            print file_name
            html = open(path + file_name, 'r')
            lines = html.readlines()
            html.close()
            rstripped = [glued_words(line) + '\n' for line in lines]
            html = open(path + file_name, 'w')
            html.writelines(rstripped)
            html.close()
