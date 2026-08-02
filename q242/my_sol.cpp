/*
242. Valid Anagram      Easy

Given two strings s and t, return true if t is Anagram of s, and false otherwise.
An anagram is a word or phrase formed by rearranging the letters of a different word
or phrase, using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

 Constraints:
    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{

    void get_freq(string &s, unordered_map<char, int> &freq)
    {
        for (char &i : s)
            freq[i]++;
    }

public:
    bool isAnagram(string s, string t)
    {
        if (s.length()!=t.length())
        {
            return false;   
        }
        

        unordered_map<char, int> s_freq; //O(n)
        unordered_map<char, int> t_freq; //O(n)

        get_freq(s, s_freq);
        get_freq(t, t_freq);

        for (std::pair<const char, int> &i : s_freq) //O(n)
        {
            // does the letter even exist
            if (t_freq.contains(i.first))
            {
                // if it does the freq should be same
                if (i.second != t_freq.at(i.first))
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "aacc", t = "ccac";

    Solution sol;
    bool result = sol.isAnagram(s, t);

    char c = 'Ű';

    return 0;
}