#include <iostream>
#include <vector>

using namespace std;


//ֱ������
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



//��1������˼��
//
//�۰��������Ļ���˼���ǣ�˳��ذѴ�����������еĸ���Ԫ�ذ���ؼ��ֵĴ�С��ͨ���۰���Ҳ��뵽����������е��ʵ�λ�á�
//
//��2�����й���
//
//ֱ�Ӳ���������������£�
//
//1�������������еĵ�һ��Ԫ�ؿ���һ���������У��ѵڶ���Ԫ�ص����һ��Ԫ�ص�����δ�������С�
//
//2����ͷ��β����ɨ��δ�������У���ɨ�赽��ÿ��Ԫ�ز����������е��ʵ�λ�ã��ڲ���Ԫ�ص��ʵ�λ��ʱ���������۰���ҷ�����������������Ԫ�������������е�ĳ��Ԫ����ȣ��򽫴�����Ԫ�ز��뵽���Ԫ�صĺ��档��
//�۰����ֻ�Ǽ����˱Ƚϴ���������Ԫ�ص��ƶ��������䡣�۰��������ƽ��ʱ�临�Ӷ�ΪO(n ^ 2)���ռ临�Ӷ�ΪO(1)�����ȶ��������㷨��

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