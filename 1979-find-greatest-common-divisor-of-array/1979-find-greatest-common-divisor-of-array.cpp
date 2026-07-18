class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int a = nums[0];
        int b = nums[n-1];

        if(b == 0){
            return a;
        }
        else{
            return gcd(b , a%b);
        }
        return 1;
    }
};