/*
66. Plus One

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

解题思路：设置一个carry变量用来存储进位，从后往前遍历
          一旦当前位digits[i]+carry>=10，更新carry = digits[i]+carry/10，并且更新当前位digits[i]=(digits[i]+carry)%10
		  用栈st存储当前digits[i]
          遍历完后如果carry>0，st.push(carry)
		  通过栈的pop恢复和的顺序

要考虑连续进位以及用栈来逆序的问题
*/

#include "iostream"
#include "string"
#include "Algorithm"
#include "vector"
#include "stack"

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int carry = 0;
	vector<int> result;
	stack<int> st;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		int total = digits[i] + carry;
		if (i == (digits.size() - 1))
		{
			total += 1;
		}
		if (total >= 10)
		{
			carry = total / 10;
			digits[i] = total % 10;
		}
		else{
			carry = 0;
			digits[i] = total;
		}
		st.push(digits[i]);
	}
	if (carry != 0)
	{
		st.push(carry);
	}
	while (!st.empty())
	{
		result.push_back(st.top());
		st.pop();
	}
	return result;
}


int main()
{
	vector<int> digits;
	digits.push_back(1);
	digits.push_back(2);
	digits.push_back(3);
	vector<int> result = plusOne(digits);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}
	while (1);
	return 0;
}

