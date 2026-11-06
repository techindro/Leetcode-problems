class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int numQueries = queries.size();
        vector<int> ans(numQueries);
        
        vector<pair<int, int>> sortedQueries(numQueries);
        for (int i = 0; i < numQueries; ++i) {
            sortedQueries[i] = {queries[i], i};
        }
        
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> serverCounts(n + 1, 0);
        int uniqueActiveServers = 0;
        int left = 0;
        int right = 0;
        int numLogs = logs.size();
        
        for (const auto& q : sortedQueries) {
            int queryTime = q.first;
            int queryIndex = q.second;
            
            int windowStart = queryTime - x;
            int windowEnd = queryTime;
            
            while (right < numLogs && logs[right][1] <= windowEnd) {
                int serverId = logs[right][0];
                if (serverCounts[serverId] == 0) {
                    uniqueActiveServers++;
                }
                serverCounts[serverId]++;
                right++;
            }
            
            while (left < numLogs && logs[left][1] < windowStart) {
                int serverId = logs[left][0];
                serverCounts[serverId]--;
                if (serverCounts[serverId] == 0) {
                    uniqueActiveServers--;
                }
                left++;
            }
            
            ans[queryIndex] = n - uniqueActiveServers;
        }
        
        return ans;
    }
};
