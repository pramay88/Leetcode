class Solution {
    int mah(vector<int> arr){
        int n = arr.size();
        vector<int> nsl(n, -1), nsr(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) nsl[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) nsr[i] = st.top();
            st.push(i);
        }

        int maxx = 0;
        for(int i = 0; i < n; i++){
            int width = nsr[i] - nsl[i] - 1;
            maxx = max(maxx, arr[i] * width);
        }
        return maxx;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), area = 0;
        vector<int> heights(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
                cout << heights[j] << " ";
            }
            cout<<endl;
            area = max(area, mah(heights));
        }
        return area;
    }
};