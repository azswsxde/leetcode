class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unsigned n = grid.size();
        unsigned short n_pow = n * n;
        short *count_arr;
        unsigned short miss_idx = 0, repeat_idx = 0;
        count_arr = new short[n_pow];
        vector<int> result;

        for(unsigned short i = 0 ; i < n_pow; i++)
            count_arr[i] = 1;

        for(unsigned short i = 0 ; i < n ; i++)
            for(unsigned short j = 0 ; j < n ; j++)
                count_arr[(grid[i][j] - 1)]--;

        for(unsigned short i = 0 ; i < n_pow; i++) {
            if (count_arr[i] == 0)
                continue;
            if (count_arr[i] == 1)
                miss_idx = i;
            if (count_arr[i] == -1)
                repeat_idx = i;
        }
        result = {repeat_idx + 1, miss_idx + 1};
        delete [] count_arr;
        return result;
    }
};