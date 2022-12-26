// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0, r = n-1;
        while(r-l >= k) {
            if(x-arr[l] <= arr[r]-x) r--;
            else l++;
        }
        vector<int> ans;
        for(int i=l; i<=r; i++) 
            ans.push_back(arr[i]);
        return ans;
    }
};