/*
67. Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

����˼·����i,j��ʾa,b��λ�ã�i,j�ֱ��a,b�����һλ������ӣ�����2ȡ����Ϊ��ǰλ�Ľ��������2������Ϊ��λ
          ֱ��i,j��һ��С��0��˵��a��b����
		  ����a��bʣ�µĲ�����֮ǰ�Ľ�λtemp��ӣ�ֱ��a��bʣ�µĲ���ȫ������
		  ������Ľ�λtemp��Ϊ0������Ҫ�����ײ���Ӹ�tempλ

ע��a,bΪstring,��Ҫ������ÿһλת��int�������
����ջstack����֤���������
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
