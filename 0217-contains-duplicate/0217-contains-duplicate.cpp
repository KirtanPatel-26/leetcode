class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    // int n = nums.size();
    // sort(nums.begin(), nums.end());

    //     for(int i=1;i<n;i++){
    //         if(nums[i-1] == nums[i]){
    //             return true;
    //         }
    //     }
    //     return false;

        unordered_set<int> st;

        for(int num :nums){
            if(st.find(num) != st.end()){
                return true;
            }
            st.insert(num);
        }
        return false;
     }
};