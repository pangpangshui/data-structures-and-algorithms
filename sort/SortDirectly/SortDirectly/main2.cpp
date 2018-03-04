#include <iostream>
#include <vector>


using namespace std;

//直接插入排序的运作如下：
//
//1、将待排序序列的第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
//
//2、从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
void InsertDrectly(vector<int> &arr)
{
	int temp, i, j;
	for (i = 1; i < arr.size(); i++)
	{
		temp = arr[i];
		//将temp即arr[i]插入到有序序列arr[0]~arr[j]里面，所以需要排序
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		if (j != i - 1)//用于将保存的arr[i]值放在被替换的位置的之后一个位置
		{
			arr[j + 1] = temp;
		}
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
	InsertDrectly(arr);
}



//当原始序列“正序”时，直接插入排序效果最好，所以直接插入排序最好情况下时间复杂度为O(n)；当原始序列“逆序”时，直接插入排序效果最差，所以直接插入排序最坏情况下时间复杂度为O(n ^ 2)。
//
//直接插入排序平均时间复杂度为O(n ^ 2)；空间复杂度为O(1)；是稳定的排序算法。