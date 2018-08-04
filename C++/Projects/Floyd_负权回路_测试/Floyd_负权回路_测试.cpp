// Floyd_负权回路_测试.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{

	/*1到2距离为2，2到3距离为3，3到1为-6*/

	int e[3][3], k, i, j;
	int inf = 99999999;                                     
	for (i = 0;i <= 2;i++) {
		for (j = 0;j <= 2;j++) {
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
		}
	}
	e[0][1] = 2;
	e[1][2] = 3;
	e[2][0] = -6;

	/*第一次求距离*/

	for (k = 0;k <= 2;k++) {
		for (i = 0;i <= 2;i++) {
			for (j = 0;j <= 2;j++) {
				if (e[i][k] < inf&&e[k][j]<inf&&e[i][j]>e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}

	/*第二次求距离*/

	for (k = 0;k <= 2;k++) {
		for (i = 0;i <= 2;i++) {
			for (j = 0;j <= 2;j++) {
				if (e[i][k] < inf&&e[k][j]<inf&&e[i][j]>e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}

	/*以下输出数组*/

	for (i = 0;i <= 2;i++) {
		for (j = 0;j <= 2;j++) {
			cout << e[i][j]<<" ";
		}
		cout << "\n";
	}
    return 0;
}

