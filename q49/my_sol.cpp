/* 49. Group Anagrams    Medium

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
    There is no string in strs that can be rearranged to form "bat".
    The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.

*/
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
    // convert the 26 to a unique string
    string convert(int *freq)
    {

        string s;
        for (int i = 0; i < 26; i++)
        {
            s.append(to_string(freq[i]));
            s.append(",");
        }

        return s;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        string freq_str;

        for (string &s : strs)
        {
            // count the freq
            int freq[26] = {};
            for (char &c : s)
            {
                freq[static_cast<int>(c) - static_cast<int>('a')]++;
            }

            freq_str = convert(freq);
            map[freq_str]; // if not present make the bucket
            map[freq_str].push_back(s);
        }
        vector<vector<string>> result;

        for (auto &bucket : map)
        {
            result.push_back(bucket.second);
        }

        return result;
    }
};

int main()
{
    // vector<string> strs;

    // strs.push_back("bdddddddddd");
    // strs.push_back("bbbbbbbbbbc");

    // Solution s;

    // vector<vector<string>> result;
    // result = s.groupAnagrams(strs);

    string freq_str;

    freq_str = "wow";

    freq_str = "asdsad";

    // for (auto i : result)
    // {

    //     for (auto &j : i)
    //     {
    //         cout << j << endl;
    //     }
    //     cout << "----------------\n";
    // }

    system("pause");
    return 0;
}