class Solution {
public:
    typedef long long ll;
    vector<ll> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<ll, vector<ll>> list;

        for(int i = 0; i < n; i++) {
            list[nums[i]].push_back(i);
        }
        vector<ll> result(n, -1); 
        for(auto& x: list){
            auto& [k, v] = x;
            // cout << "num: " << k << endl;
            int s = v.size();
            // process 0 for the base line sum.
            ll leftSum = 0, rightSum = 0;
            for(int i = 1; i < s; i++) rightSum += abs(v[i] - v[0]);
            result[v[0]] = rightSum;
            // cout << leftSum << " " << rightSum << endl;
            // process the other index available for that specific number.
            // starting from the first one, the next leftSum will be += the amount of the distance with the previous index.
            for(int i = 1; i < s; i++)  {
                // i is equal to the current index, proceed the leftSum
                ll step = abs(v[i] - v[i-1]);
                // cout << v[i] << " " << v[i-1] << " " << step << endl;
                leftSum += step * (i);
                // count rightSum
                rightSum -= (s-i) * step;
                // cout << leftSum << " " << rightSum << endl << endl;
                result[v[i]] = leftSum + rightSum;
            }
            // cout << endl;
        }
        return result;
    }
};