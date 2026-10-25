class Solution {
public:
    int calculateScore(int a, int b) {
        bitset<8> bit1(a), bit2(b);
        int s1 = bit1.count(), s2 = bit2.count();
        if(s1 >= s2) return s1 * s2;
        return s2 / s1;
    }
};
