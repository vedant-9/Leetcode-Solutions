class Solution {
public:
    string getEncryptedString(string str, int k) {
        int n = str.length();
        k %= n;
        rotate(str.begin(), str.begin() + k, str.end()); 
        return str;
    }
};
