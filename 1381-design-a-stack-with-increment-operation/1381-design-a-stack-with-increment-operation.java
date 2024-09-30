class CustomStack {
    int maxSize;
    List<Integer> stk;

    public CustomStack(int maxSize) {
        this.maxSize = maxSize;
        this.stk = new ArrayList<>();
    }

    public void push(int x) {
        if (stk.size() < maxSize) {
            stk.add(x);
        }
    }

    public int pop() {
        if (!stk.isEmpty()) {
            return stk.remove(stk.size() - 1);
        }
        return -1;
    }

    public void increment(int k, int val) {
        for (int i = 0; i < Math.min(k, stk.size()); i++) {
            stk.set(i, stk.get(i) + val);
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */