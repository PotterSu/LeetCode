/*
47. Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
[1,1,2],
[1,2,1],
[2,1,1]
]

����˼·������˼·��Permutations��ͬ��Ψһ��Ҫ���ǵ����ظ�������
          �õݹ����������dfs��
		  ���ȶ�nums��������
          ���ڸ�����nums������nλ����r��0��ʼ��n-1�ƶ���ʾ��ǰ��rλ����ȡ��Щ���ֵ������
		  ����Ȼr=0ʱ�����û���ظ���Ԫ�ؿ���ȡn������r=1ʱ����ȡn-1��������Ϊ��0λ�Ѿ�ȷ����ͨ��forѭ�����ֱ�i=r+1��n-1���������rλ���ֵ���
		  ע�⣺���һ������nums[i]==nums[r]��ֱ�������������е����������Ļ�������ظ����������
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
	dfs(r + 1, n, nums, result);
	for (int i = r + 1; i < n; i++)
	{
		if (nums[i] == nums[r])
			continue;
		int temp = nums[r];
		nums[r] = nums[i];
		nums[i] = temp;
		dfs(r + 1, n, nums, result);
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	dfs(0, nums.size(), nums, result);
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(1);
	vector<vector<int>> result = permuteUnique(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j];
	}
	while (1);
	return 0;
}

