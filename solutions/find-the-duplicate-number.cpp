// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        // note that array size is n+1
        int slow = a[0];
        int fast = a[0];
        do {
            slow = a[slow];
            fast = a[a[fast]];
        } while(slow != fast);
        fast = a[0];
        while(slow!=fast) {
            slow = a[slow];
            fast = a[fast];
        }
        return slow;
    }
};