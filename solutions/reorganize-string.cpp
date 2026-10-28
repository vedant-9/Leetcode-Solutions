class Solution {
public:
    string reorganizeString(string s) {
        map<char, int> mp;
        for(auto ch: s) mp[ch]++;
        sort(s.begin(), s.end(), [&](auto x, auto y){
            if (mp[x] != mp[y]) return mp[x] > mp[y];
            return x < y;
        }); 
        // cout << s ;
        int n = s.size();
        string res(n, '.');
        int j = 0;
        for (int i = 0; i < n; i += 2)
            res[i] = s[j++];
        for (int i = 1; i < n; i += 2)
            res[i] = s[j++];
        for (int i = 0; i < n - 1; i++) {
            if (res[i] == res[i + 1])
                return "";
        }
        return res;
    }
};
