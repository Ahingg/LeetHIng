class Solution {
public:
    bool sumGame(string num) {
        // optimalnya itu antara A kecilin yang lebih kecil sehingga B gabisa naikin lagi

        // atau, bisa saling cancel out
        int len = num.length();
        int mid = len / 2;

        int ql = 0, sl = 0;
        int qr = 0, sr = 0;
        for(int i = 0; i < mid; i++) {
            if(num[i] >= '0' && num[i] <= '9') sl += num[i] - '0';
            else ql++;
        }

        for(int i = mid; i < len; i++) {
            if(num[i] >= '0' && num[i] <= '9') sr += num[i] - '0';
            else qr++;
        }

        // if(ql + qr == 0) return sl != sr;
        if(ql == qr) {
            return sl != sr;
        }

        if((ql + qr) & 1) return true;
        return (9 * (qr-ql) != (2 * (sl-sr))) ;
    }
};