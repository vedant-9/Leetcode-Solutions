// https://leetcode.com/problems/sort-even-and-odd-indices-independently

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& a) {
        vector<int> even,odd;
        int n=a.size();
        for(int i=0;i<n;i++) {
            if(i%2==0) even.push_back(a[i]);
            else odd.push_back(a[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.rbegin(),odd.rend());
        int j=0,k=0;
        for(int i=0;i<n;i++) {
            if(i%2==0) a[i]=even[j++];
            else a[i]=odd[k++];
        }
        return a;
    }
}; 