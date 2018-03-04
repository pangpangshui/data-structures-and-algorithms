//旋转数组
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。 
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0)
//			return 0;
//		int i;
//		for (i = 0; i < rotateArray.size(); i++) {
//			if (rotateArray[i] > rotateArray[i + 1])
//				return rotateArray[i + 1];
//		}
//		return rotateArray[i];
//	}
//};


//二分法
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int low = 0, high = rotateArray.size() - 1, mid;
		while (low < high) {
			mid = (low + high) / 2;
			if (rotateArray[high] < rotateArray[mid])
				low = mid + 1;
			else if (rotateArray[high] > rotateArray[mid])
				high = mid;
			//此处需要特别注意，出现这种情况的array类似 [1,0,1,1,1] 或者[1,1,1,0,1]，此时最小数字不好判断在mid左边还是右边, 这时只好一个一个试 ，
			else if (rotateArray[high] == rotateArray[mid]) {
				high = high - 1;
			}
			
		}
		return rotateArray[low];
	}
};