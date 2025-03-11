// problem description: https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09
// solution below

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0;
        int len = colors.size();
        // this vector contains lengths of all alternating groups in 'colors'
        vector<int> lenGroup;
        // calculate length of each alternating group
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
        // edge case: 1 0 1 0 1 0
        if (lenGroup.empty() && check) {
            res = (maxLen >= k) ? len : 0;
            return res;
        // if first element = last element, we need to sum two lengths of two alternating groups
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



