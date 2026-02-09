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
    vector<TreeNode*> nodes;
public:
    // typedef tuple<int, int, TreeNode*> hb;
    // TreeNode* m = nullptr;
    // void print(TreeNode* x){
    //     if(x == nullptr) return;
    //     print(x->left);
    //     cout << x->val << " ";
    //     print(x->right);
        
    // }

    // TreeNode *rotateRight(TreeNode* x) {
    //     // cout << "right on " << x->val << " ";
    //     TreeNode* l = x->left;
    //     TreeNode* lr = l->right;
    //     l->right = x; 
    //     x->left = lr;
    //     return l;
    // }

    // TreeNode *rotateLeft(TreeNode *x) {
    //     // cout << "left on " << x->val << " ";
    //     TreeNode* r = x->right;
    //     TreeNode* rl = r->left;
    //     r->left = x; 
    //     x->right = rl;
    //     return r;
    // }

    // TreeNode *manage(TreeNode* x, int dif, int lb, int rb){
    //     if(dif > 1 && lb >= 0) {
    //         return rotateRight(x);
    //     }

    //     if(dif > 1 && lb < 0) {
    //         x->left = rotateLeft(x->left);
    //         return rotateRight(x);
    //     }

    //     if(dif < -1 && rb <= 0 ) {
    //         return rotateLeft(x);
    //     }

    //     if(dif < -1 && rb > 0) {
    //         x->right = rotateRight(x->right);
    //         return rotateLeft(x);
    //     }
    //     return x;
    // }

    // hb getBalance(TreeNode* x) {
    //     if(x == nullptr) return {0, 0, x};
    //     auto [lh, lb, l] = getBalance(x->left);
    //     auto [rh, rb, r] = getBalance(x->right);
    //     int dif = lh-rh;
    //     if(dif > 1 || dif < -1) {
    //         x = manage(x, dif, lb, rb);
    //         print(m);
    //         cout << endl;
    //         return getBalance(x);
    //     }
    //     return {1 + max(lh,rh), dif, x};
    // }

    void traverse(TreeNode* x){
        if(!x) return;
        traverse(x->left);
        nodes.push_back(x);
        traverse(x->right);
    }

    TreeNode* construct(int start, int end){
        if(start > end) return nullptr;
        int mid = start + (end-start)/2;
        TreeNode* node = nodes[mid];

        node->left = construct(start, mid-1);
        node->right = construct(mid+1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        traverse(root);
        return construct(0, nodes.size()-1);
    }
};