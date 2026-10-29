
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        if (root == nullptr) {
            return ans;
        }

        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();

                level.push_back(front->val);

                if (front->left != nullptr) {
                    q.push(front->left);
                }

                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};
