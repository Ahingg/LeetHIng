class Solution {
public:
    int numSteps(string s) {
        int i = s.length() - 1;
        int stepCount = 0;
        while(i > 0){
            cout << "i: " << i << endl;
            cout << "before: " << s.substr(0, i+1) << endl;
            if(s[i] == '1') {
                // travel until we found a suitable 
                int j = i;
                while(j > 0 && s[j] != '0')  {
                    s[j] = '0';
                    j--;
                }
                stepCount++;
                if(j > 0) {
                    s[j] = '1';
                    cout << "Hit!" << endl;
                }
                else {
                    stepCount += i + 1;
                    return stepCount;
                }
                
            }
            else {
                cout << "Hit!2" << endl;
                stepCount++;
                i--;
            }
            cout << "After: " << s.substr(0, i+1) << endl;
        }
        return stepCount;
    }
};