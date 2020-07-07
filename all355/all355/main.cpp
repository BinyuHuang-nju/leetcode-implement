#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Twitter {
private:
    struct TwitterInfo {
        int tweetId;
        int userId;
        TwitterInfo(int u, int t) :tweetId(t), userId(u) {}
    };
    vector<map<int,int>> follow_table;
    vector<TwitterInfo> twitter_table;
public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        TwitterInfo tweet(userId, tweetId);
        twitter_table.push_back(tweet);
        if (userId > follow_table.size()) {
            map<int, int> t;
            for (int i = follow_table.size(); i < userId; i++)
                follow_table.push_back(t);
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if (userId > follow_table.size()) {
            map<int, int> t;
            for (int i = follow_table.size(); i < userId; i++)
                follow_table.push_back(t);
        }
        vector<int> results;
        for (int i = twitter_table.size() - 1; i >= 0; i--) {
            if (twitter_table[i].userId == userId || \
                (follow_table[userId-1].count(twitter_table[i].userId) && follow_table[userId-1][twitter_table[i].userId]))
                results.push_back(twitter_table[i].tweetId);
            if (results.size() == 10)
                    break;
        }
        return results;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        int max = followerId > followeeId ? followerId : followeeId;
        if (max > follow_table.size()) {
            map<int, int> t;
            for (int i = follow_table.size(); i < max; i++)
                follow_table.push_back(t);
        }
        follow_table[followerId-1][followeeId] = 1;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        int max = followerId > followeeId ? followerId : followeeId;
        if (max > follow_table.size()) {
            map<int, int> t;
            for (int i = follow_table.size(); i < max; i++)
                follow_table.push_back(t);
        }
        follow_table[followerId-1][followeeId] = 0;
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(2, 5);
    twitter.postTweet(1, 3);
    twitter.postTweet(1, 101);
    twitter.postTweet(2, 13);
    twitter.postTweet(2, 10);
    twitter.postTweet(1, 2);
    twitter.postTweet(2, 94);
    twitter.postTweet(2, 505);
    twitter.postTweet(1, 333);
    twitter.postTweet(1, 22);
    twitter.getNewsFeed(2);
    twitter.follow(2, 1);
    twitter.getNewsFeed(2);

    return 0;

}