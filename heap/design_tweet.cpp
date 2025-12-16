



#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    // global timestamp to maintain tweet order
    int timeStamp;

    // userId -> list of {time, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweets;

    // follower -> set of followees
    unordered_map<int, unordered_set<int>> following; // we used unordered_set to avoid duplicate followees and for O(1) access

public:
    Twitter() {
        timeStamp = 0;
    }
//TC:O(1)
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
//TC:O(n log n) where n is total number of tweets from user and followees
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // user should follow themselves
        following[userId].insert(userId);

        // max heap based on timestamp
        priority_queue<pair<int,int>> pq;

        // push all tweets of user and followees
        for (int followee : following[userId]) {
            for (auto &t : tweets[followee]) {
                pq.push(t);  // {time, tweetId}
            }
        }

        // take top 10 recent tweets
        while (!pq.empty() && result.size() < 10) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
//TC:O(1)
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
//TC:O(1)
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) { // cannot unfollow oneself we can ignore this case
            following[followerId].erase(followeeId);
        }
    }
};
