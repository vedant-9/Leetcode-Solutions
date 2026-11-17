class Solution {
public:
    unordered_map<string, int> parse(string s) {
        unordered_map<string, int> frequencies;

        for (int i = 0; i < (int)s.size();) {
            if (s[i] == '(') {
                int depth = 0;
                int close = i;

                for (; close < (int)s.size(); close++) {
                    if (s[close] == '(') {
                        depth++;
                    } else if (s[close] == ')') {
                        depth--;
                        if (depth == 0) {
                            break;
                        }
                    }
                }

                unordered_map<string, int> inner = parse(s.substr(i + 1, close - i - 1));
                i = close + 1;

                int multiplier = 1;
                if (i < (int)s.size() and isdigit(s[i])) {
                    multiplier = 0;
                    while (i < (int)s.size() and isdigit(s[i])) {
                        multiplier = multiplier * 10 + (s[i] - '0');
                        i++;
                    }
                }

                for (auto& entry : inner) {
                    frequencies[entry.first] += entry.second * multiplier;
                }
            } else {
                string element;
                element += s[i];
                i++;

                while (i < (int)s.size() and islower(s[i])) {
                    element += s[i];
                    i++;
                }

                int count = 1;
                if (i < (int)s.size() and isdigit(s[i])) {
                    count = 0;
                    while (i < (int)s.size() and isdigit(s[i])) {
                        count = count * 10 + (s[i] - '0');
                        i++;
                    }
                }

                frequencies[element] += count;
            }
        }

        return frequencies;
    }

    string countOfAtoms(string formula) {
        unordered_map<string, int> frequencies = parse(formula);

        map<string, int> sorted(frequencies.begin(), frequencies.end());
        string answer;

        for (auto& entry : sorted) {
            answer += entry.first;
            if (entry.second > 1) {
                answer += to_string(entry.second);
            }
        }

        return answer;
    }
};
