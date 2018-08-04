// 01Pakage.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void zeroOnePack(vector<int>& v, int maxLength) {
	/****�������dp�����ʼ�������****/
	vector<vector<int>> dp(v.size() + 1, vector<int>(maxLength + 1, 0));//������ά����dp[i][j]=dp[v.size()+1][maxLength+1],iΪ��i����Ʒ,jΪ����������ֵΪǰi����Ʒ��������j�е�����
	//dp[0][j]�Ѿ���ʼ��Ϊ0��
	for (unsigned i = 0;i <= v.size();i++)
		//��ʼ��dp[i][0]������Ϊ0��ʲô�����ţ�ֻ��1��
		dp[i][0] = 1;
	for (unsigned i = 1;i <= v.size();i++) {
		for (int j = 1;j <= maxLength;j++) {
			if (v[i - 1] <= j)
				//��i����Ʒ���Ȩ��v[i-1]С�ڵ���j,�������� = ��i������(ǰi-1����Ʒ��������j��)�������� + ��i����(ǰi-1����Ʒ��������Ϊj - v[i - 1]��)��������
				dp[i][j] = dp[i - 1][j] % 1000000007 + dp[i - 1][j - v[i - 1]] % 1000000007;
			else
				//������أ��򲻷ţ������� = ��i������(ǰi-1����Ʒ��������j��)��������
				dp[i][j] = dp[i - 1][j] % 1000000007;
			cout << dp[i][j] << "  ";//����������
		}
		cout << endl;//��ʽ���������Ļ
	}
}

int main()
{
	vector<int> v{ 2,2,2,3,3,3 };//C++11 ����֧�ֵ��б��ʼ��
	int maxLength = 5;
	zeroOnePack(v, maxLength);
    return 0;
}

