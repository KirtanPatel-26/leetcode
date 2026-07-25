class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> v;
        int sum=0;

        for(int i=0;i<n;i=i+2){
            v.push_back(min(nums[i],nums[i+1]));
        }
        for(int i=0;i<v.size();i++){
            sum += v[i];
        }
        return sum;
    }
};