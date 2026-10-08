class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                depth++;

                if (depth > 1)
                    ans += c;
            }
            else {
                if (depth > 1)
                    ans += c;

                depth--;
            }
        }

        return ans;
    }
};