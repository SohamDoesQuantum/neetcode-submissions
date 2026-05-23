class StockSpanner {
public:
    vector<int>prices;
    StockSpanner() {
    }
    int next(int price) {
        prices.push_back(price);
        int i = prices.size()-1;
        int cnt = 0;
        while(i>=0 && price>=prices[i]){
            cnt++;
            i--;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */