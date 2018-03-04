#pragma warning(disable:4996) //全部關掉

#include <iostream>

using namespace std;

long num;
char p[30];
int Count = 0;

//递归  字符串->整数
long stringToint(char *str) {
	num = num * 10 + *str - '0';
	if (*(str+1) != '\0') {
		stringToint(str + 1);
	}
	return num;
}


char* intTostring(long number) {
	//int i;
	p[Count] = number % 10 + '0';
	Count++;
	number = number / 10;
	
	if (number != 0) {
		intTostring(number);
	}
	
	
	return p;
}

int main() {
	char str[30];
	scanf("%s", str);
	printf_s("%ld", stringToint(str));
	printf_s("\n");

	intTostring(num);
	char temp;
	for (int i = 0; i < strlen(p) / 2; i++) {
		temp = p[i];
		p[i] = p[strlen(p) - i - 1];
		p[strlen(p) - i - 1] = temp;
	}
	printf_s("%s", p);
	return 0;
}