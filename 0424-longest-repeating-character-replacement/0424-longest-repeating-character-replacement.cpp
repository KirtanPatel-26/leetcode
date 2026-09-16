class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int right = 0; right < s.length();right++){
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq , freq[s[right] - 'A']);

            int changes = (right - left +1)-maxFreq;

            while(changes > k){
                freq[s[left] - 'A']--;

                left++;

                changes = (right - left + 1)- maxFreq;
            }

            ans = max(ans , right - left +1);
        }
        return ans;
    }
};