// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity

class Solution {
public:
    int largestInteger(int n) {
        string s = to_string(n);
        vector<int> odd,even;
        for(int i=0;i<s.length();i++) {
            if((s[i]-'0')%2==0) even.push_back(s[i]-'0');
            else odd.push_back(s[i]-'0');
        }
        sort(even.rbegin(),even.rend());
        sort(odd.rbegin(),odd.rend());
        int j=0,k=0;
        for(int i=0;i<s.length();i++) {
            if((s[i]-'0')%2==0) s[i]=(char)(even[j++]+'0');
            else s[i]=(char)(odd[k++]+'0');
        }
        return stoi(s);
    }
};