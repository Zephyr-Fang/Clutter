// 01Pakage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void zeroOnePack(vector<int>& v, int maxLength) {
	/****函数完成dp数组初始化及输出****/
	vector<vector<int>> dp(v.size() + 1, vector<int>(maxLength + 1, 0));//创建二维数组dp[i][j]=dp[v.size()+1][maxLength+1],i为第i件物品,j为背包容量，值为前i种物品放于容量j中的种数
	//dp[0][j]已经初始化为0了
	for (unsigned i = 0;i <= v.size();i++)
		//初始化dp[i][0]，容量为0，什么都不放，只有1种
		dp[i][0] = 1;
	for (unsigned i = 1;i <= v.size();i++) {
		for (int j = 1;j <= maxLength;j++) {
			if (v[i - 1] <= j)
				//第i种物品如果权重v[i-1]小于等于j,则种类数 = 第i个不放(前i-1个物品放入容量j中)的种类数 + 第i个放(前i-1个物品放入容量为j - v[i - 1]中)的种类数
				dp[i][j] = dp[i - 1][j] % 1000000007 + dp[i - 1][j - v[i - 1]] % 1000000007;
			else
				//如果超重，则不放，种类数 = 第i个不放(前i-1个物品放入容量j中)的种类数
				dp[i][j] = dp[i - 1][j] % 1000000007;
			cout << dp[i][j] << "  ";//输出数组测试
		}
		cout << endl;//格式化输出到屏幕
	}
}

int main()
{
	vector<int> v{ 2,2,2,3,3,3 };//C++11 中新支持的列表初始化
	int maxLength = 5;
	zeroOnePack(v, maxLength);
    return 0;
}

