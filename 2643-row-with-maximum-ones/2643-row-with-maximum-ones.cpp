class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int cnt_max = 0;
        int index = 0;
        int n = mat.size();

        for(int i=0;i<n;i++){
            int cnt_one = count(mat[i].begin(),mat[i].end(),1);

            if(cnt_one > cnt_max){
                cnt_max = cnt_one;
                index = i;
            }
        }
        return {index,cnt_max};
    }   
};