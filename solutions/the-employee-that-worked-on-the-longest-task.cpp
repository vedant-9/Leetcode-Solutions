// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int len = logs[0][1], id = logs[0][0];
        for (int i = 1; i < logs.size(); i++){
            int curr = logs[i][1] - logs[i - 1][1];
            if (curr > len || curr == len and id > logs[i][0])  
                len = curr, id = logs[i][0]; 
        }
        return id;
    }
};