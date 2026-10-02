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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* head = new TreeNode(preorder[0]);

        int idx = 0;
        while(inorder[idx] != preorder[0]) idx++;

        vector<int> leftinorder(inorder.begin(), inorder.begin()+idx);
        vector<int> rightinorder(inorder.begin()+idx+1, inorder.end());

        vector<int> leftpreorder(preorder.begin()+1, preorder.begin()+1+idx);
        vector<int> rightpreorder(preorder.begin()+1+idx, preorder.end());

        head->left = buildTree(leftpreorder, leftinorder);
        head->right = buildTree(rightpreorder, rightinorder);

        return head;
    }
};
