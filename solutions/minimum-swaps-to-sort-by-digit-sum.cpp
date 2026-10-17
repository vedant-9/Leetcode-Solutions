class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Thought is find number of disjoint cycles
        // we can get correct order for cycle of length len in len-1 swaps 
        // TC - O(nlogn)
        // SC - O(n)
        int n = nums.size();

        auto digitSum = [](int x) {
            int s = 0;
            while (x) { s += x % 10; x /= 10; }
            return s;
        };

        // Pair each element with its original index.
        // Sort by digit sum, then by value as the tie-breaker.
        vector<pair<pair<int,int>, int>> items(n);
        for (int i = 0; i < n; i++)
            items[i] = {{digitSum(nums[i]), nums[i]}, i};

        // no need for custom sort function as pair checks first then second for sorting criteria
        sort(items.begin(), items.end());

        // order[i] = original index of the element that belongs at position i.
        vector<int> order(n);
        for (int i = 0; i < n; i++)
            order[i] = items[i].second;

        vector<bool> visited(n, false);
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int len = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = order[j];
                len++;              // count this cycle's length
            }
            answer += len - 1;      // len - 1 swaps for this cycle
        }
        return answer;
    }
};
