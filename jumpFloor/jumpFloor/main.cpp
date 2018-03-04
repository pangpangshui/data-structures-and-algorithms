//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//斐波那契数列的变形--jumpFloor函数的解
//解：把n级台阶时的跳法记为f(n)，当n>2时，第一次跳的时候有两种不同的选择：
//一是第一次只跳1级，此时跳法数目等于后面剩下的n - 1级台阶的跳法数目，即为f(n - 1); 
//另外一种是第一次跳2级，此时跳法数目等于后面剩下的n - 2级台阶的跳法数目，即为f(n - 2); 
//因此n级台阶时的跳法为f(n) = f(n - 1) + f(n - 2)。不难看出这实际是斐波拉契数列的变形应用，把斐波拉契数列的每一项向前移动了1位。


//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//解决函数--jumpFloor2()

//用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//依旧是斐波那契数列，不过这次f(0) = 0
//2 * n的大矩形，和n个2 * 1的小矩形
//其中target * 2为大矩阵的大小
//有以下几种情形：
//1⃣️target <= 0 大矩形为 <= 2 * 0, 直接return 0；
//2⃣️target = 1大矩形为2 * 1，只有一种摆放方法，return1；
//3⃣️target = 2 大矩形为2 * 2，有两种摆放方法，return2；
//4⃣️target = n 分为两步考虑：
//第一次摆放一块 2 * 1 的小矩阵，则摆放方法总共为f(target - 1)
//第一次摆放一块1 * 2的小矩阵，则摆放方法总共为f(target - 2)
//因为，摆放了一块1 * 2的小矩阵（用√√表示），对应下方的1 * 2（用××表示）摆放方法就确定了，所以为f(targte - 2)
//所以是斐波那契数列

#include <iostream>
#include <cmath>


using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		int sum, n1 = 1, n2 = 1;
		if (number == 1 || number == 0) {
			return 1;
		}
		while (number > 1) {
			sum = n1 + n2;
			number--;
			n1 = n2;
			n2 = sum;
		}
		return sum;
	}

	// f(n) = 2*f(n-1)， 此函数
	int jumpFloor2(int number) {
		int sum;
		if (number <= 0) { 
			return -1;
		}
		if (number == 1)
			return 1;
		sum = pow(2 , (number - 1));
		//或者是sum = 1 << (--number);左移(number-1)位相当于2的(number-1)次方

		/*n3 = n1 + n2;
		sum = n1 + n2 + n3;
		n1 = n2;
		n2 = n3;
		n3 = sum;*/
		return sum;
	}
};

int main() {
	Solution *s = new Solution();
	s->jumpFloor2(3);
	return 0;
}