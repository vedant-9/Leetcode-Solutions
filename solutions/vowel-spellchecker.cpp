class Solution {
private:
    string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    string toVowelError(string s) {
        s = toLower(s);
        for (char& c : s) {
            if (string("aeiou").find(c) != string::npos) {
                c = '#';
            }
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exact_set(wordlist.begin(), wordlist.end());
        unordered_map<string, string> case_map;
        unordered_map<string, string> vowel_map;

        for (const string& word : wordlist) {
            string lower_word = toLower(word);
            if (case_map.find(lower_word) == case_map.end()) {
                case_map[lower_word] = word;
            }

            string vowel_error_word = toVowelError(word);
            if (vowel_map.find(vowel_error_word) == vowel_map.end()) {
                vowel_map[vowel_error_word] = word;
            }
        }

        vector<string> result;
        for (const string& query : queries) {
            if (exact_set.count(query)) {
                result.push_back(query);
                continue;
            }

            string lower_query = toLower(query);
            if (case_map.count(lower_query)) {
                result.push_back(case_map[lower_query]);
                continue;
            }

            string vowel_error_query = toVowelError(query);
            if (vowel_map.count(vowel_error_query)) {
                result.push_back(vowel_map[vowel_error_query]);
                continue;
            }

            result.push_back("");
        }
        return result;
    }
};
