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
    int getHeight(TreeNode* x){
        if(x == nullptr) return 0;
        int leftH = getHeight(x->left);
        int rightH = getHeight(x->right);
        if(leftH == -1 || rightH == -1) return -1;
        if(abs(leftH - rightH) > 1) return -1;
        
        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};