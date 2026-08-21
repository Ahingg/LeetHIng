class Solution {
public:
    typedef long long ll;
    ll gcd(ll a, ll b) {
        return std::gcd(a, b);
    }

    ll lcm(ll a, ll b) {
        if(a == 0 || b == 0) return 0;
        return (a / gcd(a,b)) * b;
    }

    ll countMultiples(ll M, const vector<int>& coins) {
        int n = coins.size();
        ll total = 0;

        for(int mask = 1; mask < (1 << n); mask++) {
            ll currLcm = 1;
            int size = 0;
            bool over = false;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    size++;
                    currLcm = lcm(currLcm, coins[i]);
                    if(currLcm > M) {
                        over = true;
                        break;
                    }
                }
            }

            if(over) continue;

            ll terms = M / currLcm;

            if(size & 1) total += terms;
            else total -= terms;
        }

        return total;
    }
    ll findKthSmallest(vector<int>& coins, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        ll minCoin = *min_element(coins.begin(), coins.end());

        ll low = 1,  high = minCoin * k;    
        ll ans = high;

        while(low <= high) {
            ll mid = low + (high-low)/2;

            if(countMultiples(mid, coins) >= k) {
                ans = mid;
                high = mid - 1;
            } 
            else low = mid + 1;
        }

        return ans;
    }
};