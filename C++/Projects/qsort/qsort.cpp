// qsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T>
void Swap(T* a, T* b) {
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int num[], int begin, int end) {
	if (num == nullptr || begin >= end || begin < 0)
		throw std::exception("Invalid Parameters");
	int index = begin;
	Swap(&num[index], &num[end]);
	int small = index - 1;
	for (;index < end;++index) {
    //把所有比num[end]小的数字移到前面
		if (num[index] < num[end]) {
			++small;
			if (small != index)
				Swap(&num[small], &num[index]);
		}
	}
	++small;
	Swap(&num[small], &num[end]);
	return small;
}

void qsort(int num[], int begin, int end) {
	if (begin == end)
		return;
	int index = partition(num, begin, end);
	if (index > begin)
		qsort(num, begin, index - 1);
	if (index < end)
		qsort(num, begin + 1, end);
	return;
}

template<class T>
void output(const T num[],int size) {
	for (int i = 0; i < size; i++)
		cout << *(num + i) << " ";
	cout << endl << "输出完毕!" << endl;
}

int main()
{
	const int size = 6;
	int num[size] = { 5,3,7,8,1,10 };
	int begin = 0, end = 5;
	qsort(num, begin, end);
	output(num, size);
    return 0;
}

