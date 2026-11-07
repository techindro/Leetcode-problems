class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        for (int i = 0; i < n; ++i) {
            freeServers.push({servers[i], i});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;
        
        vector<int> ans(m);
        long long currTime = 0;
        
        for (int i = 0; i < m; ++i) {
            currTime = max(currTime, (long long)i);
            
            if (freeServers.empty() && busyServers.top().first > currTime) {
                currTime = busyServers.top().first;
            }
            
            while (!busyServers.empty() && busyServers.top().first <= currTime) {
                int idx = busyServers.top().second;
                busyServers.pop();
                freeServers.push({servers[idx], idx});
            }
            
            auto [weight, idx] = freeServers.top();
            freeServers.pop();
            
            ans[i] = idx;
            busyServers.push({currTime + tasks[i], idx});
        }
        
        return ans;
    }
};
