class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0;i<n-1;i++){
            int current = nums[i];
            int next = nums[i+1];

            while(current+1 < next){
                v.push_back(current+1);
                current++;
            }
        }
        return v;
    }
};