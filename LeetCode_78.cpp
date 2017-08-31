/*
78. Subsets
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]

����˼·���ݹ����
	      traceÿ��ݹ�����룬��ϵ�Ԫ�ظ���Ҳ������
		  ��nums����λ��ʼ���������һλ����¼��ǰλΪi����ô��iΪͷ�����һ����trace(i+1)��ͬ���
		  ���ڵ�ǰtrace�ݹ�㣬֮ǰ��iλ����Ѿ�ȷ��������ѹ��result�У�
		  ��ô����ֻ��Ҫȷ����i+1λ��ʲô����forѭ����i+1������nums.size()���ÿһλ������ѡ��ѡ�����ѡ��ĳλ��pathѹ���λ��trace(i+1)
		  ��trace(i+1)������˵����ǰλ��ѡ����ôpath������λ��ѹ��forѭ������һλ
		  ��˷��������������е����
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void trace(int position, vector<vector<int>> &result, vector<int> nums, vector<int> path)
{
	result.push_back(path);
	for (int i = position; i < nums.size(); i++)
	{
		path.push_back(nums[i]);
		trace(i + 1, result, nums, path);
		path.pop_back();
	}
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> result;
	vector<int> path;
	trace(0, result, nums, path);
	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> result = subsets(nums);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
	}
	while (1);
	return 0;
}

