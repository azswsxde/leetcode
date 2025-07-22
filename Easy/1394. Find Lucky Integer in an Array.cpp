class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky_num = -1;
        map<int, int> m_map;
        for (size_t i = 0; i < arr.size(); i++) {
            if (m_map.find(arr[i]) != m_map.end())
                m_map[arr[i]]++;
            else
                m_map[arr[i]] = 1;
        }

        for (map<int, int>::iterator iter = m_map.begin(); iter != m_map.end(); iter++) {
            if (iter->first == iter->second)
                if (iter->first > lucky_num)
                    lucky_num = iter->first;
        }
        return lucky_num;
    }
};