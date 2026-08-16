class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int left = 0;
        int right = 0;

        while (left < fruits.size()) {

            if (right >= baskets.size()) {
                // No basket found for this fruit
                left++;
                right = 0;
            }
            else if (baskets[right] >= fruits[left]) {
                baskets.erase(baskets.begin() + right);
                fruits.erase(fruits.begin() + left);

                // Start checking the next fruit
                right = 0;
            }
            else {
                right++;
            }
        }

        return fruits.size();
    }
};