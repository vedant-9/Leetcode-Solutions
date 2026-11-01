class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1) return -1;
        if(value % 2 == 0) {
            if(value - 2 * index > 1)
                return (long long) value + (n-index-1) * 2;
            return -1;
        }
        for(int i = 3; i * i <= value; i++) {
            if(value % i == 0 and value - i - (index-1)* 2 > 1) 
                return (long long) value + i + (n-index-2) * 2; 
        }
        int i = value;
        if(value % 2 != 0 and value - i - (index-1)* 2 > 1) 
            return (long long) value + i + (n-index-2) * 2; 
        return -1;
    }
};
