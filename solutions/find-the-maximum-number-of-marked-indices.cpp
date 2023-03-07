class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        unordered_set<int> marked;
        int i = 0, j = n/2;
        while (i < n && j < n) {
            if (marked.find(i) == marked.end() && marked.find(j) == marked.end() && 2 * nums[i] <= nums[j]) {
                marked.insert(i);
                marked.insert(j);
                i++;
                j++;
            } 
            else {
                if (j < n - 1) {
                    j++;
                } 
                else {
                    i++;
                }
            }
        }
        return marked.size();
    }
};
