#include <iostream>
#include <vector>

using namespace std;

//template<typename T>

void MergeSort(vector<int> arr)
{
	//申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
	vector<int> a = arr;
	vector<int> b(arr.size(), 0);
	for (int seg = 1; seg < arr.size(); seg += seg)
	{
		//重复步骤3直到某一指针达到序列尾；
		for (int start = 0; start < arr.size(); start += seg * 2)
		{
			int low = start;
			int mid = start + seg < arr.size() ? (start + seg) : arr.size();
			int high = start + seg + seg < arr.size() ? (start + seg + seg) : arr.size();
			int k = low;

			//设定两个指针，最初位置分别为两个已经排序序列的起始位置；
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			//比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
			while (start1 < end1 && start2 < end2)
			{
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			}
			
			//将另一序列剩下的所有元素直接复制到合并序列尾。
			while (start1 < end1)
				b[k++] = a[start1++];
			//将另一序列剩下的所有元素直接复制到合并序列尾。
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		vector<int> temp = a;
		a = b;
		b = temp;
	}
	/*if (a != arr)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			b[i] = a[i];
		}
		b = a;
	}*/
	b.clear();
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
	{
		cout << *iter << " ";
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
	MergeSort(arr);
	system("pause");
}



//（1）基本思想
//
//归并排序的基本思想就是：把待排序序列分为若干个子序列，每个子序列是有序的，然后再把有序子序列合并为整体有序序列。经常被使用的是二路归并算法，即将两个已经排序的序列合并成一个序列的操作。
//
//（2）运行过程
//
//归并排序算法的运行过程如下：
//
//1、申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
//
//2、设定两个指针，最初位置分别为两个已经排序序列的起始位置；
//
//3、比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
//
//4、重复步骤3直到某一指针达到序列尾；
//
//5、将另一序列剩下的所有元素直接复制到合并序列尾。