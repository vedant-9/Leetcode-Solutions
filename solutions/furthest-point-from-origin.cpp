class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int leftCur = 0, rightCur = 0;
        for(auto move: moves) {
            if(move == 'R') leftCur++, rightCur++;
            else if(move == 'L') leftCur--, rightCur--;
            else leftCur--, rightCur++;
        }
        return max(abs(leftCur), abs(rightCur));
    }
};
