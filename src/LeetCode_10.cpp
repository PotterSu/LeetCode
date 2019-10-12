/*
10.Regular Expression Matching

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") �� false
isMatch("aa","aa") �� true
isMatch("aaa","aa") �� false
isMatch("aa", "a*") �� true
isMatch("aa", ".*") �� true
isMatch("ab", ".*") �� true
isMatch("aab", "c*a*b") �� true

����˼·����dp���⣬dp[i][j]��ʾs��ǰi���ַ����Ƿ���p��ǰj���ַ���ƥ��
          ����sΪ�գ�ֻ���ж�p�Ƿ�Ϊ*���ɣ�������Ϊ*,���ùܣ�����Ϊ*dp[0][i] = dp[0][i-2]
		  ����s��Ϊ�գ�����p[j]Ϊ.������s[i]���ȣ�˵����ǰλһ�£�ֻ�迴dp[i-1][j-1]����
		               ����p[j]Ϊ*������������
					   1.p[j-1]!=s[i]����p[j-1]!='.'����ôֻ��Ҫ�ж�p��ǰj-2λ�Ƿ���s��ǰiλƥ�伴�ɣ���ʱ*Ϊ0
					   2.p[j-1]==s[i]����p[j-1]=='.'����ô��Ҫ��p��ǰj-2λ�Ƿ���s��ǰiλ����
													  ����p��ǰj-1λ�Ƿ���s��ǰiλ���Ȼ���
													  ����p��ǰjλ�Ƿ���s��ǰi-1λƥ��
          ���շ���dp[sl][pl]
*/

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include "stack"

using namespace std;

bool isMatch(string s, string p) {
	int sl = s.length();
	int pl = p.length();
	vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= pl; i++)
	{
		if (p[i - 1] == '*')
		{
			dp[0][i] = dp[0][i - 2 >= 0 ? i - 2 : 0];
		}
	}
	for (int i = 1; i <= sl; i++)
	{
		for (int j = 1; j <= pl; j++)
		{
			if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			if (p[j - 1] == '*')
			{
				if (p[j - 2 >= 0 ? j - 2 : 0] != s[i - 1] && p[j - 2 >= 0 ? j - 2 : 0] != '.')
					dp[i][j] = dp[i][j - 2 >= 0 ? j - 2 : 0];
				else{
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2 >= 0 ? j - 2 : 0];
				}
			}

		}

	}
	return dp[sl][pl];
}

int main()
{
	string s = "aaaaa";
	string p = "*";
	bool temp = isMatch(s, p);
	cout << temp << endl;
	while (1);
	return 0;
}
