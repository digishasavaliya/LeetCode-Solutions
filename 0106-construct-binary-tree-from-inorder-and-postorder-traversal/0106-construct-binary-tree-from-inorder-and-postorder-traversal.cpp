class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int> mp;

        for(int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return buildtree(postorder, 0, postorder.size()-1,inorder, 0, inorder.size()-1, mp);
    }

    TreeNode* buildtree(vector<int>& postorder, int ps, int pe,
                        vector<int>& inorder, int is, int ie,
                        unordered_map<int,int>& mp)
    {
        if(ps > pe || is > ie)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pe]);

        int iroot = mp[root->val];

        int num = iroot - is;

        
        root->right = buildtree(postorder, ps+num, pe-1,inorder, iroot+1, ie, mp);


        root->left = buildtree(postorder, ps, ps+num-1,inorder, is, iroot-1, mp);

        return root;
    }
};