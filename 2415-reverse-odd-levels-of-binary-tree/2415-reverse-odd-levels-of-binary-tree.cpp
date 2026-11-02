class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        if(root == NULL) return root;

        queue<TreeNode*> q;
        q.push(root);

        int l = 0;

        while(!q.empty())
        {
            int n = q.size();
            vector<TreeNode*> level;

            for(int i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                q.pop();

                level.push_back(front);

                if(front->left)
                    q.push(front->left);

                if(front->right)
                    q.push(front->right);
            }

            if(l % 2 != 0)
            {
                int i = 0;
                int j = level.size() - 1;

                while(i < j)
                {
                    swap(level[i]->val, level[j]->val);
                    i++;
                    j--;
                }
            }

            l++;
        }

        return root;
    }
};