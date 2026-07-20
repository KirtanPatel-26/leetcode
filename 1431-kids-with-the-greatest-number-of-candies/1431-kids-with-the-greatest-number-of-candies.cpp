class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v;

        int max = candies[0];

        for(int i=0;i<candies.size();i++){
            if(candies[i] > max){
                max = candies[i];
            }
        }

        for(int i=0;i<candies.size();i++){
            candies[i] += extraCandies;
            if(candies[i] > max-1){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
        }
        return v;
    }
};