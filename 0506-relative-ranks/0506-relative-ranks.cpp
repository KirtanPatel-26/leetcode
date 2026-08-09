class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            arr.push_back({score[i],i});
        }

        sort(arr.rbegin(),arr.rend());

        vector<string> answer(n);

        for(int i=0;i<n;i++){
            
            int orgindex = arr[i].second;

            if(i==0){
                answer[orgindex] = "Gold Medal";
            }
            else if(i==1){
                answer[orgindex] = "Silver Medal";
            }
            else if(i==2){
                answer[orgindex] = "Bronze Medal";
            }
            else{
                answer[orgindex] = to_string(i+1);
            }
        }
        return answer;
    }
};