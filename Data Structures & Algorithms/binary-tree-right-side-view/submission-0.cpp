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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        TreeNode* cur = root;
        vector<int> ans;
        queue<tuple<TreeNode*,int>> q;
        map<int, int>mp;

        q.push({cur,0});

        while(!q.empty()){
            auto [node,row] = q.front();
            q.pop();

            mp[row] = node->val;
            
            if(node->left != NULL){
                q.push({node->left,row+1});
            }
            if(node->right != NULL){
                q.push({node->right,row+1});
            }
        }

        for(auto c : mp){
            ans.push_back(c.second);
        }

        return ans;
    }
};
