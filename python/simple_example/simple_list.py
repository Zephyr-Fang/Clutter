names=['abs','pc','pom']		#3-1
print(names[0].title())
print(names[1].title())
print(names[2].title())

print(names)

names.insert(1,'pvc')
print(names)

print('abs')		#3-4
names[0]='peft'
print(names)
names.insert(0,'abs')
print(names)
names.insert(1,'pe')
print(names)
names.append('peek')
print(names)
names.pop()
names.pop()
names.pop()
names.pop()
names.pop()
print(names)
del names[1]
print(names)
names.remove('abs')
print(names)


names=['tc4','abs','pom']
print(sorted(names))
print(names)
names.sort()
print(names)
names.reverse()
print(names)
