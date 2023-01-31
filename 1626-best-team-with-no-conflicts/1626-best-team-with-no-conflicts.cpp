class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int dp[n];
        vector<pair<int,int>> players;
        int high_score = 0;
        
        for(int i = 0;i < n;i++){
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());
        for(int i = 0;i < n;i++){
            dp[i] = players[i].second;
            for(int j = 0;j < i;j++){
                if(players[j].second <= players[i].second){
                    dp[i] = max(dp[i], dp[j]+players[i].second);
                }
            }
            high_score = max(high_score, dp[i]);
        }
        return high_score;
    }
};