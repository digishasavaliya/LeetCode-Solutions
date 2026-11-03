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
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        TreeNode* root = buildtree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* buildtree(vector<int>& preorder,int ps,int pe, vector<int>& inorder,int is,int ie,unordered_map<int,int>& mp)
    {
        if(ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int iroot=mp[root->val];
        int num=iroot-is;
        root->left=buildtree(preorder,ps+1,ps+num,inorder,is,iroot-1,mp);
        root->right=buildtree(preorder,ps+num+1,pe,inorder,iroot+1,ie,mp);
        return root;
    }
};