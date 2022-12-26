// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        //custom sort (in increasing order of numberOfUnitsPerBox as we have to return  maximum total number of units )
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int> &first, vector<int> &second){
            return first[1]>second[1];
        });
        
		//greedily pick boxes till capacity is full
        int ans=0;
        for(auto box: boxTypes)
        {
            int x=min(box[0],truckSize);  //choose minimum boxes from available boxes and capacity left
            ans+=(x*box[1]);  //adding units in ans
            truckSize-=x;  //reduce the capacity
            if(!truckSize) break;  //capacity full
        }
        return ans;
    }
};