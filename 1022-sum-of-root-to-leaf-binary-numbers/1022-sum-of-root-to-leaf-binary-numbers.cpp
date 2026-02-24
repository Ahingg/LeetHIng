/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int getSum(TreeNode* x, int sum){
        if(x == nullptr) return -1;
        sum += x->val;
        sum <<= 1;
        int left = getSum(x->left, sum);
        int right = getSum(x->right, sum);

        if(left == -1 && right == -1) {
            // cout << "Sum when returned: " << sum << endl;
            return sum >>= 1;
        }
        if(left == -1) return right;
        if(right == -1) return left;
        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        return getSum(root, 0);
    }
};