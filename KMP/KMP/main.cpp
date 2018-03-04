#include <iostream>
#include <string>
using namespace std;

#define MAX 10000
char str[MAX], substr[MAX];
int Next[MAX] = {};


void getNext() {
	int i = 0, j = -1;
	Next[0] = -1;
	while (i < strlen(substr)) {
		while (j >= 0 && substr[i] != substr[j])
			j = Next[j];
		Next[i++] = j++;
	}
}


int KMP(int *count) {
	int i = 0, j = 0, num = 0;
	while (j < strlen(str)) {
		if (i == -1 || substr[i] == str[j]) {
			i++;
			j++;
		}
		else
			i = Next[i];
		if (i == strlen(substr)) {
			count++;
			num++;
			//return (j - strlen(substr) + 1);
		}			
	}
	return num;
}

int main()
{
	int *count = 0;
	cin >> str;
	cin >> substr;

	getNext();
	cout << KMP(count);

	return 0;
}