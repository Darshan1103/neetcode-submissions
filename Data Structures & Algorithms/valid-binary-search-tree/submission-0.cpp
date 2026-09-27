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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        
        vector<int> values;
        inorder(root,values);

        for(int i = 0; i < values.size() - 1; i++){
            if(values[i] >= values[i+1]){
                return false;
            }
        }

        return true;
        
    }

    void inorder(TreeNode* root, vector<int>& values){

        if(root == NULL) return ;

        inorder(root->left,values);
        values.push_back(root->val);
        inorder(root->right,values);
    }
};
