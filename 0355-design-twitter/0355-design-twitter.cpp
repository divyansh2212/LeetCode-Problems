class Twitter {
    map<int, set<int>> followList;
    int num_posts;
    set<vector<int>, greater<vector<int>>> posts;
public:
    Twitter() {
        followList.clear();
        num_posts = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        num_posts++;
        posts.insert({num_posts, userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(auto &it : posts)
        {
            if(ans.size() == 10) break;
            if(userId == it[1] || followList[userId].find(it[1]) != followList[userId].end()) {
                ans.push_back(it[2]);
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */