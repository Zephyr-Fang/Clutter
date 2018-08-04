// KMP.cpp : 定义控制台应用程序的入口点。
// 该算法用于查找模式字符串p在文本字符串s中的位置

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> GetNextval(string p) {
	// 由模式字符串p返回next数组
	int pLen = p.size();
	vector<int> next(pLen, 0);
	next[0] = -1;    //第0个元素之前没有任何字符与它相同
	int k = -1;    //k必须要在j前面
	int j = 0;
	while (j < pLen - 1) {
		//p[k]表示前缀，p[j]表示后缀    
		if (k == -1 || p[j] == p[k]) {
			++j;
			++k;    //下面k最小为0，表示前面有0个字符
			if (p[j] != p[k])
				next[j] = k;    //k位置前面若干个字符和j位置前面若干个字符相同
			else
				next[j] = next[k];    //因为p[j]已经与s[i]（不在此函数中的文本字符串）失配，如果next[j] = k，由于p[j] == p[k]，即p[j] == p[next[j]]，则跳跃后将再次失配；
									  //所以当出现时需要继续递归，k = next[k] = next[next[k]]。那p[j] == p[next[k]]成立吗？答案是不成立因为之前就排除了除非是 0
		}
		else
			k = next[k];    //最差k变为-1，j不改变
	}
	return next;
}

int KmpSearch(string s,string p,vector<int>& next) {
	int i = 0;
	int j = 0;
	int sLen = s.size();
	int pLen = p.size();
	while (i < sLen && j < pLen) {      
		if (j == -1 || s[i] == p[j]) {    
			//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
			i++;
			j++;
		}
		else
			j = next[j];    //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]  
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main() {
	string p = "abc";
	string s1 = "zyxabcmmmn";
	string s2 = "asdfghjkl";
	vector<int> next = GetNextval(p);
	cout << KmpSearch(s1, p, next) << '\t' << KmpSearch(s2, p, next) << endl;
	return 0;
}