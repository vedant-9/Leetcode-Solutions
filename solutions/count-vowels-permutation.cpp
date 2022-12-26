// https://leetcode.com/problems/count-vowels-permutation

class Solution {
public:
    const int MOD = 1e9+7;
    
    int countVowelPermutation(int n) {
        long prevA, prevE, prevI, prevO, prevU;
        prevA = prevE = prevI = prevO = prevU = 1;

        for (int i = 2; i <= n; ++i) {
            
            long countA = (prevE + prevI + prevU) % MOD;
            long countE = (prevA + prevI) % MOD;
            long countI = (prevE + prevO) % MOD;
            long countO = prevI;
            long countU = (prevI + prevO) % MOD;
            
            prevA = countA;     prevE = countE;
            prevI = countI;     prevO = countO;     prevU = countU;
        }
        
        return (prevA + prevE + prevI + prevO + prevU) % MOD;
    }
};