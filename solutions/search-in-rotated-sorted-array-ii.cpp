// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n=arr.size();
        
        int l=0,r=n-1;
        
        while(l<=r){
            
            while(l<r && arr[l]==arr[l+1])
                ++l;
            while(l<r && arr[r]==arr[r-1])
                --r;
            
            int mid=(l+r)/2;
            
            if(arr[mid]==target)
                return true;
            
            if( arr[l] <= arr[mid]){
                
                if(target>=arr[l] && arr[mid]> target )
                    r=mid-1;
                else
                    l=mid+1;
                
                
            }else{
                
                if(target>arr[mid] && target<=arr[r])
                    l=mid+1;
                else
                    r=mid-1;
                
            }
            
        }
        return false;
    }
};