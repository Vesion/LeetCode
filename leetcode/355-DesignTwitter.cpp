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
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> posts;
    int timestamp;

    using vpit = vector<pair<int,int>>::iterator;
    struct Cmp {
        bool operator() (const pair<vpit, vpit>& p1, const pair<vpit, vpit>& p2) {
            return p1.first->first < p2.first->first;
        }
    };
    
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp++, tweetId});
    }
    
    // O(n + kn), n is the number of followees + itself, k is the number tweets we want to get
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<vpit,vpit>, vector<pair<vpit,vpit>>, Cmp> pq;
        // push all n bounds into pq
        if (!posts[userId].empty()) pq.push({--posts[userId].end(), posts[userId].begin()});
        for (int followee : follows[userId]) {
            if (!posts[followee].empty()) pq.push({--posts[followee].end(), posts[followee].begin()});
        }

        vector<int> res;
        // retrieve tweets at most k times
        while (!pq.empty() && res.size() < 10) {
            auto t = pq.top(); pq.pop();
            res.push_back(t.first->second);
            if (--t.first >= t.second) pq.push({t.first, t.second});
        }
        return res;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};


int main() {
    Twitter t;
    t.postTweet(1, 5);
    for (auto& e : t.getNewsFeed(1)) cout << e << " "; cout << endl; 
    t.follow(1, 2);
    t.postTweet(2, 6);
    for (auto& e : t.getNewsFeed(1)) cout << e << " "; cout << endl; 
    t.unfollow(1, 2);
    for (auto& e : t.getNewsFeed(1)) cout << e << " "; cout << endl; 
    return 0;
}

