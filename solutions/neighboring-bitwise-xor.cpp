class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sum = 0;
        for(auto x: derived) sum += x;
        return (sum % 2 == 0);
    }
};
