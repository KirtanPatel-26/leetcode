class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1;
        int currentwidth = 0;

        for(char c : s){
            int width = widths[c - 'a'];

            if(currentwidth + width  > 100){
                lines++;
                currentwidth = width;
            }
            else{
                currentwidth += width; 
            }
        }
        return {lines,currentwidth};
    }
};