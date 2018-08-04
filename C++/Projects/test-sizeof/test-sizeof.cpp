// test-sizeof.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream> 
#include <algorithm>
using namespace std;

class A {
//private:
public:
	char a[2];
	virtual void noMeanA();
};
class B : public A {
public:
	char b1[2];
	char b2[2];
	virtual void noMeanB1();    //无论多少个虚函数都只分配一个虚函数指针，4个字节
	virtual void noMeanB2();
	void noMeanB3();    //不分配空间
};
class C {
public:
	char c[2];
};

void A::noMeanA() {
	cout << "This is class A!" << endl;
}
void B::noMeanB1() {
	cout << "This is B.noMeanB1!" << endl;
}
void B::noMeanB2() {
	cout << "This is B.noMeanB2!" << endl;
}
void B::noMeanB3() {
	cout << "This is B.noMeanB3!" << endl;
}

int main() {
	A a;
	B b;
	C c;
	char ch[2];
	cout << "ch[2]的大小为：" << sizeof(ch) << endl;
	cout << "类A的大小为：" << sizeof(a) << endl;    //8个字节，因为内存对齐！
	cout << "类B的大小为：" << sizeof(b) << endl;
	cout << "类C的大小为：" << sizeof(c) << endl;
	return 0;
}