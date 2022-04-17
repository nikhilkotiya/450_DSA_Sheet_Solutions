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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* node=root;
        int sum=0;
        while(s.size()|| node!=NULL)
        {
            while(node!=NULL)
            {
                s.push(node);
                node=node->right;
            }
            node=s.top();
            sum+=node->val;
            node->val=sum;
            s.pop();
            node=node->left;
        }
        return root;
    }
};