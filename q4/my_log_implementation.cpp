/*
This is my implementation of the O(log(m+n)) solution described in the editorial of this problem:

Let's define a function that helps us find the kth smallest element from two inclusive ranges [a_start, a_end] and [b_start, b_end] from arrays A and B.

    If the range (for example, a range of A) is empty, in other words a_start > a_end, it means all elements in A are passed, we just return the (k - a_start)-th element from the other array B. Vice versa if b_start > b_end.

    Otherwise, get the middle indexes of the two ranges: a_index = (a_start + a_end) / 2, b_index = (b_start + b_end) / 2.

    Get the middle values of the two ranges: a_value = A[a_index], b_value = B[b_index].

    Cut one array in half, according to:
        If a_index + b_index < k, cut one smaller half.
            If a_value < b_value, cut the smaller half of A.
            Otherwise, cut the smaller half of B.
        Otherwise, cut one larger half.
            If b_value < a_value, cut the larger half of B.
            Otherwise, cut the larger half of A.

--------------------------------------------------------------------------------------------------
4. Median of Two Sorted Arrays
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
#include <iostream>
using namespace std;

class Solution
{
public:
    // given single arr return the median
    double median(vector<int> &arr);

    // return median given the range from the arr
    double median(int start, int end, vector<int> &arr, int k);

    double find_kth_element(int k, vector<int> &nums1, vector<int> &nums2);

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // edge cases if one of the array is empty
        if (nums1.empty() && !nums2.empty())
        {
            return median(nums2);
        }
        else if (nums2.empty() && !nums1.empty())
        {
            return median(nums1);
        }

        // both arrays are not empty
        //--------------------------------------------------------------------------
        int a_start = 0;
        int a_end = nums1.size() - 1;
        int b_start = 0;
        int b_end = nums2.size() - 1;

        // A+B length
        int a_b_length = (a_start + a_end + b_start + b_end + 2);

        int k = (a_b_length / 2) + 1;

        if (a_b_length % 2 == 0)
        {
            double x1 = find_kth_element(k, nums1, nums2);
            double x2 = find_kth_element(k - 1, nums1, nums2);

            return (x1 + x2) / 2.0;
        }

        return find_kth_element(k, nums1, nums2);
    }
};

double Solution::find_kth_element(int k, vector<int> &nums1, vector<int> &nums2)
{
    int a_start = 0;
    int a_end = nums1.size() - 1;
    int b_start = 0;
    int b_end = nums2.size() - 1;

    int a_mid = (a_start + a_end) / 2;
    int b_mid = (b_start + b_end) / 2;

    // A+B length
    int a_b_length = (a_start + a_end + b_start + b_end + 2);

    while (true)
    {
        a_b_length = (a_end + 1 - a_start) + (b_end + 1 - b_start);

        // cut one of the smaller halves of the A+B array
        if (k > a_b_length / 2)
        {

            // nums1 is the smaller array
            if (nums1[a_mid] < nums2[b_mid])
            {
                // cut off a_left
                // array has only 2 elements
                if (a_end - a_start == 1)
                {
                    k--;
                    a_start = a_end;
                }
                // array has only 1 element
                else if (a_end == a_start)
                {
                    k--;
                    // only remaining array is b
                    return median(b_start, b_end, nums2, k);
                }
                // arary has more than 2 elements
                else
                {
                    k = k - (a_mid - a_start);
                    a_start = a_mid;
                }

                a_mid = (a_start + a_end) / 2;
            }
            else
            {
                // cut off b_left
                // array has only 2 elements
                if (b_end - b_start == 1)
                {
                    k--;
                    b_start = b_end;
                }
                // array has only 1 element
                else if (b_end == b_start)
                {
                    k--;
                    // only remaining array is a
                    return median(a_start, a_end, nums1, k);
                }
                // arary has more than 2 elements
                else
                {
                    k = k - (b_mid - b_start);
                    b_start = b_mid;
                }

                b_mid = (b_start + b_end) / 2;
            }
        }
        else // cut one of the larger halves of the A+B array
        {
            // nums1 is the smaller array
            if (nums1[a_mid] < nums2[b_mid])
            {
                // cut off b_right
                // array has only 2 elements
                if (b_end - b_start == 1)
                {
                    b_end = b_start;
                }
                // array has only 1 element
                else if (b_end == b_start)
                {
                    // only remaining array is a
                    return median(a_start, a_end, nums1, k);
                }
                // arary has more than 2 elements
                else
                {
                    b_end = b_mid;
                }

                b_mid = (b_start + b_end) / 2;
            }
            else // nums2 is the smaller array
            {
                // cut off a_right
                // array has only 2 elements
                if (a_end - a_start == 1)
                {
                    a_end = a_start;
                }
                // array has only 1 element
                else if (a_end == a_start)
                {
                    // only remaining array is b
                    return median(b_start, b_end, nums2, k);
                }
                // arary has more than 2 elements
                else
                {
                    a_end = a_mid;
                }

                a_mid = (a_start + a_end) / 2;
            }
        }
    }
}
double Solution::median(int start, int end, vector<int> &arr, int k)
{
    return arr[(k-1) + start];
}

double Solution::median(vector<int> &arr)
{
    int s = arr.size();
    if (s % 2 == 0)
    {
        int prev = arr[(s / 2) - 1];

        return (prev + arr[s / 2]) / 2.0;
    }

    return arr[s / 2];
}

int main()
{
    // vector<int> nums1{1,2,3,4,5};
    // vector<int> nums2{6,7,8,9,10,11,12,13,14,15,16,17};

    vector<int> nums1{0,0,0,0,0};
vector<int> nums2{-1,0,0,0,0,0,1};

    

    Solution s;

    double d = s.findMedianSortedArrays(nums1, nums2);
    cout << d << endl;
    system("pause");
    return 0;
}