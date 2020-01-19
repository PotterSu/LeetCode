/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
*/

#include "iostream"
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size() == 0)
            return 0;
        int low = 0;
        int high = rotateArray.size() - 1;
        int middle = (low + high) / 2;
        if(rotateArray[low] < rotateArray[high])
            return rotateArray[low];
        else
        {
            while(low < high)
            {
                middle = (low + high) / 2;
                if(rotateArray[middle] <= rotateArray[high])
                {
                    high = middle;
                }
                else if(rotateArray[middle] > rotateArray[high])
                {
                    low = middle + 1;
                }
            }
            return rotateArray[low];
        }
    }
};

int main()
{
    vector<int> rotateArray;
    rotateArray.push_back(3);
    rotateArray.push_back(4);
    rotateArray.push_back(5);
    rotateArray.push_back(1);
    rotateArray.push_back(2);

    Solution solution;
    int result = solution.minNumberInRotateArray(rotateArray);

    cout << result << endl;

	return 0;
}
