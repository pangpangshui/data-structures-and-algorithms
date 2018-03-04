//��ת����
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
//��������{ 3,4,5,1,2 }Ϊ{ 1,2,3,4,5 }��һ����ת�����������СֵΪ1�� 
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

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


//���ַ�
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
			//�˴���Ҫ�ر�ע�⣬�������������array���� [1,0,1,1,1] ����[1,1,1,0,1]����ʱ��С���ֲ����ж���mid��߻����ұ�, ��ʱֻ��һ��һ���� ��
			else if (rotateArray[high] == rotateArray[mid]) {
				high = high - 1;
			}
			
		}
		return rotateArray[low];
	}
};