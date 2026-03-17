class Solution {
    int n;
    
    vector<int> ng(vector<int> &arr){
        vector<int> v(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty()) v[i] = st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> pg(vector<int> &arr){
        vector<int> v(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if(!st.empty()) v[i] = st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> ns(vector<int> & arr){
        vector<int> v(n, n);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) v[i] = st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> ps(vector<int> & arr){
        vector<int> v(n, -1);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) v[i] = st.top();
            st.push(i);
        }
        return v;
    }

    long long maximum(vector<int> &arr){
        long long sum = 0;
        
        vector<int> nge = ng(arr);
        vector<int> pge = pg(arr);

        for(int i = 0; i < n; i++){
            long long right = nge[i] - i;
            long long left = i - pge[i];
            long long contrib = left * right * arr[i];
            sum += contrib;
        }
        return sum;
    }

    long long minimum(vector<int> &arr){
        long long sum = 0;
        
        vector<int> nse = ns(arr);
        vector<int> pse = ps(arr);

        for(int i = 0; i < n; i++){
            long long right = nse[i] - i;
            long long left = i - pse[i];
            long long contrib = left * right * arr[i];
            sum += contrib;
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();

        long long maxx = maximum(nums);
        long long minn = minimum(nums);

        return maxx - minn;

    }
};