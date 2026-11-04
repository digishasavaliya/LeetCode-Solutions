class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> pv;

        parentvisit(root, pv);

        int level = 0;

        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, bool> mp;
        mp[target] = true;

        while(!q.empty())
        {
            if(level == k) break;

            level++;

            int n = q.size();

            for(int i = 0; i < n; i++)
            {
                TreeNode* front = q.front();
                q.pop();

                if(front->left && !mp[front->left])
                {
                    q.push(front->left);
                    mp[front->left] = true;
                }

                if(front->right && !mp[front->right])
                {
                    q.push(front->right);
                    mp[front->right] = true;
                }

                if(pv.count(front) && !mp[pv[front]])
                {
                    q.push(pv[front]);
                    mp[pv[front]] = true;
                }
            }
        }

        vector<int> res;

        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }

        return res;
    }

    void parentvisit(TreeNode* root,
        unordered_map<TreeNode*, TreeNode*>& mp)
    {
        if(root == NULL) return;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left)
            {
                mp[cur->left] = cur;
                q.push(cur->left);
            }

            if(cur->right)
            {
                mp[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }
};