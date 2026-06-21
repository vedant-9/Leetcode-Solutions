class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs, digitLogs;
        for(auto &log: logs) {
            int i = 0;
            while(log[i] != ' ') i++;
            i++;
            if(isdigit(log[i])) digitLogs.push_back(log);
            else letterLogs.push_back(log);
        }

        sort(letterLogs.begin(), letterLogs.end(), [](const auto &x, const auto &y)->bool{
            int i = 0, j = 0;
            string iden1 = "", iden2 = "";
            while(x[i] != ' ') iden1+=x[i], i++;
            while(y[j] != ' ') iden2+=y[j], j++;
            string llog1 = x.substr(i), llog2 = y.substr(j);
            if(llog1 < llog2) return 1;
            else if(llog1 > llog2) return 0;
            else return iden1 < iden2;
        });

        vector<string> ans = letterLogs;
        for(auto l: digitLogs) ans.push_back(l);

        return ans;
    }
};
