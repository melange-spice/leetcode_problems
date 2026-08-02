#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;

        vector<int> tmp;
        int i = 0, j = 0;
        if (n1 == 0)
        {
            // I blindy do: 
            // merged.push_back(nums2[0]);
            // nums2.erase(nums2.begin());
            //              ^^
            //              ||
            //this shit is fcked up the whole vector has to shift left the whole vector
            //each time erase wanks out the 0th element of a vector

            if (n2 % 2 != 0)
            {
                return double(nums2[n2 / 2]);
            }
            else
            {
                return double((double)(nums2[n2 / 2] + nums2[n2 / 2 - 1]) / 2.0);
            }
        }
        if (n2 == 0)
        {
            if (n1 % 2 != 0)
            {
                return double(nums1[n1 / 2]);
            }
            else
            {
                return double((double)(nums1[n1 / 2] + nums1[n1 / 2 - 1]) / 2.0);
            }
        }
        
        //constructing the merged array until:
        //1) one of the arrays becomes empty 
        //OR
        //2) both arrays become empty

        while ((i < n1) && (j < n2))
        {
            if (nums1[i] < nums2[j])
            {
                tmp.push_back(nums1[i]);
                i++;
            }
            else
            {
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        //dealing with the 1 remaining array if there is any left
        while (i < n1)
        {
            tmp.push_back(nums1[i]);
            i++;
        }
        while (j < n2)
        {
            tmp.push_back(nums2[j]);
            j++;
        }

        if (n % 2 != 0)
        {
            return double(tmp[n / 2]);
        }
        else
        {
            return double((double)(tmp[n / 2] + tmp[n / 2 - 1]) / 2.0);
        }
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