class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        int square;

        for(int i=0;i<n;i++){
            square = nums[i]*nums[i];
            v.push_back(square);
        }
        sort(v.begin(),v.end());

        return v;
    }
};