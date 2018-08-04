# -*- coding: utf-8 -*-
# coding=gbk
"""
Created on Fri Feb  2 23:50:01 2018

@author: FZF-PC
"""

# 3import numpy as np
import matplotlib.pyplot as plt
import matplotlib
matplotlib.rcParams['xtick.direction'] = 'in'
matplotlib.rcParams['ytick.direction'] = 'in'
matplotlib.rcParams['font.sans-serif'] = ['simhei']
matplotlib.rcParams['font.family']='sans-serif'

#MEF, northen Juan de Fuca Ridge热液区的计算结果
pressure=[1,2.5,5,7.5,10,12.5,15,17.5,20,22]
H2S=[95.1846,98.0296,99.0023,99.3318,99.4977,99.5975,99.6643,99.712,99.7479,99.7708]    #溶解的H2S占比
H2=[71.9086,96.0298,99.0905,99.6082,99.7831,99.8625,99.9051,99.9306,99.9471,99.9563]    #溶解的H2占比
CH4=[81.3084,97.6249,99.4628,99.7691,99.8722,99.919,99.9441,99.9592,99.9688,99.9743]    #溶解的CH4占比
CO2=[99.053,99.899,99.978,99.99,99.995,99.997,99.998,99.998,99.999,99.999]    #溶解的CO2占比
plt.figure(figsize=(8,5))
plt.plot(pressure, H2S, c='r', ls='--',marker='o', lw=2, label='H2S')
plt.plot(pressure, H2, c='g', ls='--',marker='*', lw=2, label='H2')
plt.plot(pressure, CH4, c='b', ls='--',marker='x', lw=2, label='CH4')
plt.plot(pressure, CO2, c='k', ls='--',marker='^', lw=2, label='CO2')
#plt.title("MEF, northen Juan de Fuca Ridge",fontsize=18)
plt.xlabel("热液压力 (MPa)",fontsize=14)
plt.ylabel("溶解于热液中的气体占比 (%)",fontsize=14)
plt.xlim([0.5,22.5])
plt.ylim([70,101])
plt.tick_params(axis='both',labelsize=14)
plt.legend(loc='lower right', bbox_to_anchor=(0.97,0.06),fontsize=12)
bbox_to_anchor=(-2,-2)    #设置图例的位置
plt.show()

#Rainbow, MAR热液区的计算结果
pressure=[1,1.5,2,2.5,3,4]
H2S=[98.4568,99.2064,99.5743,99.7923,99.918,99.939]    #溶解的H2S占比
H2=[31.8048,49.2093,66.8958,84.7845,99.8142,99.989]    #溶解的H2占比
CH4=[44.2132,62.2134,77.4469,90.4481,99.8906,99.993]    #溶解的CH4占比
CO2=[95.0128,97.5356,98.8031,99.5626,99.9954,99.999]    #溶解的CO2占比
plt.figure(figsize=(8,5))
plt.plot(pressure, H2S, c='r', ls='--',marker='o', lw=2, label='H2S')
plt.plot(pressure, H2, c='g', ls='--',marker='*', lw=2, label='H2')
plt.plot(pressure, CH4, c='b', ls='--',marker='x', lw=2, label='CH4')
plt.plot(pressure, CO2, c='k', ls='--',marker='^', lw=2, label='CO2')
#plt.title("MEF, northen Juan de Fuca Ridge",fontsize=18)
plt.xlabel("热液压力 (MPa)",fontsize=14)
plt.ylabel("溶解于热液中的气体占比 (%)",fontsize=14)
plt.xlim([0.9,4.1])
plt.ylim([30,103])
plt.tick_params(axis='both',labelsize=14)
plt.legend(loc='lower right', bbox_to_anchor=(0.96,0.05),fontsize=12)
bbox_to_anchor=(-2,-2)
plt.show()

#Logatchev, MAR热液区的计算结果
pressure=[1,1.5,2,2.5,3,4,5,6]
H2S=[97.8546,98.7927,99.2606,99.5402,99.7257,99.8732,99.899,99.9157]    #溶解的H2S占比
H2=[26.7384,41.0705,55.6438,70.404,85.2856,99.9008,99.973,99.9863]    #溶解的H2占比
CH4=[38.2798,54.2197,68.0694,80.1685,90.783,99.9416,99.984,99.9919]    #溶解的CH4占比
CO2=[93.7142,96.6067,98.0859,98.9814,99.5794,99.9976,99.999,99.9994]    #溶解的CO2占比
plt.figure(figsize=(8,5))
plt.plot(pressure, H2S, c='r', ls='--',marker='o', lw=2, label='H2S')
plt.plot(pressure, H2, c='g', ls='--',marker='*', lw=2, label='H2')
plt.plot(pressure, CH4, c='b', ls='--',marker='x', lw=2, label='CH4')
plt.plot(pressure, CO2, c='k', ls='--',marker='^', lw=2, label='CO2')
plt.xlabel("热液压力 (MPa)",fontsize=14)
plt.ylabel("溶解于热液中的气体占比 (%)",fontsize=14)
plt.xlim([0.9,6.1])
plt.ylim([20,103])
plt.tick_params(axis='both',labelsize=14)
plt.legend(loc='lower right', bbox_to_anchor=(0.96,0.05),fontsize=12)
bbox_to_anchor=(-2,-2)
plt.show()

#钛箔袋实验图
capacity=[150,150,30,30,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,150,15,15,
          150,140]
time=[0,3,3.5,6.5,
      7,10,10.5,13.5,
      14,17,17.5,20.5,
      21,24,24.5,27.5,
      28,31,31.5,34.5,
      35,38,38.5,41.5,
      42,45,45.5,48.5,
      49,52,52.5,55.5,
      56,59,59.5,62.5,
      63,66,66.5,69.5,
      70,73,73.5,76.5,
      77,78]
plt.figure(figsize=(12,5))
plt.plot(time,capacity,c='b',ls='-',marker='*',lw=2)
plt.xlabel("时间 (mins)",fontsize=14)
plt.ylabel("钛箔袋容积 (ml)",fontsize=14)
plt.xlim([0,78])
plt.ylim([0,160])
plt.tick_params(axis='both',labelsize=14)
plt.show()

