class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;

        v1.push_back(nums[0]);
        v2.push_back(nums[1]);

        int n = nums.size();

        for(int i=2;i<n;i++){
            if(v1.back() > v2.back()){
                v1.push_back(nums[i]);
            }
            else{
                v2.push_back(nums[i]);
            }
        }

        vector<int> result;

        result.insert(result.end(), v1.begin(), v1.end());
        result.insert(result.end(), v2.begin(), v2.end());

        return result;
    }
};