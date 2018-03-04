#include <iostream>
#include <vector>

using namespace std;

//template<typename T>

void MergeSort(vector<int> arr)
{
	//����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ�������У�
	vector<int> a = arr;
	vector<int> b(arr.size(), 0);
	for (int seg = 1; seg < arr.size(); seg += seg)
	{
		//�ظ�����3ֱ��ĳһָ��ﵽ����β��
		for (int start = 0; start < arr.size(); start += seg * 2)
		{
			int low = start;
			int mid = start + seg < arr.size() ? (start + seg) : arr.size();
			int high = start + seg + seg < arr.size() ? (start + seg + seg) : arr.size();
			int k = low;

			//�趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ�ã�
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			//�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ�ã�
			while (start1 < end1 && start2 < end2)
			{
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			}
			
			//����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��
			while (start1 < end1)
				b[k++] = a[start1++];
			//����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��
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



//��1������˼��
//
//�鲢����Ļ���˼����ǣ��Ѵ��������з�Ϊ���ɸ������У�ÿ��������������ģ�Ȼ���ٰ����������кϲ�Ϊ�����������С�������ʹ�õ��Ƕ�·�鲢�㷨�����������Ѿ���������кϲ���һ�����еĲ�����
//
//��2�����й���
//
//�鲢�����㷨�����й������£�
//
//1������ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ�������У�
//
//2���趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ�ã�
//
//3���Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ�ã�
//
//4���ظ�����3ֱ��ĳһָ��ﵽ����β��
//
//5������һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��