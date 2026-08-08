class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = word1.length();
        int m = word2.length();

        vector<int> last_pos(m, -1);

        int p = n-1;

        for(int j = m-1; j >= 0; j--) {
            while(p >= 0 && word1[p] != word2[j]) p--;
            last_pos[j] = p;
            if(p >= 0) p--;
        }

        vector<int> ans;
        bool used = false;

        int j = 0;
        for(int i = 0; i < n && j < m; i++) {
            bool matched = (word1[i] == word2[j]);
            if(matched) {
                ans.push_back(i);
                j++;
            }
            else if(!used) {
                bool fit = (j+1 == m) || (i < last_pos[j+1]);
                if(fit) {
                    ans.push_back(i);
                    used = true;
                    j++;
                }
            }
        }

        if(j < m) return {};
        return ans;

    }
};