import os
import sys
import datetime
import uuid

if len(sys.argv) < 2:
	print('You should supply a path to the new page as an argument')
	exit(1)

path = sys.argv[1]

# from file
f = open(path, 'rt')
content = f.read()
f.close
title = content.split("<title>")[1].split("</title>")[0]
description = content.split('<meta name="description" content="')[1].split('">')[0]
keywords = content.split('<meta name="keywords" content="')[1].split('">')[0].split(', ')

# date
today = datetime.datetime.utcnow()
timestamp = today.strftime("%a, %d %b %Y %H:%M:%S +0000")

# rss
f = open('../../pages/rss', 'r')
rss = f.read()
f.close()

lbd = rss.split('<lastBuildDate>')[1].split('</lastBuildDate>')[0]
rss = rss.replace('<lastBuildDate>' + lbd + '</lastBuildDate>', '<lastBuildDate>' + timestamp + '</lastBuildDate>')

item = ' <item>\n'
item += '  <title>' + title + '</title>\n'
item += '  <description>' + description + '</description>\n'
item += '  <link>https://wordsandbuttons.online/' + path.split('/')[-1] + '</link>\n'
item += '  <guid isPermaLink="false">' + str(uuid.uuid4()) + '</guid>\n'
item += '  <pubDate>' + timestamp + '</pubDate>\n'
item += ' </item>\n\n'

rss = rss.replace('</channel>', item + '</channel>')

f = open('../../pages/rss', 'w')
f.write(rss)
f.close()

f = open('../../pages/rss.rss', 'w')
f.write(rss)
f.close()
