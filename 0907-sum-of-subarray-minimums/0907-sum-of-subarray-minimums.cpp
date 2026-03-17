class Solution {
    vector<int> ns(vector<int> &arr, int n){
        vector<int> nse(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> ps(vector<int> &arr, int n){
        vector<int> pse(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), MOD = 1e9 + 7;
        long long sum = 0;

        vector<int> nse = ns(arr, n);
        vector<int> pse = ps(arr, n);

        for(int i = 0; i < n; i++){
            long long contrib = (1LL * arr[i] * (i - pse[i]) % MOD * (nse[i] - i) % MOD);
            sum = (sum + contrib) % MOD;
        }

        return sum;
    }
};