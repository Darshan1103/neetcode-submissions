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
    int goodNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int goodnodes = 0;
        TreeNode* cur = root;
        queue<pair<TreeNode*,int>> q;

        q.push({cur,cur->val});

        while(q.size()){
            TreeNode* cur = q.front().first;
            int maxval = q.front().second;
            q.pop();

            if(cur->val >= maxval){
                goodnodes++;
            }

            maxval = max(maxval,cur->val);

            if(cur->left != NULL){
                q.push({cur->left,maxval});
            }
            if(cur->right != NULL){
                q.push({cur->right,maxval});
            }
        }

        return goodnodes; 
        
    }
};
