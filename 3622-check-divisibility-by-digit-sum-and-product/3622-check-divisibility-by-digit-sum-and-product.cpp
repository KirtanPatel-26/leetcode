class Solution {
public:
    bool checkDivisibility(int n) {
        int ori = n;
        int sum = 0;
        int product = 1;
        int add;

        while(n > 0){
            int temp = n%10;
            sum = sum+temp;
            product = product*temp;
            n = n/10;
        }
        add = sum+product;

        if(ori % add == 0){
            return true;
        }
        return false;
    }
};