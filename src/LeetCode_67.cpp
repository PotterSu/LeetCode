/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

解题思路：用i,j表示a,b的位置，i,j分别从a,b的最后一位依次相加，和与2取余作为当前位的结果，和与2做除作为进位
          直到i,j有一个小于0，说明a或b加完
		  对于a或b剩下的部分与之前的进位temp相加，直到a或b剩下的部分全部加完
		  如果最后的进位temp不为0，还需要再在首部添加个temp位

注意a,b为string,需要将他们每一位转成int才能相加
利用栈stack来保证结果的正序
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

string addBinary(string a, string b) {
	int i = a.length() - 1;
	int j = b.length() - 1;
	int temp = 0;
	stack<int> s;
	while (i >= 0 && j >= 0)
	{
		int total = (int)(a[i] - '0') + (int)(b[j] - '0') + temp;
		int left = total % 2;
		temp = total / 2;
		s.push(left);
		i--;
		j--;
	}

	while (i >= 0)
	{
		int total = (int)(a[i] - '0') + temp;
		int left = total % 2;
		temp = total / 2;
		s.push(left);
		i--;
	}
	while (j >= 0)
	{
		int total = (int)(b[j] - '0') + temp;
		int left = total % 2;
		temp = total / 2;
		s.push(left);
		j--;
	}

	if (temp > 0)
	{
		s.push(temp);
	}
	string c;
	while (!s.empty())
	{
		c += to_string(s.top());
		s.pop();
	}
	return c;
}

int main()
{
	string a = "11";
	string b = "111";
	string c = addBinary(a, b);
	cout << c << endl;
	while (1);
	return 0;
}
