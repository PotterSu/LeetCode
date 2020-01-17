/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include "iostream"
#include <vector>

using namespace std;

void replaceSpace(char *str,int length)
{
    //计算原始字符串长度
    int nOriLength = 0;
    while(str[nOriLength] != '\0')
    {
        nOriLength++;
    }
    if(nOriLength + 1 > length)
        return;

    int nSpaceLength = 0;
    for(int i = 0; i < nOriLength; i++)
    {
        if(str[i] == ' ')
            nSpaceLength++;
    }
    int nNewLength = nOriLength + nSpaceLength * 2;
    int curIndex = nNewLength;
    for(int oriIndex = nOriLength; oriIndex >= 0; oriIndex--)
    {
        if(str[oriIndex] == ' ')
        {
            str[curIndex--] = '0';
            str[curIndex--] = '2';
            str[curIndex--] = '%';
        }
        else
        {
            str[curIndex--] = str[oriIndex];
        }
    }
}

int main()
{
    char str[20] = " We are Happy";
	replaceSpace(str, 20);
	cout << str << endl;

	return 0;
}
