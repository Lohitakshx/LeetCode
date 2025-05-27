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
    bool isSymmetric(TreeNode* root) {
        return loki(root->left, root->right);
    }

private:
    bool loki(TreeNode* n1, TreeNode* n2){
        if(n1==NULL && n2==NULL) return true;
        if(n1==NULL || n2==NULL) return false;
        return n1->val==n2->val && loki(n1->right, n2->left) && loki(n2->right, n1->left);
    }
};