class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, unordered_set<int>> reserved;

        for (auto& seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        int answer = (n - reserved.size()) * 2;

        for (auto& [row, seats] : reserved) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                answer += 2;
            }
            else if (left || middle || right) {
                answer += 1;
            }
        }

        return answer;
    }
};