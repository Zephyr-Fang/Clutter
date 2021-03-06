# -*- coding: utf-8 -*-
# coding=gbk
import csv
import numpy as np
from scipy.interpolate import interp1d
import matplotlib.pyplot as plt
import matplotlib

# 设置默认中文字体为黑体
matplotlib.rcParams['xtick.direction'] = 'in'
matplotlib.rcParams['ytick.direction'] = 'in'
matplotlib.rcParams['font.sans-serif'] = ['simhei']
matplotlib.rcParams['font.family']='sans-serif'
chinese =matplotlib.font_manager.FontProperties(fname='C:\\Windows\\Fonts\\simfang.ttf')    # 设置仿宋字体，每次使用时调用对象chinese

ripple_data=list(csv.reader(open("RippleDiaphragmSEQV.csv",'r')))
x=[]
half_thick=[]
one_thick=[]
two_thick=[]
three_thick=[]
for row in ripple_data:
    x.append(float(row[0]))
    half_thick.append(float(row[1]))
    one_thick.append(float(row[2]))
    two_thick.append(float(row[3]))
    three_thick.append(float(row[4]))

plt.figure(figsize=(8,5))    # 图的尺寸
# plt.title("波纹膜片等效应力—径向位置关系曲线",fontproperties=chinese,fontsize=18)    # 设置图标题

# 画出厚度为0.05的应力数据，并用三次样条曲线拟合
x0= np.linspace(0, 11, num=1000, endpoint=True)    # 均匀的1000个x轴点
f0 = interp1d(x, half_thick, kind='cubic')    # 三次样条曲线插值函数
plt.scatter(x, half_thick, marker='o', c='r', lw=1, label='0.05mm')    # 真实点散点图
plt.plot(x0, f0(x0), c='r', ls='-', lw=1)    # 导入数据（x,y,颜色，线条样式，标记点，线宽，标记）

# 画出厚度为0.1的应力数据，并用三次样条曲线拟合
f1 = interp1d(x, one_thick, kind='cubic')    # 三次样条曲线插值函数
plt.scatter(x, one_thick, marker='*', c='g', lw=1, label='0.1mm')    # 真实点散点图
plt.plot(x0, f1(x0), c='g', ls='-', lw=1)    # 导入数据（x,y,颜色，线条样式，标记点，线宽，标记）

# 画出厚度为0.2的应力数据，并用三次样条曲线拟合
f2 = interp1d(x, two_thick, kind='cubic')    # 三次样条曲线插值函数
plt.scatter(x, two_thick, marker='x', c='b', lw=1, label='0.2mm')    # 真实点散点图
plt.plot(x0, f2(x0), c='b', ls='-', lw=1)    # 导入数据（x,y,颜色，线条样式，标记点，线宽，标记）

# 画出厚度为0.1的应力数据，并用三次样条曲线拟合
f3 = interp1d(x, three_thick, kind='cubic')    # 三次样条曲线插值函数
plt.scatter(x, three_thick, marker='^', c='k', lw=0.1, label='0.3mm')    # 真实点散点图
plt.plot(x0, f3(x0), c='k', ls='-', lw=1)    # 导入数据（x,y,颜色，线条样式，标记点，线宽，标记）

plt.xlabel("径向位置X (mm)",fontproperties=chinese,fontsize=20)    # 设置横坐标标题
plt.xticks(np.linspace(0,11,12))    # 设定横坐标刻度点
plt.xlim([0,11.2])    # 设定横坐标值的范围
plt.ylabel("等效应力SEQV (MPa)",fontproperties=chinese,fontsize=20)    # 设置纵坐标标题
plt.yticks(np.linspace(0,550,12))
plt.ylim([0,560])

plt.tick_params(axis='both',labelsize=18)    # 横纵坐标刻度的字体大小
plt.legend(loc='lower left', bbox_to_anchor=(0.02,0.03),fontsize=14)    # 设置图例位置
ax = plt.gca()    # gca stands for 'get current axis'
ax.spines['top'].set_visible(False)    # 设置上边框不可见
# ax.spines['top'].set_color('none')    # 设置上边框为无色
ax.spines['right'].set_color('none')    # 设置右边框为无色
plt.show()