#include <iostream>
#include <vector>

using namespace std;


//直接排序
void InsertSort(vector<int> &arr)
{
	int temp = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}



//（1）基本思想
//
//折半插入排序的基本思想是：顺序地把待排序的序列中的各个元素按其关键字的大小，通过折半查找插入到已排序的序列的适当位置。
//
//（2）运行过程
//
//直接插入排序的运作如下：
//
//1、将待排序序列的第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
//
//2、从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置，在查找元素的适当位置时，采用了折半查找方法。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
//折半查找只是减少了比较次数，但是元素的移动次数不变。折半插入排序平均时间复杂度为O(n ^ 2)；空间复杂度为O(1)；是稳定的排序算法。

void BinSort(vector<int> &arr)
{
	int left = 0, right = 0, middle = 0, temp = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		temp = arr[i];
		left = 0, right = i - 1;
		while (left <= right)
		{
			middle = (left + right) / 2;
			if (arr[i] < arr[middle])
			{
				right = middle - 1;
			}
			else
				left = middle + 1;
		}
		for (int j = i - 1; j >= left; j--)
		{
			arr[j + 1] = arr[j];
		}
		if (left != i)
			arr[left] = temp;
	}
}


void main()
{
	int data;
	vector<int> arr;
	while (cin >> data)
	{
		arr.push_back(data);
		if (cin.get() == '\n')
			break;
	}
	//InsertSort(arr);
	BinSort(arr);
	for (vector<int>::iterator iter = arr.begin(); iter != arr.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	system("pause");
}