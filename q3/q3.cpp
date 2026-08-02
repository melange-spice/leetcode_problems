/*
3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest without duplicate characters.


Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s == "")
        {
            return 0;
        }

        vector<int> substring_lengths;

        for (int i = 0; i < s.size() ; i++)
        {
            string current_substring{s[i]};

            for (int j = i + 1; j < s.size(); j++)
            {
                int index = current_substring.find(s[j]);

                // found a duplicate
                if (index != current_substring.npos)
                {
                    break;
                }
                else
                {
                    current_substring.push_back(s[j]);
                }
            }
            int current_sub_len = current_substring.size();
            substring_lengths.push_back(current_sub_len);
        }

        // find the longest substring length
        int longest = substring_lengths.back();
        substring_lengths.pop_back();

        for (int &i : substring_lengths)
        {
            if (i > longest)
            {
                longest = i;
            }
        }

        return longest;
    }
};

int main()
{
    string s = "wsslpluuwekuaxt";

    Solution g;

    g.lengthOfLongestSubstring(s);

    system("pause");
    return 0;
}