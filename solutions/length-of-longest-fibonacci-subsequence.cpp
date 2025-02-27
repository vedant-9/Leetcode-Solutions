class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // array is sorted
        set<int> st;
        for(auto x: arr) st.insert(x);

        int res = 0, n = arr.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int first = arr[i], second = arr[j], len = 2;
                while(st.find(first + second) != st.end()) {
                    second = first + second;
                    first = second - first;
                    len++;
                }
                if(len > 2)
                    res = max(res, len);
            }
        }

        return res;
    }
};
