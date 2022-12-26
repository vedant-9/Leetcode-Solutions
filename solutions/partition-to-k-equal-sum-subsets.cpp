// https://leetcode.com/problems/partition-to-k-equal-sum-subsets

class Solution {
public:
    bool rec(vector<int> &arr, int subsetSum[], bool taken[], int tar, int k, int n, int curIdx, int limitIdx)
    {
        if (subsetSum[curIdx] == tar)
        {
            if (curIdx == k - 2)
                return true;

            return rec(arr, subsetSum, taken, tar,k, n, curIdx + 1, n - 1);
        }

        for (int i = limitIdx; i >= 0; i--)
        {
            if (taken[i])
                continue;
            int tmp = subsetSum[curIdx] + arr[i];


            if (tmp <= tar)
            {
                taken[i] = true;
                subsetSum[curIdx] += arr[i];
                bool nxt = rec(arr, subsetSum, taken, tar, k, n, curIdx, i - 1);
                taken[i] = false;
                subsetSum[curIdx] -= arr[i];
                if (nxt)
                    return true;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& a, int k) 
    {
        int n = a.size();
        long sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
        }
        if(sum%k!=0)
            return false;
        
        int tar = sum/k;
        int subsetSum[k];
        bool taken[n];

        // Initialize sum of each subset from 0
        for (int i = 0; i < k; i++)
            subsetSum[i] = 0;

        // mark all elements as not taken
        for (int i = 0; i < n; i++)
            taken[i] = false;

        subsetSum[0] = a[n - 1];
        taken[n - 1] = true;

        // call recursive method to check K-substitution condition
        return rec(a, subsetSum, taken,tar, k, n, 0, n - 1);
    }
};