// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words

class Solution {
public:
    bool isSumEqual(string s1, string s2, string s3) 
    {
        string num1,num2,num3;
        for(int i=0;i<s1.length();i++)
        {
            num1 += (char)(s1[i]-'a'+'0');
        }
        for(int i=0;i<s2.length();i++)
        {
            num2 += (char)(s2[i]-'a'+'0');
        }
        for(int i=0;i<s3.length();i++)
        {
            num3 += (char)(s3[i]-'a'+'0');
        }
        return (stoi(num1)+stoi(num2)==stoi(num3));
    }
};