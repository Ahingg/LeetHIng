class Solution {
public:
    typedef pair<int, int> pos;
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pos> img1pos;
        // vector<pos> img2pos;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1) img1pos.push_back({i, j});
                // if(img2[i][j] == 1) img2pos.push_back({i, j});
            }
        }

        int ans = 0;
        // coba offset untuk setiap i dan j, masing masing positif
        for(int i = -1 * (n-1); i < n; i++) {
            
            for(int j = -1 * (n-1); j < n; j++) {
                // pilih salah satu antara img1 dan img2, karena salah satu pasti benar.
                // tinggal cek untuk setiap angka 1 di dalam img1
                // ketika di offset apakah hasil x,y nya di img2 adalah 1 juga
                // jika iya maka masukkan ke curr
                int count = 0;
                for(const auto& [y, x]: img1pos){
                    // cout << y << " " << x << endl;
                    int offY = y + i;
                    int offX = x + j;
                    if(offY >= n || offX >= n || offY < 0 || offX < 0) continue;
                    if(img2[offY][offX] == 1) count++;
                }
                ans = max(ans, count);
            }
        }
        
    
        return ans;
    }
};