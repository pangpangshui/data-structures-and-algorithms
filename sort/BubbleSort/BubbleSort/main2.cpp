#include <iostream>
#include <vector>

using namespace std;


//��һ��ð������

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

//�ڶ���ð������
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
//��β�������ֽж���ð�����򣬽���������������ȣ���ð�������һ�ֱ��Ρ����㷨��ð������Ĳ�ͬ����������ʱ����˫���������н�������
//
//��β��������������������ȴӵ͵��ߣ�Ȼ��Ӹߵ��ͣ���ð����������ӵ͵���ȥ�Ƚ��������ÿ��Ԫ�ء������Եõ���ð��������΢��һ���Ч�ܣ�ԭ����ð������ֻ��һ��������бȶԣ��ɵ͵��ߣ���ÿ��ѭ��ֻ�ƶ�һ����Ŀ��

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



//��1��ʱ�临�Ӷ�
//
//�����ñ�־����֮��
//
//��ԭʼ���С���������ʱ��ð�������ܵıȽϴ���Ϊn - 1���ƶ�����Ϊ0��Ҳ����˵ð���������������µ�ʱ�临�Ӷ�ΪO(n)��
//
//��ԭʼ���С���������ʱ��ð�������ܵıȽϴ���Ϊn(n - 1) / 2���ƶ�����Ϊ3n(n - 1) / 2�Σ�����ð�������������µ�ʱ�临�Ӷ�ΪO(n ^ 2)��
//
//��ԭʼ������������ʱ��ð�������ƽ��ʱ�临�Ӷ�ΪO(n ^ 2)��
//
//
//
//��2���ռ临�Ӷ�
//
//ð�����������������Ҫһ����ʱ����������������������Ҫ�Ķ���ռ�Ϊ1����˿ռ临�Ӷ�ΪO(1)��
//
//
//
//��3���ȶ���
//
//ð����������������У�Ԫ����������ʱ����ͬԪ�ص�ǰ��˳��û�иı䣬����ð��������һ���ȶ������㷨��