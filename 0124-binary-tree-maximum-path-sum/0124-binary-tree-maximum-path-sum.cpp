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
    int maxi=INT_MIN;
    int maxPathSum(TreeNode* root) {
        int ans=height(root,maxi);
        return maxi;
    }
    int height(TreeNode* root,int & maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=max(0,height(root->left,maxi));
        int r=max(0,height(root->right,maxi));
        maxi=max(maxi,root->val+l+r);
        return root->val+max(l,r);
    }
};