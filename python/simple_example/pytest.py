"""
num=5
mask = ~0
print(mask)
while (mask & num):
    mask <<= 1
    print(mask)
res=~mask ^ num
print(res)

s=[0,1,2,3,4,5,6,7,8,9]
k=2
n=len(s)
res=[]
for i in range(n//(2*k)):
    res+=s[-n-1+2*k*i+k:-n-1+2*k*i:-1]+s[k+2*k*i:2*k+2*k*i]
print(res)
s[0:2]=[1,2]
print(s)

nums=[-1,0,-1,0,-1,0,-1]
numdict={}
sorts=sorted(nums)
resnum=[]
for num in sorts:
    numdict[num]=numdict[num]+1 if numdict.get(num) else 1
numsinglesorts=list(set(sorts))
pre=numsinglesorts[0]
res=0
for key in numsinglesorts:
    if key==pre+1:
        res=numdict[key]+numdict[pre] if numdict[key]+numdict[pre]>res else res
    pre=key
print(res)
"""
flowerbed = [0,1,0]
n=1
flowerbed=[1,0]+flowerbed+[0,1]
maxv=0
tmp=0
for num in flowerbed:
    if num and tmp:
        maxv+=((tmp-1)//2)
        tmp=0
    else:
        tmp+=1
print(n<=maxv)


import csv
csv_reader = list(csv.reader(open('yi.csv','r')))
for stu in csv_reader:
    print(stu)