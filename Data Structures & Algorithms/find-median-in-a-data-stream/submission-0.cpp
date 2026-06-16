class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> large;
    priority_queue<int> small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(large.size() && num>large.top()){
            large.push(num);
        }
        else small.push(num);
        if(small.size()>large.size()+1){
            large.push(small.top());
            small.pop();
        }
        if(large.size()>small.size()+1){
            small.push(large.top());
            large.pop();
        }

    }
    
    double findMedian() {
        if(small.size()==large.size()){
            return (small.top()+large.top())/2.0;
        }
        else if(small.size()>large.size()){
            return small.top();
        }
        else return large.top();
    }
};
