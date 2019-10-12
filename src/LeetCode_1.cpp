/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 */

#include "iostream"
#include "vector"
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    map<int, int> hash_map;
    // //第一次遍历，存储所有的数
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     hash_map.insert(map<int, int>::value_type(nums[i], i));
    // }
    // //第二次遍历，查找
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     int another = target - nums[i];
    //     if(hash_map.count(another) > 0 && i != hash_map[another])
    //     {
    //         result.push_back(i);
    //         result.push_back(hash_map[another]);
    //         return result;
    //     }
    // }
    for(int i = 0; i < nums.size(); i++)
    {
        hash_map.insert(make_pair(nums[i], i));
        int another = target - nums[i];
        if(hash_map.count(another) && i != hash_map[another])
        {
            result.push_back(i);
            result.push_back(hash_map[another]);
            return result;
        }
    }

    return result;
}

int main()
{
	int numRows;

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;

    vector<int> result = twoSum(nums, target);

    for(int i = 0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }

	return 0;
}
