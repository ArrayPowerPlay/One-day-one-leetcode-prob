// problem description: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/
// solution below

class Solution {
public:
    // check for vowels
    bool isVowel(char c) {
        return c == 'a' || c == 'u' || c == 'i' || c == 'o' || c == 'e';
    }
    // count number of substrings valid with at least k consonants
    long long countAtLeastK(string &word, int k) {
        // approach using sliding window
        unordered_map<char, int> map;
        long long res = 0;
        int left = 0;
        // count number of consonants in substrings
        int consonants = 0;
        int n = word.size();
        // valid substrings begin at 'left' and end at 'right'
        for (int right = 0; right < n; right++) {
            char c = word[right];
            if (isVowel(c)) {
                map[c]++;
            } else consonants++;
            /* if valid substring founded, try to eliminate first elements 
            to find another valid substring */
            while (map.size() == 5 && consonants >= k) {
                res += n - right;
                char c = word[left];
                if (isVowel(c)) {
                    map[c]--;
                    if (map[c] == 0) map.erase(c);
                } else consonants--;
                left++;
            }
        }
        return res;
    }
    
    long long countOfSubstrings(string word, int k) {
        return countAtLeastK(word, k) - countAtLeastK(word, k + 1);
    }
};
