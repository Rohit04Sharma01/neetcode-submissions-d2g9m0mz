class CountSquares {
   private:
    unordered_map<int, vector<pair<int, int>>> XAxisPoints;
    unordered_map<int, vector<pair<int, int>>> YAxisPoints;

    struct Hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    unordered_map<pair<int, int>, int, Hash> freq;

   public:
    CountSquares() {}

    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        XAxisPoints[x].push_back({x, y});
        YAxisPoints[y].push_back({x, y});
        freq[{x, y}]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int res = 0;

        for (auto& XAxisPoint : XAxisPoints[x]) {
            int y1 = XAxisPoint.second;
            int disX = abs(y - y1);

            if (disX == 0) continue;

            for (auto& YAxisPoint : YAxisPoints[y]) {
                int x1 = YAxisPoint.first;
                int disY = abs(x - x1);

                if (disX != disY) continue;

                // Count all copies of the fourth point
                res += freq[{x1, y1}];
            }
        }

        return res;
    }
};
