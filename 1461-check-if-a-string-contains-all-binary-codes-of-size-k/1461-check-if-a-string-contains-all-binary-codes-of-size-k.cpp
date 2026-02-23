class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int maximumValue = pow(2,k) - 1;
        int len = s.length();
        if(k >= len) return false;

        unordered_map<int, int> list;

        int currentValue = (s[0]-'0') & 1;
        for(int i = 1; i < k; i++){
            currentValue <<= 1;
            currentValue += s[i] - '0';
        }
        list[currentValue] = 1;
        // cout << currentValue << endl;
        for(int i = 1; i + k <= len; i++){
            currentValue <<= 1;
            currentValue += s[i+k-1] -'0';
            currentValue &= maximumValue;
            list[currentValue] = 1;
            // cout << i << ": " << currentValue << endl;
        }
        // cout << "size: " << list.size() << endl;
        return list.size() == maximumValue + 1;

    }
};