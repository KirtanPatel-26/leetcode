class Solution {
public:
    int minimumPushes(string word) {
        int eword = 0;

        vector<int> freq(26,0);

        for(int ch : word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        for(int i=0;i<26;i++){
            if(freq[i] == 0){
                break;
            }
            eword += freq[i] * ((i/8)+1);
        }
        return eword;
    }
};