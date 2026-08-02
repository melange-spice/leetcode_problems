#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        result.push_back(i);
                        result.push_back(j);
                        return result;
                    }
                }
            }
        }
    }
};

int main()
{
    Solution s;

    vector<int> arr = {2, 7, 11, 15};

    vector<int> r = s.twoSum(arr, 9);

    for (int &i : r)
    {
        cout << i << endl;
    }

    system("pause");
    return 0;
}