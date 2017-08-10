#include <iostream>
#include <vector>
using namespace std;
/* ˼·
* ����������ģ������½��������������ֵݼ����������ֵ�����
* ��˴����½ǿ�ʼ���ң���Ҫ�������ֱ����½����ִ�ʱ������
* Ҫ�������ֱ����½�����Сʱ������
*/
class Solution {
public:
	bool Find(int target, vector<vector<int>> array) {
		/*��ά���������������*/
		int rowCount = array.size();
		int colCount = array[0].size();
		int i, j;//iָ���еı仯,jָ���еı仯

		//ѭ��
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