// problem description: https://leetcode.com/problems/take-gifts-from-the-richest-pile/
// solution below 

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res = 0;
        // use maxHeap
        priority_queue<int> q(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++) {
            int num = sqrt(q.top());
            q.push(num);
            q.pop();
        }
        while(!q.empty()) {
            res += q.top();
            q.pop();
        }
        return res;
    }
};
