// https://leetcode.com/problems/number-of-different-integers-in-a-string

class Solution {
public:
    int numDifferentIntegers(string word) 
    {
        set<string> S;
    int i = 0, f = 0, n = word.length();
    while (i < n)
    {
        string t;
        while (i < n && word[i] == '0')
            i++;
        if(i==n)
        {
            if(i>=1 && word[i-1]=='0')
                f=1;
            break;
        }
        if (!(word[i] >= '0' && word[i] <= '9'))
        {
            if(i>=1 && word[i-1]=='0')
                f=1;
            i++;
            continue;
        }
        while (i < n && word[i] >= '0' && word[i] <= '9')
        {
            t.push_back(word[i]);
            i++;
        }
        S.insert(t);
        i++;
    }
    // out(S);
    return S.size() + f;
    }
};