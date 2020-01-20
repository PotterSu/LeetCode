/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

#include "iostream"
#include <vector>

using namespace std;

//3, 4, 9, 5, 12, 11, 10
bool Verify(int left, int right, vector<int> s)
{
	bool status = true;
	if(left >= right)
		return status;
	int root = s[right];
	int leftEnd = left;
	while(leftEnd < right)
	{
		if(s[leftEnd] < root)
		 	leftEnd++;
		else
			break;
	}
	int rightEnd = leftEnd;
	while(rightEnd < right)
	{
		if(s[rightEnd] > root)
		{
			rightEnd++;
		}
		else
		{
			status = false;
			return status;
		}
	}

	bool leftstatus = Verify(left, leftEnd - 1, s);
	bool rightstatus = Verify(leftEnd, rightEnd - 1, s);
	status = status && leftstatus && rightstatus;
	return status;
}

bool VerifySquenceOfBST(vector<int> sequence)
{
	if(sequence.size() == 0)
		return false;
	bool status = Verify(0, sequence.size() - 1, sequence);
	return status;
}

int main()
{
	vector<int> sequence(7);
	sequence = {3, 4, 9, 5, 12, 11, 10};
	bool result = VerifySquenceOfBST(sequence);
	cout << result << endl;

	return 0;
}
