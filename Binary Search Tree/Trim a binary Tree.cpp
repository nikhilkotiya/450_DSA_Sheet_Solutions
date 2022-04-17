class Solution {
public:
    TreeNode* rec(TreeNode* root,int low,int high)
    {
        if(root==NULL)
        {
            return NULL;    
        }
        if(root->val<low)
        {
            // if root value less than low it mean the value not belong to given range so we need to 
            // delete that value.
            // if root value is less than low so every value on its left is less than low because the
            // property of binary tree and we need to take care about right
            // so we are change our root to root->right.
            return root=rec(root->right,low,high);
            
        }
        if(root->val>high)
        {
            // opposite case as low.
            return root=rec(root->left,low,high);    
        }
        // recursion calling
        root->left=rec(root->left,low,high);
        root->right=rec(root->right,low,high);
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //in this q we need to delete if the value of root is not in range of [low,high]
        return rec(root,low,high);
    }
};