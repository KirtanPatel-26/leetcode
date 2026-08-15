class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> v;

        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        
        for(string word : words){
            string w = word;

            for(char &c : w){
                c = tolower(c);
            }
            string row;

            if(row1.find(w[0]) != string::npos){
                row = row1;
            }
            else if(row2.find(w[0]) != string::npos){
                row = row2;
            }
            else{
                row = row3;
            }

            bool valid = true;
            for(char c : w){
                if(row.find(c) == string::npos){
                    valid = false;
                    break;
                }
            }
            if(valid){
                v.push_back(word);
            }
        }
        return v; 
    }
};