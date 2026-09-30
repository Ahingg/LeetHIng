class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // as seq is a valid parenthesis, 
        // then we can say that the whole string of len n
        int len = seq.length();

        // taking this into consideration, every a and b should always start with an open parenthesis
        // then we need to take the minimum value possible of max(depth(a), depth(b))
        // thus, we can try to take as much open parenthesis as possible
        // the count of open parenthesis and close parenthesis would always be len/2

        // depth of a sequence dcan be denoted as
        // the amount of open it can retrieve before being closed
        vector<int> ans;
        int balance = 1;
        for(int i = 0; i < len; i++) {
            if(seq[i] == '(') balance++;
            ans.push_back(balance % 2);
            if(seq[i] == ')') balance--;
        }
        return ans;
    }
};