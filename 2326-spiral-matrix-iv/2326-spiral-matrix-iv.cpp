/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
       vector<vector<int>> ans(m, vector<int>(n, -1));
        if (m == 1 && n == 1) {
            ans[0][0] = head->val;
            return ans;
        }
        for (int c = 0; head != nullptr; ++c) {
            for (int j = c; (j + 1 + c) < n && head != nullptr; ++j, head = head->next) {
                ans[c][j] = head->val;
            }
            for (int i = c; i + 1 + c < m && head != nullptr; ++i, head = head->next) {
                ans[i][n - 1 - c] = head->val;
            }
            for (int j = n - 1 - c; j > c && head != nullptr; --j, head = head->next) {
                ans[m - 1 - c][j] = head->val;
            }
            for (int i = m - 1 - c; i > c && head != nullptr; --i, head = head->next) {
                ans[i][c] = head->val;
            }
        }
        return ans;
    }

};