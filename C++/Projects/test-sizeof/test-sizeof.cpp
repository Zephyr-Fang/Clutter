// test-sizeof.cpp : �������̨Ӧ�ó������ڵ㡣
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
	virtual void noMeanB1();    //���۶��ٸ��麯����ֻ����һ���麯��ָ�룬4���ֽ�
	virtual void noMeanB2();
	void noMeanB3();    //������ռ�
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
	cout << "ch[2]�Ĵ�СΪ��" << sizeof(ch) << endl;
	cout << "��A�Ĵ�СΪ��" << sizeof(a) << endl;    //8���ֽڣ���Ϊ�ڴ���룡
	cout << "��B�Ĵ�СΪ��" << sizeof(b) << endl;
	cout << "��C�Ĵ�СΪ��" << sizeof(c) << endl;
	return 0;
}