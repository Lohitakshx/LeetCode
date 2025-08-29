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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int first , last;
            int minn = q.front().second;
            for(int n = 0; n<size; n++){
                auto i = q.front();
                long long id = i.second-minn;
                TreeNode* temp = i.first;
                q.pop();
                if(n==0) first = id;
                if(n==size-1) last = id;
                if(temp->left) q.push({temp->left, id*2+1});
                if(temp->right) q.push({temp->right, id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};