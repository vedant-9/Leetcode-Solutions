// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    vector<int> a;
    NumArray(vector<int>& b) 
    {
        int p = 0;
        for(int i=0;i<b.size();i++)
        {
            p+=b[i];
            a.push_back(p);
        }
    }
    
    int sumRange(int left, int right) 
    {
        if(left==0)
            return a[right];
        return a[right]-a[left-1];       
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */