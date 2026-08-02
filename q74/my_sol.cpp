/*
74. Search a 2D Matrix      Medium

You are given an m x n integer matrix matrix with the following two properties:
    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.


Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


Constraints:
    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
*/
#include <vector>
using namespace std;

class Solution
{
public:
    // given a linear index return the value from the 2d matrix
    int get_value(int index, vector<vector<int>> &matrix)
    {
        int num_cols = matrix[0].size();

        int row = index / num_cols;
        int col = index % num_cols;

        return matrix[row][col];
    }

    bool binary_search(vector<vector<int>> &matrix, int target)
    {
        int size = matrix.size() * matrix[0].size();

        int low = 0;
        int high = size - 1;
        int mid = (low + high) / 2;

        while (true)
        {

            mid = (low + high) / 2;
            int mid_value = get_value(mid, matrix);

            if (mid_value == target|| get_value(low,matrix)==target||get_value(high,matrix)==target)
            {
                return true;
            }
            else if (high == low || high == mid ||low == mid )
            {
                return false;
            }

            if (mid_value < target)
            {
                low = mid + 1;
            }
            else if (mid_value > target)
            {
                high = mid - 1;
            }
        }
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        return binary_search(matrix, target);
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

    Solution s;
    bool d = s.searchMatrix(matrix,3);

    return 0;
}