class Solution {
public:
    int maxProduct(int n) {
        vector<int> v;

        while(n>0){
            int digit = n%10;
            v.push_back(digit);
            n /= 10;
        }
        sort(v.begin(),v.end());

        return v[v.size()-1]*v[v.size()-2];
    }
};