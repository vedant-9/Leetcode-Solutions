// https://leetcode.com/problems/encrypt-and-decrypt-strings

class Encrypter {
public:
    map<char,string> en;
    map<string,int> cnt;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < int(keys.size()); i++) {
            en[keys[i]] = values[i];
        }
        for (auto s : dictionary) {
            cnt[encrypt(s)]++;
        }
    }
    
    string encrypt(string word1) {
        string s;
        for (auto c : word1) {
            s += en[c];
        }
        return s;
    }
    
    int decrypt(string word2) {
        return cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */