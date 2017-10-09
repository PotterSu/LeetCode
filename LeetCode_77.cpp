/*
77. Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]

����˼·���ݹ����
	      ��position��¼��ǰ���kλ�еĵڼ�λ����ô��λ��ൽn�����еĵ�n - k + position��λ�ã������޷������ݹ顣��position=1,��ô��ൽ3�������4���鲻��2λ��
		  ��һ��temp��������ӵ�ǰpositionλ,Ȼ��backtrace����һ��position,�������
		  ���position����k+1�ˣ�˵������һ��������������temp��ӵ����ս��result�У���֮����backtrace
		  ֱ���������е����

	ע�⣺ÿ�η��ظ��µ�ǰpostionλʱ����Ҫ��temp��һ��ѹ��ĵ�ǰpostionλ���е�����Ҫ��������
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

void backtrace(vector<vector<int>> &result, vector<int> temp, int jj, int position, int n, int k)
{
	if (position == k + 1)
	{
		result.push_back(temp);
		return;
	}

	for (int j = jj; j <= n - k + position; j++)
	{
		temp.push_back(j);
		backtrace(result, temp, j + 1, position + 1, n, k);
		temp.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> result;
	if (n < k)
	{
		return result;
	}
	vector<int> temp;
	for (int i = 1; i <= n - k + 1; i++)
	{
		temp.push_back(i);
		backtrace(result, temp, i + 1, 2, n, k);
		temp.pop_back();
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<vector<int>> result = combine(n, k);
	for (int i = 0; i < result.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
	}
	while (1);
	return 0;
}

