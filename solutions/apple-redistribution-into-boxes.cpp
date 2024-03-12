class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(auto x: apple) sum += x;
        sort(capacity.rbegin(), capacity.rend());
        int i = 0;
        while(i < capacity.size() and sum > 0) {
            sum -= capacity[i];
            i++;
        }
        if(sum <= 0) return i;
        return -1;
    }
};
