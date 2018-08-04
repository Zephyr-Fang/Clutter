// randNumber.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
	default_random_engine e(unsigned(time(0)));    //创建随机数列对象并设置种子
	e.seed(10);    //将种子改为 10
	uniform_int_distribution<unsigned> iu(0, 9);    //均匀分布，整数 0~9
	uniform_real_distribution<double> ru(0, 1);    //均匀分布，小数 0~1
	normal_distribution<> n(4, 1.5);    //正态分布，均值为4，方差为1.5
	for (size_t i = 0; i < 10; ++i)
		//注意e是函数对象，调用需要加（） 
		cout << e() << '\t' << iu(e) << '\t' << ru(e) << '\t' << n(e) << endl;
	return 0;
}

/*
#include <cstdlib>    //包含rand函数的库
#include <ctime>
#include <iostream>
using namespace std;

int randInt(int lowerBound, int upBound) {
	//产生[a,b)范围内的随机整数
	return rand() % (upBound - lowerBound) + lowerBound;
}
float randDecimal() {
	//产生0~1内的小数
	return rand() / double(RAND_MAX);
}

int main() {
	cout << RAND_MAX << endl;
	srand((unsigned)time(0));
	for (int i = 0;i < 10;i++)
		cout << randInt(0, 100) << '\t' << randDecimal() << endl;
	return 0;
}
*/