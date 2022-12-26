// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int n=nums.size();
        map<int,int> cnt;
        for(int i=1;i<n;i++) {
            if(nums[i-1]==key) 
                cnt[nums[i]]++;
        }
        int mx=0,mxcnt=0;
        for(auto it:cnt) {
            if(it.second>mxcnt) {
                mx=it.first;
                mxcnt=it.second;
            }
        }
        return mx;
    }
};