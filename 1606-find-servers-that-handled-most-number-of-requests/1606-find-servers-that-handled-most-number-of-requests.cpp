class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> res;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        set<int> servers;
        for(int i = 0; i < k; i++) servers.insert(i);

        vector<int> reqCount(k, 0);

        int n = arrival.size();
        int maxReq = 0;
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && arrival[i] >= pq.top().first) {
                servers.insert(pq.top().second);
                pq.pop();
            }

            if(servers.size() == 0) continue;

            int reqServer = i % k;
            auto foundServer = servers.lower_bound(reqServer);

            auto avail = -1;
            if(foundServer == servers.end()) avail = *servers.begin();
            else avail = *foundServer;
            servers.erase(avail);

            pq.push({arrival[i] + load[i], avail});
            reqCount[avail]++;

            maxReq = max(maxReq, reqCount[avail]);
        }

        for(int i = 0; i < k; i++) {
            if(reqCount[i] == maxReq) {
                res.push_back(i);
            }
        }

        return res;
    }
};