// https://leetcode.com/problems/number-of-pairs-satisfying-inequality

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;

class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n = a.size();

        ll ans = 0;
        ordered_set<int> os;
        
        for(int i=0; i<n; i++) {
            ans += os.order_of_key(a[i]-b[i]+diff+1);
            os.insert(a[i]-b[i]);
        }
        
        return ans;
    }
};