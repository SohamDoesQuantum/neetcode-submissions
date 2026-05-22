class FreqStack {
public:
    priority_queue<vector<int>> pq;
    unordered_map<int,int> mp;
    int timer;
    FreqStack() {
        timer = 0;
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],timer,val});
        timer++;
    }
    
    int pop() {
        int x = pq.top()[2];
        pq.pop();
        mp[x]--;
        return x;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */