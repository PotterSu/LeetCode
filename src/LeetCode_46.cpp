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

����˼·���õݹ����������dfs��
          ���ڸ�����nums������nλ����r��0��ʼ��n-1�ƶ���ʾ��ǰ��rλ����ȡ��Щ���ֵ������
		  ����Ȼr=0ʱ������ȡn������r=1ʱ����ȡn-1��������Ϊ��0λ�Ѿ�ȷ����ͨ��forѭ�����ֱ�r+1��n-1���������rλ���ֵ���
		  ��ô���˵�rλ�������ͨ��dfs(r+1,n,nums��result)�ݹ��ʾ����λ��ϵ������
		  һ��r��n-1��ȣ�˵���������һλ��ǰ�涼�Ѿ��źã�����ֱ�Ӵ洢nums��
		  Ȼ��ݹ鷴�����ֱ�����е�nums��������洢
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

