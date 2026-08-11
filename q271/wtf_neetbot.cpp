/*
question 271 Encode and Decode Strings      Medium

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:
    String encode(List<String> strs) {
        // ... your code
        return encoded_string;
    }

Machine 2 (receiver) has the function:
    List<String> decode(String encoded_string) {
        // ... your code
        return decoded_strs;
    }

So Machine 1 does:
String encoded_string = encode(strs);

and Machine 2 does:
List<String> decoded_strs = decode(encoded_string);

decoded_strs in Machine 2 should be the same as the input strs in Machine 1.

Implement the encode and decode methods.

Example 1:
Input: strs = ["Hello","World"]
Output: ["Hello","World"]

Explanation:
Solution solution = new Solution();
String encoded_string = solution.encode(strs);

// Machine 1 ---encoded_string---> Machine 2

List<String> decoded_strs = solution.decode(encoded_string);

Example 2:
Input: strs = [""]
Output: [""]

Constraints:

    0 <= strs.length < 100
    0 <= strs[i].length < 200
    strs[i] contains any possible characters out of 256 valid ASCII characters.

Follow up: Could you write a generalized algorithm to work on any possible set of characters?
*/
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

class Solution
{

    // convert to integer,
    // with "," delimiter between chars
    //  and ",|" delimieter  between two strings in the vector

    string convert_word(const string &inp)
    {

        string encoded;

        for (const char &i : inp)
        { // use unsigned char to handle 256 ASCII correctly
            int value = static_cast<int>(i);

            encoded.append(to_string(value));
            encoded.push_back(',');
        }
        encoded.push_back('|');
        return encoded; // move semantics should prevent a copy being made here
    }

    // extracts a single token from inp and pop it from inp. That is extract code of a single string
    // e.g From 72,101,124,108,108,111,|124,|87,111,114,108,100,| we extract 72,101,124,108,108,111,|
    string extract_token(string &inp)
    {

        string token;

        while (inp.size() > 0)
        { // Look for the sequence ",|" or just "|" for empty strings
            if (inp[0] == '|') {
                token.push_back('|');
                inp.erase(0, 1);
                break;
            }
            
            size_t pos = inp.find(",|");
            if (pos != string::npos) {
                token = inp.substr(0, pos + 2);
                inp.erase(0, pos + 2);
                break;
            }
            break;
        }
        return token;
    }

    // decode the token of the form 72,101,124,108,108,111,| to "He|llo"
    string decode_token(string inp)
    {
        if (inp == "|") return "";
        string encoded_word;
        string result;

        for (int i = 0; i < inp.length(); ++i)
        {
            if (isdigit(inp[i]))
            {
                encoded_word.push_back(inp[i]);
            }
            else if (inp[i] == ',' && i + 1 < inp.length() && inp[i+1] == '|')
            {
                if (!encoded_word.empty()) {
                    result.push_back(static_cast<char>(stoi(encoded_word)));
                }
                break;
            }
            else if (inp[i] == ',')
            {
                result.push_back(static_cast<char>(stoi(encoded_word)));
                encoded_word.clear();
            }
        }
        return result;
    }

public:
    string encode(vector<string> &strs)
    {
        if (strs.empty()) return "";
        string result;

        for (const string &s : strs)
        {
            result.append(convert_word(s));
        }

        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        if (s.empty()) return result;
    
        while (!s.empty())
        {
            string encoded_token = extract_token(s);
            string word = decode_token(encoded_token);
            result.push_back(word);
        }
        return result;
    }
};

int main()
{

    Solution s;

    vector<string> strings = {"Hello","World"};
    //vector<string> strings = {""};

 // Measures and displays an execution time of a function call.
    const auto start{std::chrono::steady_clock::now()};
    

    string en = s.encode(strings);
    vector<string> r = s.decode(en);

    const auto finish{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{finish - start};

    for(const string& s: r){

        cout<<s<<endl;
    }

    std::cout <<"\nElapsed time: "<<elapsed_seconds<<endl;
    

    

    system("pause");
    return 0;
}