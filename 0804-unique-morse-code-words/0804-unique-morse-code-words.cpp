class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };

        set<string> st;

        for(string word : words){
            string transformation = "";

            for(char c : word){
                int index = c - 'a';
                transformation += morse[index];
            }
            st.insert(transformation);
        }
        return st.size();
    }
};