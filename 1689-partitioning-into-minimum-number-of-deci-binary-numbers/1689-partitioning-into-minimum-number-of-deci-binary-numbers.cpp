class Solution {
public:
    int minPartitions(string n) {
        char maximumDigit = '0';
        for(char c: n) if(c > maximumDigit) maximumDigit = c;
        return maximumDigit - '0';
    }
};