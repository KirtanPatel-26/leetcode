class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;

        for(int i=0;i<list1.size();i++){
            mp[list1[i]] = i;
        }

        vector<string> v;
        int minsum = INT_MAX;

        for(int j=0;j<list2.size();j++){
            if(mp.find(list2[j]) != mp.end()){

                int i = mp[list2[j]];
                int sum = i+j;

                if(sum < minsum){
                    minsum = sum;
                    v.clear();
                    v.push_back(list2[j]);
                }
                else if(sum == minsum){
                    v.push_back(list2[j]);
                }
            }
        }
        return v;
    }
};