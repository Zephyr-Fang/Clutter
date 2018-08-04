#coding=gbk 

def display_message():
	print("本章我学习了：python....\n")
display_message()

def favorite_book(title):
	print("One of my favorite books is " + title + ".\n")
favorite_book('Alice in Wonderland')	

def make_shirt(size,print_name):
	print("This T-shirt's size is " + str(size) + " inch, and we need to print this words: " + print_name +'.\n')
make_shirt(23,"Hello_world")
make_shirt(print_name="Cool",size=21)

def make_shirt(size='big',print_name='I love Python!'):
	print("This T-shirt's size is " + size + ", and we need to print this words: " + print_name +'\n')
make_shirt()
make_shirt('middle',)
make_shirt('small',)

def city_country(city, country):
	return(city + ", " + country + '\n')
print(city_country('Santiago','Chile'))

"""
def make_album(singer, song, numbers = ''):
	'''打印歌手名和专辑名'''
	if numbers:
		albums = {														#字典赋值写成albums={}，而不是albums{}
		'singer':singer,
		'song':song,
		'numbers':numbers}
	else:
		albums = {
		'singer':singer,
		'song':song}
	return(albums)
print(make_album('Lincon', 'lalala'))
print(make_album('Lincon', 'lalala', '5'))
while True:                                                             #True 而不是true
	user_singer = input('Please enter the singer: ')
	user_song = input('Please enter the song: ')
	print(make_album(user_singer, user_song))
	q = input('Do you want to quit? Enter Y/N: ')
	if q == 'Y':
		break
"""

"""
#下一个练习
print('\n\n\n')

magicians=['刘谦','大卫']
def show_magicians(magicians):
	'''显示魔术师的名字'''
	print(magicians)
show_magicians(magicians)

#下一个练习
print('\n\n\n')

def make_great(magicians):
	'''将魔术师改为伟大的魔术师'''
	great_magicians = []
	while magicians:
		great_magicians.append('the Great ' + magicians.pop())
	print(great_magicians)
copy_magicians = magicians[:]
make_great(copy_magicians)
print(magicians)
make_great(magicians[:])
"""

