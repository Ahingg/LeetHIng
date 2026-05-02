class Solution {
    public:
    vector<int> datas = {0, 0, 1, 1, 1, 2, 3, 3, 3, 4};
    vector<int> check = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1};

    int good(int n){
        int rotatePossible = 0;
        while(n) {
            int m = n%10;
            if(m == 4 || m == 7 || m == 3) return 0;
            if(check[m]) rotatePossible = 1;
            n /= 10;
        }

        return rotatePossible;
    }
    int rotatedDigits(int n) {
        // 0..10
        if(n < 10) return datas[n];
        

        for(int i = 10; i <= n; i++) {
            int prev = datas[i-1];
            int left = good(i);
            // cout << "i, total: " << i << " " << (prev+left) << endl; 

            datas.push_back(prev + left);
        }

        return datas[n];
    }
};