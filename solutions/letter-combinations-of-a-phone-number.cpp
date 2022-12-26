// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(digits.size()==0)
            return res;
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        
        // for each number take each char in respected string and
        // append to every subresult stroed in res and then swap
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> tempres;
            string chars = charmap[digits[i] - '0'];
            for (int c = 0; c < chars.size();c++)
            {
                for (int j = 0; j < res.size();j++)
                {
                    tempres.push_back(res[j]+chars[c]);
                }
            }
            res.swap(tempres);
        }
        return res;
    }
};