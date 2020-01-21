/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
*/

#include "iostream"
#include <vector>

using namespace std;

//1,2,3,2,2,2,5,4,2
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if(numbers.size() == 0)
		return 0;
	sort(numbers.begin(), numbers.end());
	int count = 0;
	for(int i = 0; i < numbers.size(); i++)
	{
		if(i > 0 && numbers[i] == numbers[i - 1])
		{
			count++;
		}
		else
		{
			count = 1;
		}
		if(count > numbers.size() / 2)
		{
			return numbers[i];
		}
	}
	return 0;
}

int main()
{
	vector<int> numbers = {3,2,3,2,3,6,3,4,3};
	int result = MoreThanHalfNum_Solution(numbers);
	cout << result << endl;

	return 0;
}
