// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>res;
        int n=nums.size();
        if(nums.empty()) 
            return res;
        //sort
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target2 = target-nums[i]-nums[j];     
                
                //two pointer appraoch start from here     
                int front=j+1;
                int back=n-1;
                while(front<back)
                {
                    int sum = nums[front]+nums[back];
                    if(sum<target2)
                        front++;
                    else if(sum>target2) 
                        back--;
                    else
                    {
                        vector<int>quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        
                        res.push_back(quad);
                        
                        //handle duplicates for front
                        while(front<back && nums[front]==quad[2]) front++;
                        
                        //handle duplicates  for back
                        while(front<back && nums[back]==quad[3]) back--;   
                    }
                }
                
                // handle duplicates for j
                while(j+1<n && nums[j+1]==nums[j]) j++;
                
            }
            // handle duplicates for i
            while(i+1<n && nums[i+1]==nums[i]) i++;      
        }
        return res;
    }
};