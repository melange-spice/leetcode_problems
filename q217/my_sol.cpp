/*
217. Contains Duplicate     Easy

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true
Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false
Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
    1 <= nums.length <= 105
    -109 <= nums[i] <= 109
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int &i : nums)
        {
            freq[i]++;
            if (freq[i] > 1)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> nums= {1,2,3,1};

    Solution s;
    bool t = s.containsDuplicate(nums);

    
    return 0;
}