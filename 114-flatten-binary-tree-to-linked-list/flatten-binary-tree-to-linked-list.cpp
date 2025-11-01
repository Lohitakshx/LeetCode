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
    void loki(TreeNode* root, TreeNode*& pre){
        if(!root) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        pre->right = root;
        pre->left= NULL;
        pre = root;
  
        loki(left, pre);
        loki(right, pre);
    }
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* dummy = new TreeNode(0);
        // if(root==NULL) return;
        // flatten(root->right);
        // flatten(root->left);
        // root->left=NULL;
        // root->right=prev;
        // prev=root;
        TreeNode* pre = dummy;
        loki(root, pre);
        root =dummy->right;
    }
};