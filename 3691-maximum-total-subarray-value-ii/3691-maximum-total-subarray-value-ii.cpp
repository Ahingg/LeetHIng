class Solution {
public:
    typedef long long ll;
    typedef tuple<ll, int, int> tii;
    struct Node {
        ll minVal, maxVal;
    };

    vector<Node> segment; 
    Node merge(const Node& left, const Node& right) {
        return {
            min(left.minVal, right.minVal), max(left.maxVal, right.maxVal)
        };
    }

    void build(int nodeIdx, int start, int end, const vector<int>& nums){
        if(start == end) {
            segment[nodeIdx] = {nums[start], nums[end]}; 
            return;
        }

        ll mid = start + (end-start)/2;
        build(nodeIdx * 2, start, mid, nums);
        build(nodeIdx * 2 + 1, mid+1, end, nums);
        segment[nodeIdx] = merge(segment[nodeIdx*2], segment[nodeIdx*2+1]);
    }
    
    Node query(ll node, ll start, ll end, ll l, ll r){
        // cout << l << " " << r << " end, start: " << end << " " << start << endl;
        if(start > r || end < l) return {INT_MAX, INT_MIN};
        if(l <= start && r >= end) return segment[node];
        ll mid = start + (end-start)/2;
        Node left = query(node * 2, start, mid, l, r);
        Node right = query(node * 2 + 1, mid + 1, end, l, r);
        return merge(left, right);
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        segment.resize(4 * n);
        build(1, 0, n-1, nums);
        // for(auto &x: segment) cout << x.minVal << " " << x.maxVal << endl;
        priority_queue<tii> maxHeap;

        for(int i = 0; i < n; i++){
            Node result = query(1, 0, n-1, i, n-1);
            // cout << "a" << endl;
            // if(result.maxVal == INT_MAX && result.minVal == INT_MIN) continue;
            ll val = 1LL * (result.maxVal - result.minVal);
            // cout << "i:  " << i << " " << val << endl;
            maxHeap.push({val, i, n-1}); 
        }

        ll sumValue = 0;
        int counter = 0;
        while(!maxHeap.empty() && counter < k) {
            auto [val, l, r] = maxHeap.top();
            maxHeap.pop();
            // cout << val << " " << l << " " << r << endl;

            sumValue += val;
            if(l < r) {
                Node result = query(1, 0, n-1, l, r-1);
                // if(result.maxVal == INT_MAX && result.minVal == INT_MIN) continue;
                ll currVal = 1LL * (result.maxVal - result.minVal);
                maxHeap.push({currVal, l, r-1});
            }
            counter++;

        }

        return sumValue;
    }
};