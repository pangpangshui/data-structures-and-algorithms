#include <iostream>
#include <vector>

using namespace std;

void ShellSort(vector<int> &arr)
{
	int gap = 0, i, j, temp;
	while (gap < arr.size() / 3)
	{
		gap = gap * 3 + 1;
	}
	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < arr.size(); i++)
		{
			temp = arr[i];
			for (j = i - gap; j >= 0 && temp < arr[j]; j -= gap)
			{
				arr[j + gap] = arr[j];
			}
			/*if (j != i - 1)
			{
				arr[j + gap] = temp;
			}*/
			arr[j + gap] = temp;
		}
	}

	for(int i = 0; i < arr.size(); i++)
	{
		printf("%d ", arr[i]);
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
	ShellSort(arr);
	system("pause");
}