#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque> 
#include <map> 
#include <set> 
using namespace std;


class Twitter {
private:
    map<int, vector<pair<int, int>>> posts;
    map<int, set<int>> follows;
    int timestamp;

    struct Cmp {
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
            return p1.first > p2.first;
        }
    };

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pair<int, int>, Cmp> snews;
        for (auto& p : posts[userId]) {
            snews.insert(p);
            if (snews.size() > 10) snews.erase(--snews.end());
        }
        for (auto& followee : follows[userId]) {
            for (auto& p : posts[followee]) {
                snews.insert(p);
                if (snews.size() > 10) snews.erase(--snews.end());
            }
        }

        vector<int> news;
        for (auto& p : snews) news.push_back(p.second);
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
    Twitter t; 
    t.postTweet(1, 10);
    for (auto& e : t.getNewsFeed(1)) cout << e << " "; cout << endl; 
    t.follow(1, 2);
    for (int i = 0; i < 20; ++i) { 
         t.postTweet(2, i);
    } 
    for (auto& e : t.getNewsFeed(1)) cout << e << " "; cout << endl; 
    t.unfollow(1, 2);
    for (auto& e : t.getNewsFeed(1)) cout << e << " "; cout << endl; 

    for (auto& e : t.getNewsFeed(0)) cout << e << " "; cout << endl; 
    return 0;
}
