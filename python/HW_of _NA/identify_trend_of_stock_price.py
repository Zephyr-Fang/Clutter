# Created by FangZhenfang in 18--6-21
import csv
import numpy as np

yi_reader = list(csv.reader(open('yi.csv','r')))
wi_reader = list(csv.reader(open('wi.csv','r')))
yi=[]
wi=[]
for stu in yi_reader:
    yi.append(float(stu[0]))
for stu in wi_reader:
    wi.append(float(stu[0]))
xi=[i for i in range(1,60)]
c=[[],[],[],[]]    # first two coefficient of A,last two is b
c0=sum(wi)
for i in range(30):
    c[0].append(0)
    c[1].append(0)
    c[2].append(0)
    c[3].append(0)
    for j in range(30):
        c[0][i] += wi[j] * xi[i + j]    # sum(wi*xi)
        c[1][i] += wi[j] * xi[i + j] * xi[i + j]    # sum(wi*xi^2)
        c[2][i] += wi[j] * yi[i + j]    # sum(wi*yi)
        c[3][i] += wi[j] * xi[i + j] * yi[i + j]    # sum(wi*xi*yi)
a=[[],[]]    # a0,a1
for i in range(30):
    a[1].append((c[3][i]*c0-c[0][i]*c[2][i])/(c0*c[1][i]-c[0][i]*c[0][i]))
    a[0].append(c[2][i]/c0-c[0][i]*a[1][i]/c0)
zi=[]    # vector b in systerm equation
for i in range(30):
    zi.append(a[0][i]+a[1][i]*(30+i))
A=[]    # matrix A in systerm equation
for i in range(30):
    A.append([])
    for j in range(30):
        A[i].append(yi[29+i-j])
# using matrix to caculate the answer
Am=np.mat(A)
bv=np.transpose(np.mat(zi))
x=Am.I*bv
x=np.transpose(np.mat(x)).tolist()
b=[]

for num in x[0]:
    b.append(num)
y_reader = list(csv.reader(open('754yi.csv','r')))
y=[]
for stu in y_reader:
    y.append(float(stu[0]))
z=[]
for i in range(725):
    z.append(0)
    for j in range(30):
        z[i]+=b[j]*y[29+i-j]
print(z)
