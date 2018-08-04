// randNumber.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
	default_random_engine e(unsigned(time(0)));    //����������ж�����������
	e.seed(10);    //�����Ӹ�Ϊ 10
	uniform_int_distribution<unsigned> iu(0, 9);    //���ȷֲ������� 0~9
	uniform_real_distribution<double> ru(0, 1);    //���ȷֲ���С�� 0~1
	normal_distribution<> n(4, 1.5);    //��̬�ֲ�����ֵΪ4������Ϊ1.5
	for (size_t i = 0; i < 10; ++i)
		//ע��e�Ǻ������󣬵�����Ҫ�ӣ��� 
		cout << e() << '\t' << iu(e) << '\t' << ru(e) << '\t' << n(e) << endl;
	return 0;
}

/*
#include <cstdlib>    //����rand�����Ŀ�
#include <ctime>
#include <iostream>
using namespace std;

int randInt(int lowerBound, int upBound) {
	//����[a,b)��Χ�ڵ��������
	return rand() % (upBound - lowerBound) + lowerBound;
}
float randDecimal() {
	//����0~1�ڵ�С��
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