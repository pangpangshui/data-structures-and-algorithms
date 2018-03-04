#include <iostream>

using namespace std;


class Space {
public:
	void RemoveSpace(char *str) {
		int i = 0, j = 0;
		while (str[i] != '\0') {
			if (str[i] != ' ') {
				str[j] = str[i];
				j++;
			}
			i++;
		}
		str[j] = '\0';
	}
};


void main() {
	Space *s = new Space();
	s->RemoveSpace("hello  world");
	/*char str[50] = "hello  world";
	int i = 0, j = 0;
	while (str[i] != '\0') {
		if (str[i] != ' ') {
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	printf_s("%s", str);*/
	return;
}

