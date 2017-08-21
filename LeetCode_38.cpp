/*
38.Count and Say

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
����˼�룺�ݹ�
          1 ���n=1��ֱ�ӷ���1
		  2 ������ȣ��ݹ����countAndSay(n-1)����temp��
		  3 ��temp������������һ��������count��result+count+temp[i]
		    ����һ����count++
		  4 ���շ���result

to_string�ܽ�intתΪstring
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

string countAndSay(int n)
{
	if (n == 1)
		return "1";
	else{
		string temp = countAndSay(n - 1);
		int count = 1;
		string result;
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == temp[i + 1])
			{
				count++;
				continue;
			}
			result = result + to_string(count) + temp[i];
			count = 1;
		}
		return result;
	}
}

int main()
{
	cout << countAndSay(5);
	while (1);
	return 0;
}

