
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        // {finishing time, server ID}
        priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        vector<int> cnt(k,0);
        // Initially, all servers are available
        for(int i=0;i<k;i++) {
            available.insert(i);
        }
        for(int i=0;i<arrival.size();i++){
            // Release servers whose requests are completed
            while(!busy.empty() && busy.top().first<=arrival[i]){
                int server=busy.top().second;
                busy.pop();
                available.insert(server);
            }
            // All servers are busy
            if(available.empty()){
                continue;
            }
            // Preferred server
            int start=i%k;
            // Find the next available server
            auto it=available.lower_bound(start);
            // Wrap around if necessary
            if (it == available.end()) {
                it = available.begin();
            }
            int server = *it;
            // Assign request to this server
            available.erase(it);
            cnt[server]++;
            // Store when this server becomes free
            busy.push({ (long long)arrival[i] + load[i], server});
        }
        // Find maximum number of handled requests
        int maxi = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == maxi) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
