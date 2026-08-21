class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26,0);
        int n = words.size();

        for(char ch : words[0]){
            freq[ch - 'a']++;
        }

        for(int i=1;i<n;i++){
            vector<int> freq1(26,0);
            
            for(char ch : words[i]){
                freq1[ch - 'a']++;
            }

            for(int j=0;j<26;j++){
                freq[j] = min(freq[j],freq1[j]);
            }
        }

        vector<string> ans;
        for(int i=0;i<26;i++){
            while(freq[i] > 0){
                ans.push_back(string(1, 'a'+ i));
                freq[i]--;
            }
        }
        return ans;
    }
};