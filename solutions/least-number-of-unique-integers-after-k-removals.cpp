// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int &x : arr) mp[x]++;
        
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto x : mp) {
            int freq = x.second;
            pq.push(freq);
        }

        while(pq.size()>0) {
            int freq = pq.top();
            if(k>=freq) {
                pq.pop();
                k = k-freq;
            }
            else
                break;
        }

        return pq.size();
    }
};