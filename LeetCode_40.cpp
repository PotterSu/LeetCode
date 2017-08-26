/*
40. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
����˼�룺�������39��һ�����ݹ���ݣ�Ψһ��֮ͬ������ͬһ���ֲ����ظ�ʹ�ã�����candidates�п��ܳ����ظ����֣�����Ҫ�жϱ����ظ�������
          ���ȶ�candidates����
          ��r��¼��ǰλcandidates��������λ�ã�����ѭ��i=r��candidates.size()�����i!=r����candidates[i]��candidates[i-1]��ȣ���ֱ��continue�����������ظ�
		  һ������֮ǰtemp��¼���ܺ�sum+candidates[i]��target��ȣ���temp����result�У�return
		  ���sum<target����candidates[i]����temp�У������ݹ�dfs(i+1, candidates.size(), candidates, sum, target, result, temp);
		  temp.pop_back()��������Ϊ��ǰλ��������ѱ����꣬��Ҫ����ǰλ������Ϊѹ���һλ
		  ���sum>target,ֱ��return
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void dfs(int r, vector<int> candidates, int sum, int target, vector<vector<int>> &result, vector<int> temp)
{
	//111335
	for (int i = r; i < candidates.size(); i++)
	{
		if (i != r&&candidates[i] == candidates[i - 1])
			continue;
		sum = sum + candidates[i];
		if (sum == target)
		{
			temp.push_back(candidates[i]);
			result.push_back(temp);
			return;
		}
		if (sum < target)
		{
			temp.push_back(candidates[i]);
			dfs(i + 1, candidates, sum, target, result, temp);
			temp.pop_back();
			sum = sum - candidates[i];
		}
		if (sum > target)
		{
			return;
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> temp;
	int sum = 0;
	dfs(0, candidates, sum, target, result, temp);
	return result;

}

int main()
{
	vector<int> candidates;
	candidates.push_back(3);
	candidates.push_back(1);
	candidates.push_back(3);
	candidates.push_back(5);
	candidates.push_back(1);
	candidates.push_back(1);
	int target = 8;

	vector<vector<int>> result = combinationSum2(candidates, target);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
	}
	while (1);
	return 0;
}
