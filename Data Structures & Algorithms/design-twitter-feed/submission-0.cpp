class Twitter {
public:
    unordered_map<int,unordered_set<int>> followees;
    using elem = pair<int,int>;
    unordered_map<int,priority_queue<elem,vector<elem>,greater<elem>>> posts;
    int timestamp;
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<elem,vector<elem>,greater<elem>> user_feed;
        followees[userId].insert(userId);
        for(auto& it: followees[userId]){
            auto pq = posts[it];
            while(!pq.empty()){
                user_feed.push(pq.top());
                if(user_feed.size()>10) user_feed.pop();
                pq.pop();
            }
        }
        vector<int> ans;
        while(user_feed.size()){
            ans.push_back(user_feed.top().second);
            user_feed.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto& st = followees[followerId];
        if(st.find(followeeId)!=st.end()){
            st.erase(followeeId);
        }
    }
};
