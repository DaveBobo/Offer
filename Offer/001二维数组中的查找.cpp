#include <iostream>
#include <vector>
using namespace std;
/* 思路
* 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
* 因此从左下角开始查找，当要查找数字比左下角数字大时。右移
* 要查找数字比左下角数字小时，上移
*/
class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		/*二维数组的行数和列数*/
		int rowCount = array.size();
		int colCount = array[0].size();
		int i, j;//i指定行的变化,j指定列的变化

		//循环
		for (i = rowCount - 1, j = 0; i >= 0 && j < colCount;)
		{
			if (target == array[i][j])
				return true;

			if (target < array[i][j])
			{
				i--;
				continue;
			}

			if (target > array[i][j])
			{
				j++;
				continue;
			}
		}
		return false;
	}
};

int main001(){
	
	vector<vector<int>> myArray;

	for (int i = 0; i < 2;i++)
	{
		myArray.push_back(vector<int>(3));
	}

	myArray[0][0] = 1;
	myArray[0][1] = 2;
	myArray[0][2] = 3;
	myArray[1][0] = 4;
	myArray[1][1] = 5;
	myArray[1][2] = 6;

	Solution sln;
	if (sln.Find(3, myArray))
	{
		printf("YES!\n");
	}
	else{
		printf("NO!\n");
	}
	system("pause");
	return 0;
}