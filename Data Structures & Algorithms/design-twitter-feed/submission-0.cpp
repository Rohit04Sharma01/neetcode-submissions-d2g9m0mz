class User {
public:
    vector<int> followingList;
    vector<pair<int, int>> tweets; 
    // {time, tweetId}

    User() {}

    void postTweet(int tweetId, int time) {
        tweets.push_back({time, tweetId});
    }

    void actionFollow(int userId) {
        // avoid duplicate follow
        for (int id : followingList) {
            if (id == userId) {
                return;
            }
        }

        followingList.push_back(userId);
    }

    void actionUnfollow(int userId) {
        int n = followingList.size();

        for (int i = 0; i < n; i++) {
            if (followingList[i] == userId) {
                followingList.erase(
                    followingList.begin() + i
                );
                return;
            }
        }
    }
};

class Twitter {
    vector<User*> users;
    int counter;

public:
    Twitter() {
        users.resize(501, nullptr);
        counter = 0;
    }

    void postTweet(int userId, int tweetId) {

        // create user if absent
        if (users[userId] == nullptr) {
            users[userId] = new User();
        }

        users[userId]->postTweet(
            tweetId,
            counter
        );

        counter++;
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> result;

        if (users[userId] == nullptr) {
            return result;
        }

        // min heap of size 10
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // include self tweets
        vector<int> followingList =
            users[userId]->followingList;

        followingList.push_back(userId);

        for (int f : followingList) {

            if (users[f] == nullptr) {
                continue;
            }

            for (auto [time, tweetId]
                 : users[f]->tweets) {

                pq.push({time, tweetId});

                if (pq.size() > 10) {
                    pq.pop();
                }
            }
        }

        while (!pq.empty()) {
            result.push_back(
                pq.top().second
            );

            pq.pop();
        }

        reverse(
            result.begin(),
            result.end()
        );

        return result;
    }

    void follow(
        int followerId,
        int followeeId
    ) {

        if (followerId == followeeId) {
            return;
        }

        if (users[followerId] == nullptr) {
            users[followerId] =
                new User();
        }

        if (users[followeeId] == nullptr) {
            users[followeeId] =
                new User();
        }

        users[followerId]->
            actionFollow(followeeId);
    }

    void unfollow(
        int followerId,
        int followeeId
    ) {

        if (users[followerId] == nullptr ||
            followerId == followeeId) {
            return;
        }

        users[followerId]->
            actionUnfollow(followeeId);
    }
};