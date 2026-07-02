class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();

        map<ll, int> listCnt;

        for(auto x: nums) listCnt[x]++;
        int result = 0;
        if(listCnt.count(1)){
            result = listCnt[1] - (listCnt[1] % 2 == 1 ? 0 : 1);
        }
        for(const auto& [key, value]: listCnt) {
            if(key == 1) continue;
            int temp = 0;
            ll num = key;
            while(true){
                if(num > 100000) break;
                ll nextNum = num * num;
                auto it = listCnt.find(nextNum);
                if(it == listCnt.end() || it->second == 0) break;
                
                if(listCnt[num] > 1) {
                    temp += 2;
                    num *= num;
                }
                else {
                    break;
                }
            }   
            if(listCnt[num] >= 1) temp++;
            result = max(temp, result);
        }
        return result;
    }
};