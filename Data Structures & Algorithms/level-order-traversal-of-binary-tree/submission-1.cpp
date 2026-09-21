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
    vector<vector<int>> levelOrder(TreeNode* root) {
       if(root == NULL) return {};
       TreeNode* cur = root;
       vector<vector<int>> ans;
       map<int, vector<int>> mp;
       queue<tuple<TreeNode*,int>> q;

       q.push({cur,0});

       while(!q.empty()){
        auto[node,row] = q.front();
        q.pop();

        mp[row].push_back(node->val);

        if(node->left != NULL){
            q.push({node->left,row+1});
        }
        if(node->right != NULL){
            q.push({node->right, row+1});
        }
       }

       for(auto i : mp){
        vector<int> temp;
        for(auto c : i.second){
            temp.push_back(c);
        }
        ans.push_back(temp);
       }

        return ans;

    }
};
