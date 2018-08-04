// Reverse_string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void reverse_string(char *STR) {
	char *LAST;
	for (LAST = STR;*LAST != '\0';LAST++)
		;
	LAST--;
	while (STR < LAST) {
		char TEMP=*LAST;
		*LAST = *STR;
		*STR = TEMP;
		LAST--;
		STR++;
	}
}
int main()
{
	char string[10]="abcdefghi";
	reverse_string(string);
	cout<<*string;
    return 0;
}

