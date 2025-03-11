// problem description: https://leetcode.com/problems/alternating-groups-i/description/
// solution below


class Solution {
    public int numberOfAlternatingGroups(int[] colors) {
        int len = colors.length;
        if (len < 2) return 0;
        int res = 0;
        for (int i = 1; i < len - 1; i++) {
            if (check(colors[i - 1], colors[i], colors[i + 1])) res++;
        }
        if (check(colors[len - 1], colors[0], colors[1])) res++;
        if (check(colors[len - 2], colors[len - 1], colors[0])) res++;
        return res;
    }
    boolean check(int a, int b, int c) {
        if (b == 0) return a + c == 2;
        else return a + c == 0;
    }
}
