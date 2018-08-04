// test.cpp : 定义控制台应用程序的入口点。
//
// vector<_>::iterator iter = _.begin();


#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <limits>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n = -1;
	n %= 2;
	cout << n;
	return 0;
}













/*
void input(vector<int>& num) {
	string str;
	getline(cin, str);
	int size = str.size();
	for (int i = 0;i < size;) {
		if (str[i] == '-') {
			++i;
			int nTmp = str[i] - '0';
			++i;
			for (;isdigit(str[i]);i++) {
				nTmp = nTmp * 10 + str[i] - '0';
			}
			num.push_back(-nTmp);
		}
		else if (isdigit(str[i])) {
			int nTmp = str[i] - '0';
			++i;
			for (;isdigit(str[i]);i++) {
				nTmp = nTmp * 10 + str[i] - '0';
			}
			num.push_back(nTmp);
		}
		else
			i++;
	}
}

int main() {
	vector<int> num;
	input(num);
	int size = num.size();
	int maxSum = INT_MIN, tmpSum = 0;
	for (int i = 0;i < size;i++) {
		tmpSum += num[i];
		maxSum = tmpSum > maxSum ? tmpSum : maxSum;
		if (tmpSum < 0)
			tmpSum = 0;
	}
	cout << maxSum << endl;
	return 0;
}
*/

















/*
void put(int begin, int end, int remv, vector<int>& num,int& cnt) {
	if (begin == end) {
		if (num[begin] <= remv)
			cnt++;
		return;
	}
	if (num[begin] <= remv) {
		cnt++;
		put(begin + 1, end, remv - num[begin], num, cnt);
	}
	else 
		put(begin + 1, end, remv, num, cnt);
}

int main() {
	int cnt = 0;
	int n, v;
	cin >> n >> v;
	vector<int> num;
	for()
	return 0;
}

void input(vector<vector<char>>& str,int n) {
	for (int i = 0;i < n;i++) {
		int col;
		cin >> col;
		str.push_back(vector<char>());
		for (int j = 0;j < col;j++) {
			char tmp;
			cin >> tmp;
			str[i].push_back(tmp);
		}
	}
}

void output(vector<vector<char>>& str, int n) {
	for (int i = 0;i < n;i++) {
		int size = str[i].size();
		int res = 0;
		for (int j = 0;j < size;j++) {
			if (str[i][j] == '.') {
				j+=2;
				res++;
			}
		}
		cout << res;
	}
}

int main() {
	int total;
	cin >> total;
	vector<vector<char>> str;
	input(str, total);
	output(str, total);
	return 0;
}
*/
