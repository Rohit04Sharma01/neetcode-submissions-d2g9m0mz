class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }
};

class Solution {
public:
    vector<int> dp;

    int solve(int idx, string &s, Trie &trie) {
        int n = s.size();

        if (idx == n)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        // Option 1: treat current character as extra
        int ans = 1 + solve(idx + 1, s, trie);

        // Option 2: match dictionary words
        TrieNode* curr = trie.root;

        for (int j = idx; j < n; j++) {
            int letter = s[j] - 'a';

            if (curr->children[letter] == nullptr)
                break;

            curr = curr->children[letter];

            if (curr->isEnd) {
                ans = min(ans, solve(j + 1, s, trie));
            }
        }

        return dp[idx] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;

        for (string &word : dictionary)
            trie.insert(word);

        dp.assign(s.size(), -1);

        return solve(0, s, trie);
    }
};