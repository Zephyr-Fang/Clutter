// Floyd_��Ȩ��·_����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{

	/*1��2����Ϊ2��2��3����Ϊ3��3��1Ϊ-6*/

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

	/*��һ�������*/

	for (k = 0;k <= 2;k++) {
		for (i = 0;i <= 2;i++) {
			for (j = 0;j <= 2;j++) {
				if (e[i][k] < inf&&e[k][j]<inf&&e[i][j]>e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}

	/*�ڶ��������*/

	for (k = 0;k <= 2;k++) {
		for (i = 0;i <= 2;i++) {
			for (j = 0;j <= 2;j++) {
				if (e[i][k] < inf&&e[k][j]<inf&&e[i][j]>e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
			}
		}
	}

	/*�����������*/

	for (i = 0;i <= 2;i++) {
		for (j = 0;j <= 2;j++) {
			cout << e[i][j]<<" ";
		}
		cout << "\n";
	}
    return 0;
}

