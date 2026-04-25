class Solution {
public:
    typedef long long ll;
    
    ll S;

    ll getCoor(int x, int y) {
        if(y == 0) return x;
        if(x == S) return S + y;
        if(y == S) return 2LL * S + (S-x);
        return 3LL * S + (S-y);
    }



    int maxDistance(int side, vector<vector<int>>& points, int k) {
        S = side;
        int n = points.size();

        vector<ll> p;

        for(auto& pt: points) p.push_back(getCoor(pt[0], pt[1]));
        sort(p.begin(), p.end());
        for(int i = 0; i < n; i++) p.push_back(p[i] + 4LL * S);

        auto check = [&](ll D) {
            vector<int> next_idx(2*n);
            int right = 0;

            for(int left = 0; left < 2 * n; left++) {
                while(right < 2 * n && p[right] - p[left] < D) right++;
                next_idx[left] = right;
            }

            int layers = 32 - __builtin_clz(k);
            vector<vector<int>> up(2*n + 1, vector<int>(layers, 2*n));

            for(int i = 0; i <= 2*n; i++){
                up[i][0] = (i < 2*n) ? next_idx[i] : 2 * n;
            }

            for(int j = 1; j < layers; j++) {
                for(int i = 0; i <= 2*n; i++) {
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }

            for(int i = 0; i < n; i++) {
                int curr = i;
                int jumps = k-1;

                for(int j = 0; j < layers; j++){
                    if((jumps >> j) & 1) {
                        curr = up[curr][j];
                    }
                }

                if(curr < 2 * n && (p[i] + 4LL * S) - p[curr] >= D) return true;
            }
            return false;
        };

        ll low = 1, high = 4LL*S;
        ll ans = 0;

        while(low <= high) {
            ll mid = low + (high - low)/2;
            if(check(mid)) {
                ans = mid;
                low = mid+1;
            }
            else high = mid - 1;
        }

        return ans;
        
    }
};