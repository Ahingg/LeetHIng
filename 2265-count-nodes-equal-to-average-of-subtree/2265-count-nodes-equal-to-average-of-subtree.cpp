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
    typedef pair<int, int> pii;
    int count = 0;
    pii traverse(TreeNode *curr) {
        if(curr == nullptr) return {0, 0};
        pii left = traverse(curr->left);
        pii right = traverse(curr->right);
        int cnt = left.second + right.second + 1;
        int total = left.first + right.first + curr->val;
        if(((int)(total / cnt)) == curr->val) count++;
        return {total, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return count;
    }
};