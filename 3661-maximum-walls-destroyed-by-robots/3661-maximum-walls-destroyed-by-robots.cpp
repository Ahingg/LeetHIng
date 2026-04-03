class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pll;
    vector<int> wallSorted;

    int countWall(ll l, ll r) {
        if(l > r) return 0;
        auto it1 = lower_bound(wallSorted.begin(), wallSorted.end(), l);
        auto it2 = upper_bound(wallSorted.begin(), wallSorted.end(), r);
        return distance(it1, it2);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        wallSorted = walls;
        sort(wallSorted.begin(), wallSorted.end());

        vector<pll> robos(n);
        for(int i = 0; i < n; i++) {
            robos[i] = {robots[i], distance[i]};
        }
        sort(robos.begin(), robos.end());

        ll pos0 = robos[0].first;
        ll dist0 = robos[0].second;
        int prevL = countWall(pos0 - dist0, pos0);
        int prevR = countWall(pos0, pos0);

        for(int i = 1; i < n; i++) {
            auto [pos, d] = robos[i];
            auto [prevPos, prevD] = robos[i-1];

            ll leftStart = max(pos-d, prevPos+1);
            int countL = countWall(leftStart, pos);

            ll prevEndR = min(prevPos + prevD, pos-1);
            int countPrevR = countWall(prevPos + 1, prevEndR);

            ll overlapStart = max(leftStart, prevPos +1);
            ll overlapEnd = min(prevEndR, pos);
            int overlap = countWall(overlapStart, overlapEnd);

            int posCount = countWall(pos, pos);

            int currL = max(prevL + countL, prevR + countPrevR + countL - overlap);
            int currR = max(prevL + posCount, prevR + countPrevR + posCount);
            prevL = currL;
            prevR = currR;
        }

        ll lastPos = robos[n-1].first;
        ll lastDist = robos[n-1].second;
        int result = max(prevL, prevR + countWall(lastPos + 1, lastPos + lastDist));
        return result;
    }
};