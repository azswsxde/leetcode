class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        size_t vec_len = timeSeries.size();
        for (size_t i = 0; i < vec_len; i++)
        {
            if (i < (vec_len-1))
            {
                if (timeSeries[i + 1] - timeSeries[i] >= duration)
                    total += duration;
                else
                    total += (timeSeries[i + 1] - timeSeries[i]);
            }
        }
        total += duration;
        return total;
    }
};