class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int firstLandFinish = INT_MAX;
        for (int i = 0; i < n; i++) {
            firstLandFinish = min(firstLandFinish, landStartTime[i] + landDuration[i]);
        }

        int firstWaterFinish = INT_MAX;
        for (int j = 0; j < m; j++) {
            firstWaterFinish = min(firstWaterFinish, waterStartTime[j] + waterDuration[j]);
        }

        int bestLandThenWater = INT_MAX;
        for (int j = 0; j < m; j++) {
            int finish = max(firstLandFinish, waterStartTime[j]) + waterDuration[j];
            bestLandThenWater = min(bestLandThenWater, finish);
        }

        int bestWaterThenLand = INT_MAX;
        for (int i = 0; i < n; i++) {
            int finish = max(firstWaterFinish, landStartTime[i]) + landDuration[i];
            bestWaterThenLand = min(bestWaterThenLand, finish);
        }

        return min(bestLandThenWater, bestWaterThenLand);
    }
};
