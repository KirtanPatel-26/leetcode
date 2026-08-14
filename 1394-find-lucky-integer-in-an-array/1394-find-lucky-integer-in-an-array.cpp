class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;

        for(int x : arr){
            freq[x]++;
        }

        int maxi = -1;
        for(int x : arr){
            if(freq[x] == x){
                maxi = max(maxi,x);
            }
        }
        return maxi;
    } 
};