class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        // dif >= 1

        // case ganjil semua
        // case genap semua

        int n = nums.size();
        if(n == 1) return true;
        // yang paling kecil tidak bisa di replace...1
        // yang paling besar tidak bisa dipakai
        // simpen index
        int smallestOdd  = -1;
        int smallestEven = -1;
        for(int i = 0; i < n; i++) {
            int& v = (nums[i] & 1) ? smallestOdd : smallestEven;
            if(v == -1) {
                v = i;
                continue;
            }

            if(nums[i] < nums[v]) {
                v = i;
            }
        }

        if(smallestOdd == -1 || smallestEven == -1) return true;
        bool oddCan = true;
        // coba setir ke ganjil semua=
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) continue;
            if(nums[i] < nums[smallestOdd]) {
                oddCan = false;
                break;
            }
        }
        bool evenCan = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) continue;
            if(i == smallestOdd || nums[i] < nums[smallestOdd]) {
                evenCan = false;
            }
        }

        return evenCan || oddCan;

    }
};