/*4. Median of Two Sorted Arrays
Hard

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).


Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.



Constraints:
    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106
*/
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int combined = nums1.size() + nums2.size();
        if (combined == 0)
        {
            return 0;
        }

        vector<double> merged;
        if (nums1.empty() == true)
        {
            if (nums2.empty() == false)
            {
                merged.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }

            goto tag;
        }
        else if (nums2.empty() == true)
        {
            if (nums1.empty() == false)
            {
                merged.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }

            goto tag;
        }

        // smallest first element of the two arrays
        if (nums1[0] < nums2[0])
        {
            merged.push_back(nums1[0]);
            nums1.erase(nums1.begin());
        }
        else
        {
            merged.push_back(nums2[0]);
            nums2.erase(nums2.begin());
        }

    tag:
        int difference1 = 0, difference2 = 0;
        for (int i = 0; i < combined / 2; i++)
        {

            if (nums1.empty() == false)
            {
                difference1 = nums1[0] - merged.back();
            }

            if (nums2.empty() == false)
            {
                difference2 = nums2[0] - merged.back();
            }

            if (nums2.empty() == false && nums1.empty() == false)
            {
                // smallest number goes to merged
                if (difference1 < difference2)
                {
                    merged.push_back(nums1[0]);
                    nums1.erase(nums1.begin());
                }
                else
                {
                    merged.push_back(nums2[0]);
                    nums2.erase(nums2.begin());
                }
            }
            else if (nums1.empty() == false)
            {
                merged.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else if (nums2.empty() == false)
            {
                merged.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }

        double median = 0.0;

        if (combined % 2 == 0)
        {
            median = merged.back();
            merged.pop_back();
            median += merged.back();

            median /= 2.0;

            return median;
        }

        median = merged.back();
        return median;
    }
};

int main()
{
    vector<int> nums1{1, 3};
    vector<int> nums2{2};

    Solution s;

    double d = s.findMedianSortedArrays(nums1, nums2);

    system("pause");
    return 0;
}