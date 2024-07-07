class Solution {
public:
    int rec(const string& target, const unordered_map<string, int>& wordCosts, int index, vector<int>& memo) {
        if (index == target.length()) {
            return 0;
        }

        if (memo[index] != -2) {
            return memo[index];
        }

        int minCost = INT_MAX;
        for (const auto& it : wordCosts) {
            if (target.compare(index, it.first.length(), it.first) == 0) {
                int remainingCost = rec(target, wordCosts, index + it.first.length(), memo);
                if (remainingCost != -1) {
                    minCost = min(minCost, it.second + remainingCost);
                }
            }
        }

        memo[index] = (minCost == INT_MAX) ? -1 : minCost;
        return memo[index];
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        vector<int> memo(target.length(), -2);
        unordered_map<string, int> wordCosts;
        for (int i = 0; i < words.size(); i++) {
            if (wordCosts.find(words[i]) == wordCosts.end())
                wordCosts[words[i]] = costs[i];
            else
                wordCosts[words[i]] = min(wordCosts[words[i]], costs[i]);
        }
        return rec(target, wordCosts, 0, memo);
    }
};
