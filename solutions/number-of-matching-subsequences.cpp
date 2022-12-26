// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        
        // index pointers for every char 'a' to 'z'
		vector<vector<int>> v(26);
		for(int i=0;i<n;i++) {
            v[s[i]-'a'].push_back(i);
        }
            
		int res = 0;
		for(auto w:words) {
            // initial pointer in s
			int x = -1;
			bool found = true;

			for(char ch:w) {
                // search for index of that char which is just greater than x
				auto it = upper_bound(v[ch-'a'].begin(), v[ch-'a'].end(), x);
                
                // if not found then word dosen't exist
				if (it == v[ch-'a'].end()) found = false;
				else x = *it;
			}

			if(found) res++;
		}

		return res;
	}
};