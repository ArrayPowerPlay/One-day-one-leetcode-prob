// problem description: https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09
// solution below

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0;
        int len = colors.size();
        vector<int> lenGroup;
        int maxLen = 1;

        for (int i = 1; i < len; i++) {
            if (colors[i] != colors[i - 1]) {
                maxLen++;
            } else {
                lenGroup.push_back(maxLen);
                maxLen = 1;
            }
        }
        bool check = colors[0] != colors[len - 1];
        if (lenGroup.empty() && check) {
            res = (maxLen >= k) ? len : 0;
            return res;
        } else if (check) {
            lenGroup[0] += maxLen;
        } else {
            lenGroup.push_back(maxLen);
        }

        for (int i = 0; i < lenGroup.size(); i++) {
            if (lenGroup[i] >= k) res += lenGroup[i] - k + 1;
        }

        return res;
    }
};

