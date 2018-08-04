// KMP.cpp : �������̨Ӧ�ó������ڵ㡣
// ���㷨���ڲ���ģʽ�ַ���p���ı��ַ���s�е�λ��

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> GetNextval(string p) {
	// ��ģʽ�ַ���p����next����
	int pLen = p.size();
	vector<int> next(pLen, 0);
	next[0] = -1;    //��0��Ԫ��֮ǰû���κ��ַ�������ͬ
	int k = -1;    //k����Ҫ��jǰ��
	int j = 0;
	while (j < pLen - 1) {
		//p[k]��ʾǰ׺��p[j]��ʾ��׺    
		if (k == -1 || p[j] == p[k]) {
			++j;
			++k;    //����k��СΪ0����ʾǰ����0���ַ�
			if (p[j] != p[k])
				next[j] = k;    //kλ��ǰ�����ɸ��ַ���jλ��ǰ�����ɸ��ַ���ͬ
			else
				next[j] = next[k];    //��Ϊp[j]�Ѿ���s[i]�����ڴ˺����е��ı��ַ�����ʧ�䣬���next[j] = k������p[j] == p[k]����p[j] == p[next[j]]������Ծ���ٴ�ʧ�䣻
									  //���Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]����p[j] == p[next[k]]�����𣿴��ǲ�������Ϊ֮ǰ���ų��˳����� 0
		}
		else
			k = next[k];    //���k��Ϊ-1��j���ı�
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
			//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++
			i++;
			j++;
		}
		else
			j = next[j];    //�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]  
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