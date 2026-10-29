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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        if(root==NULL)
        {
            return ans;
        }
        q.push(root);
        while(!q.empty())
        {
           
            int n=q.size();
            double sum=0;
          
            for(int i=0;i<n;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                sum=sum+front->val;
                if(front->left!=NULL)
                {
                    q.push(front->left);
                }
                 if(front->right!=NULL)
                {
                    q.push(front->right);
                }
            }
           
            double a=sum/n;
            ans.push_back(a);
        }
      return ans;  
    }
};