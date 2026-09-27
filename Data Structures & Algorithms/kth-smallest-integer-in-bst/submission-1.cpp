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
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;

        vector<int> values;
        inorder(root,values);

        return values[k-1];
    }

    void inorder(TreeNode* root, vector<int>& values){
        if(root == nullptr) return;

        inorder(root->left,values);
        values.push_back(root->val);
        inorder(root->right,values);

    }
};


// optimal answer using stack 

// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*> st;
//         TreeNode* curr = root;

//         while (curr || !st.empty()) {
//             // Go as far left as possible
//             while (curr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }

//             // Visit node
//             curr = st.top();
//             st.pop();

//             k--;
//             if (k == 0)
//                 return curr->val;

//             // Move to right subtree
//             curr = curr->right;
//         }

//         return -1;
//     }
// };
