/*
46. Permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]

解题思路：用递归回溯来做（dfs）
          对于给定的nums向量有n位数，r从0开始向n-1移动表示当前第r位可以取哪些数字的情况，
		  （显然r=0时，可以取n个数，r=1时可以取n-1个数，因为第0位已经确定）通过for循环，分别将r+1到n-1的数字与第r位数字调换
		  那么有了第r位的情况，通过dfs(r+1,n,nums，result)递归表示后续位组合的情况，
		  一旦r与n-1相等，说明到了最后一位，前面都已经排好，可以直接存储nums。
		  然后递归反向回溯直至所有的nums情况都被存储
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void dfs(int r, int n, vector<int> nums, vector<vector<int>> &result)
{
	if (r == n - 1)
	{
		result.push_back(nums);
		return;
	}
	for (int i = r; i < n; i++)//1 2 3
	{
		int temp = nums[r];
		nums[r] = nums[i];
		nums[i] = temp;
		for (int j = 0; j < nums.size(); j++)
			cout << nums[j] << " ";
		dfs(r + 1, n, nums, result);
	}

}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> result;
	dfs(0, nums.size(), nums, result);
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> result = permute(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
	}
	while (1);
	return 0;
}

