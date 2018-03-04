#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		/*char temp[200] = "";
		int j = 0;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ') {
				temp[j++] = '%';
				temp[j++] = '2';
				temp[j++] = '0';
			}
			else {
				temp[j] = str[i];
				j++;
			}
			if (str[i] == '\0')
				break;
		}
		str = temp;*/

		/*int k = 0,i = 0, len = 0;
		while (str[i] != '\0') { 
			len++;
			i++;
		}
		len++;
		i = 0;
		while (str[i] != '\0') {
			if (str[i] == ' ') {
				for (int j = i + 1; j < len + 3; j++) {
					str[len + 1 - k] = str[len - k - 1];
					k++;
				}
				length += 3;
				str[i++] = '%';
				str[i++] = '2';
				str[i++] = '0';
			}
			if (str[i] == '\0')
				break;
		}*/


		//从后往前扫描替换，可以减少字符移动次数
		int i = 0;
		int spacenum = 0, oldlength = 0, newlength = 0;
		while (str[i] != '\0') {
			if (str[i] == ' ')
				spacenum++;
			oldlength++;
			i++;
		}

		if (oldlength == 0 || spacenum == 0 || newlength > length)
			return;
		newlength = oldlength + spacenum * 2;//原来的空格属于一个,所以只需要再加两个
		while (oldlength >= 0 && newlength > oldlength) { 
			if (str[oldlength] == ' ') {
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';
			}
			else {
				str[newlength--] = str[oldlength];
			}
			oldlength--;
		}
	}
};


int main() {
	char str[200] = "";
	int i = 0;
	Solution *s = new Solution();
	cin.get(str, 13);
	s->replaceSpace(str, 13);
	return 0;
}