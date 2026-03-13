class Solution {
public:
    typedef long long ll;
    typedef tuple<ll, ll, ll, ll> pkg;
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<pkg, vector<pkg>, greater<pkg>> pq;
        for(auto& x: workerTimes){
            pq.push({x, 0, x, 0}); // time passed, base factor, assigned
        } 
        while(mountainHeight != 0){
            auto [potential, time, base, assigned] = pq.top();
            pq.pop();
            // cout << "Before: " << potential << " " << time << " " << base << " " << assigned << endl;
            assigned++;
            time += base*assigned;
            potential += base * (assigned+1);
            pq.push({potential, time, base, assigned});
            mountainHeight--;
            // cout << "After: " << potential << " " << time << " " << base << " " << assigned << endl;
            // cout << "Height: " << mountainHeight << endl;
            // cout << endl;
        }

        ll result = -1;
        while(!pq.empty()){
            auto [potential, time, base, assigned] = pq.top();
            pq.pop();
            result = result > time ? result : time;
        }
        return result;
    }
};