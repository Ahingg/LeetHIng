class Solution {
public:

    int count = 0;
    string bloom(int n, int k, char curr){
        if(n == 1) {
            count++;
            string x = "";
            if(count == k) return x + curr;
            return "";            
        }
        char first, second;
        switch(curr) {
            case 'a':
                first = 'b';
                second = 'c';
                break;
            case 'b':
                first = 'a';
                second = 'c';
                break;
            case 'c':
                first = 'a';
                second = 'b';
                break;
        }

        // cout << "Curr: " << curr << " Next: " << first << endl << endl;
        // cout << count << " " << curr << endl;
        string left = bloom(n-1, k, first);
        if(left != "") return curr + left; 
        string right = bloom(n-1, k, second);
        if(right != "") return curr + right;

        return "";
    }
    string getHappyString(int n, int k) {
        if(n == 1){
            char x = 'a' + k - 1;
            string y = "";
            if(k <= 3) return y + x;
            else return "";
        } 
        string a = bloom(n, k, 'a');
        if(a != "") return a;
        string b = bloom(n, k, 'b');
        if(b != "") return b;
        string c = bloom(n, k, 'c');
        if(c != "") return c;
        // cout << a << " | " << b << " | " << c << endl;
        return "";
    }
};