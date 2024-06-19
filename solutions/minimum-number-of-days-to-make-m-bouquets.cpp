class Solution {
public:
    // binary search on answer(days)
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            int c = 0;
            while(i < bloomDay.size() and c < k and bloomDay[i] <= day) {
                c++;
                i++;
            }
            
            if(c == k) cnt++, i--;
        }
        return (cnt >= m);
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long) m * k > bloomDay.size()) return -1;
        
        int low = 1, high = 1e9;
        while(low < high) {
            int mid = low + (high-low)/2;
            
            if(canMakeBouquets(bloomDay, m, k, mid)) 
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};
