// https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int carryBit{0};
        string resultStr;
        
        int indexA{(int)a.size()-1};
        int indexB{(int)b.size()-1};
        
        // run strings right to left        
        while (indexA >=0 || indexB >=0) {
            int bit{carryBit};
            if (indexA >= 0) {
                bit += a[indexA]-'0';
                --indexA;
            }
            if (indexB >= 0) {
                bit += b[indexB]-'0';
                --indexB;
            }
            
            if (bit == 3) {
                resultStr = "1" + resultStr;
                carryBit = 1;
            } else if (bit == 2) {
                resultStr = "0" + resultStr;
                carryBit = 1;
            } else {
                resultStr = to_string(bit) + resultStr;
                carryBit = 0;
            }
        }
        // possible last value
        if (carryBit == 1) {
            resultStr = "1" + resultStr;
        }
        return resultStr;
        
    }
};