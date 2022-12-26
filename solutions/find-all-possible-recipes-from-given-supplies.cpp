// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size(), m = supplies.size();
        
        unordered_map<string, vector<string>> ingred;
        unordered_map<string, int> degree;
        
        for (int i = 0; i < n; i++)
        {
            degree[recipes[i]] = ingredients[i].size();
            for (auto& j : ingredients[i])
                ingred[j].push_back(recipes[i]);
        }
        
        unordered_set<string> s(recipes.begin(), recipes.end());
        
        queue<string> q;
        for (int i = 0; i < m; i++)
            q.push(supplies[i]);
        
        vector<string> ans;
        while (!q.empty())
        {
            string cur = q.front();
            q.pop();
            
            if (s.count(cur))
                ans.push_back(cur);
            
            for (auto& nxt : ingred[cur])
            {
                degree[nxt]--;
                if (degree[nxt] == 0)
                    q.push(nxt);
            }
        }
        return ans;
    }
};