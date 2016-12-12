#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
#include <unordered_set> 
#include <queue> 
using namespace std;


class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> follows;
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for (auto& p : posts[userId]) { // get self's news
            q.push(p);
            if (q.size() > 10) q.pop();
        }
        for (auto& followee : follows[userId]) { // get followers' news
            if (followee == userId) continue;
            for (auto& p : posts[followee]) {
                q.push(p);
                if (q.size() > 10) q.pop();
            }
        }

        vector<int> news;
        while (!q.empty()) {
            news.push_back(q.top().second);
            q.pop();
        }
        reverse(news.begin(), news.end());
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);    
    }
};


int main() {
    return 0;
}


