class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());  // 先排序

        vector<string> result;
        string prev = "";

        unsigned short folder_len = folder.size(), i;
        for (i = 0; i < folder_len; i++) {
            if (prev.empty() || folder[i].find(prev + "/") != 0) {
                result.push_back(folder[i]);
                prev = folder[i];
            }
        }

        return result;
    }
};
