// problem description: https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/
// solution below

class Solution {
public:
    // check for vowels
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    // count number of valid substrings in a valid string
    int countValidSubstrings(const string &str) {
        int l = 0;
        unordered_map<char, int> freq;
        int m = str.size();
        int res = 0;

        for (int r = 0; r < m; r++) {
            freq[str[r]]++;
            while (l < r && freq.size() == 5) {
                res += m - r;
                char ch = str[l];
                freq[ch]--;
                if (freq[ch] == 0) freq.erase(ch);
                l++;
            }
        }
        return res;
    }

    int countVowelSubstrings(string word) {
        int n = word.size();
        int res = 0;
        int l = 0;
        int r;
        
        while (l < n) {
            if (!isVowel(word[l])) {
                l++;
                continue;
            }
            r = l;
            while (r < n && isVowel(word[r])) {
                r++;
            }
            // find longest valid substrings that do not contain each other
            string longest = word.substr(l, r - l);
            res += countValidSubstrings(longest);
            l = r + 1;
        }
        return res;
    }
};
