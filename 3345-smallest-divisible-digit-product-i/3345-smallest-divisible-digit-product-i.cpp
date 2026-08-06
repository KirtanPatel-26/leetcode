class Solution {
public:
    int smallestNumber(int n, int t) {

    while(true){
        int temp = n;
        int multiply = 1;
            while(temp >0){
                int digit = temp%10;
                multiply *= digit;
                temp = temp/10; 
            }
            if(multiply % t == 0){
                return n;
            }
            n++;
        }
    }
};