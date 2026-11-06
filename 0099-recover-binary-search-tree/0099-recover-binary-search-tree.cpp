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
    TreeNode* f;
    TreeNode* m;
    TreeNode* l;
    TreeNode* p;
public:
    void recoverTree(TreeNode* root) {
        f=m=l=NULL;
        inorder(root);
        if(f&&l) swap(f->val,l->val);
        else if(f&&m) swap(f->val,m->val);
         
        
    }
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        if(p!=NULL && root->val<p->val)
        {
            if(f==NULL)
            {
                f=p;
                m=root;
            }
            else
            {
                l=root;
            }

        }
        p=root;
        inorder(root->right);
        
    }
};
