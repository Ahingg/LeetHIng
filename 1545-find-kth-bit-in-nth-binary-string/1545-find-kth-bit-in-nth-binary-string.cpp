class Solution {
public:
    int preCompute[21];
    char process(int n, int k){
        // cout << "n, k: " << n << " " << k << endl;
        if(n == 1) return 0;
        int len = preCompute[n];
        int mid = ((len-1)/2) + 1;
        // cout << "len, mid: " << len << " " << mid << endl;
        if(k == mid) return 1;
        if(k > mid) {
            int x = !process(n-1, 2*mid - k);
            // cout << " k > return: " << x << endl;
            return !process(n-1, 2*mid - k);
        }
        int x = process(n-1, k);
        // cout << " k < return: " << x << endl;
        return process(n-1, k);
    }

    char findKthBit(int n, int k) {
        for(int i = 1; i < 21; i++) preCompute[i] = (preCompute[i-1] + 1)*2 - 1;
        return '0' + process(n, k);
    }
};