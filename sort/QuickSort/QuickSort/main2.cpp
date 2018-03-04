#include <iostream>
#include <vector>

using namespace std;


void QuickSort(vector<int> &arr, int left, int right)
{
	
	if (left >= right)
		return;
	int l = left, r = right;
	int temp = arr.at(l);
	while (l < r)
	{
		while (l < r && temp <= arr.at(r))
			r--;
		if (l < r)
		{
			arr[l] = arr[r];
			//l++;
		}

		while (l < r && temp >= arr.at(l))
			l++;
		if (l < r)
		{
			arr[r] = arr[l];
			//r--;
		}
	}
	arr[l] = temp;
	QuickSort(arr, left, l - 1);
	QuickSort(arr, l + 1, right);
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
	QuickSort(arr, 0, arr.size() - 1);
	return 0;
}