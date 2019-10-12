/*
89. Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

����˼·��������ָ��������ֻ��һλ��ͬ
          ���ڸ���n=3���ܹ���8����ͬ�ĸ����룬���ڵ�i�����������ͨ��i^i>>1��á�
		  �磺��n=3ʱ��������������Ϊ011^001->010��Ҳ����2
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

vector<int> grayCode(int n) {
	vector<int> result;
	for (int i = 0; i < pow(2, n); i++)
	{
		result.push_back(i^i >> 1);
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	vector<int> result = grayCode(n);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
	return 0;
}

