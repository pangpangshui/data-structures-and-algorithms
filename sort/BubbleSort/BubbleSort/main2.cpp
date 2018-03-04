#include <iostream>
#include <vector>

using namespace std;


//第一种冒泡排序

void bubbleSort1(vector<int> arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr.at(j + 1) < arr.at(j))
			{
				int temp = arr.at(j + 1);
				arr.at(j + 1) = arr.at(j);
				arr.at(j) = temp;
			}
		}
	}
}

//第二种冒泡排序
void bubbleSort2(vector<int> arr)
{
	bool flag;
	for (int i = 0; i < arr.size() - 1; i++) {
		flag = false;
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr.at(j + 1) < arr.at(j))
			{
				int temp = arr.at(j + 1);
				arr.at(j + 1) = arr.at(j);
				arr.at(j) = temp;
				flag = true;
			}
			if (flag == false)
				break;
		}
	}
}

//
//鸡尾酒排序又叫定向冒泡排序，搅拌排序、来回排序等，是冒泡排序的一种变形。此算法与冒泡排序的不同处在于排序时是以双向在序列中进行排序。
//
//鸡尾酒排序在于排序过程是先从低到高，然后从高到低；而冒泡排序则仅从低到高去比较序列里的每个元素。它可以得到比冒泡排序稍微好一点的效能，原因是冒泡排序只从一个方向进行比对（由低到高），每次循环只移动一个项目。

void cocktail_sort(vector<int> arr)
{
	int left = 0, right = arr.size() - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (arr.at(i + 1) < arr.at(i))
			{
				int temp = arr.at(i + 1);
				arr.at(i + 1) = arr.at(i);
				arr.at(i) = temp;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (arr.at(i - 1) > arr.at(i))
			{
				int temp = arr.at(i - 1);
				arr.at(i - 1) = arr.at(i);
				arr.at(i) = temp;
			}
		}
		left++;
	}
}

int main()
{
	int data;
	vector<int> arr;
	while (cin >> data)
	{
		arr.push_back(data);
		if (cin.get() == '\n')
			break;
	}
	//bubbleSort1(arr);
	cocktail_sort(arr);
}



//（1）时间复杂度
//
//在设置标志变量之后：
//
//当原始序列“正序”排列时，冒泡排序总的比较次数为n - 1，移动次数为0，也就是说冒泡排序在最好情况下的时间复杂度为O(n)；
//
//当原始序列“逆序”排序时，冒泡排序总的比较次数为n(n - 1) / 2，移动次数为3n(n - 1) / 2次，所以冒泡排序在最坏情况下的时间复杂度为O(n ^ 2)；
//
//当原始序列杂乱无序时，冒泡排序的平均时间复杂度为O(n ^ 2)。
//
//
//
//（2）空间复杂度
//
//冒泡排序排序过程中需要一个临时变量进行两两交换，所需要的额外空间为1，因此空间复杂度为O(1)。
//
//
//
//（3）稳定性
//
//冒泡排序在排序过程中，元素两两交换时，相同元素的前后顺序并没有改变，所以冒泡排序是一种稳定排序算法。