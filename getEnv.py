# import os
# import sys
# import aiohttp
# import signal
# import json
# import asyncio
# from threading import Thread

# loop = asyncio.get_event_loop()
# client = aiohttp.ClientSession(loop=loop)

# async def get_json(client, url):
# 	async with client.get(url) as response:
# 		assert response.status == 200
# 		return await response.read()

# async def get_reddit_top(subreddit, client):
# 	data1 = await get_json(client, 'https://www.reddit.com/r/' + subreddit + '/top.json?sort=top&t=day&limit=5')

# 	j = json.loads(data1.decode('utf-8'))
# 	for i in j['data']['children']:
# 		score = i['data']['score']
# 		title = i['data']['title']
# 		link = i['data']['url']
# 		print(str(score) + ': ' + title + ' (' + link + ')')

# 	print('DONE:', subreddit + '\n')

# list = ['c++', 'python', 'programming']

# # for i in list:
# # t1 = Thread(target=get_reddit_top, args=('python', client, ))
# # t1.deamon() = True
# # t1.start()

# def signal_handler(signal, frame):
# 	loop.stop()
# 	client.close()
# 	sys.exit(0)

# signal.signal(signal.SIGINT, signal_handler)

# asyncio.ensure_future(get_reddit_top('python', client))
# asyncio.ensure_future(get_reddit_top('programming', client))
# asyncio.ensure_future(get_reddit_top('compsci', client))
# loop.run_forever()


# filepath = "./file"

# for content in os.listdir('.'):
# 	if os.path.isfile(content):
# 		print('f- {0}'.format(content))
# 	elif os.path.isdir(content):
# 		print('d- {0}'.format(content))
# 	elif os.path.islink(content):
# 		print('l- {0}'.format(content))
# 	else:
# 		print('--- {0}'.format(content))

# print ('{0}'.format(os.path.isfile(filepath)))
# print("{0}".format(filter(lambda c: os.path.isfile(c), os.listdir('.'))))

# rx = re.compile(r'\.(py|pl)')

# print filter(rx.search, os.listdir('.'))

# list = filter(lambda c: os.path.isfile(c), os.listdir('.'))
# print(list)
# s = "perl pwd.pl"
# l = [m.start() for m in re.finditer('p', s)]
# for i in l:
# 	print(s[int(i)])
# print(l)
import os
import re
import sys

def list_to_str(l):
	s = ''
	for e in l:
		s += e
	return s

def replace(filename, s1, s2):
	l , s, r, o_s = [], '', [], ''
	i = filename.rfind('/')
	o_file = 'replace.' + filename[i + 1:]
	with open(filename, 'r') as f:
		line = f.readline()
		while line != '':
			l.append(line)
			line = f.readline()
	s = list_to_str(l)
	r = [m.start() for m in re.finditer(s1, s)]
	if r:
		for i in r:
			o_s = s.replace(s[int(i)], s2)
	with open(o_file, 'w') as o:
		o.write(o_s)


filepath = os.path.abspath('file')

if __name__ == "__main__":
	replace(filepath, 'r', '😃')
