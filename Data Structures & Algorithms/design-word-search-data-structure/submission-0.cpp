class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char& ch: word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        return;
    }
    
    bool utility(string word, TrieNode* root) {
        TrieNode* curr = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr->children[j] != nullptr && utility(word.substr(i + 1), curr->children[j])) {
                        return true; 
                    }
                }
                return false;
            } else {
                int idx = word[i] - 'a';
                if (curr->children[idx] == nullptr) {
                    return false;
                }
                curr = curr->children[idx];
            }
        }
        return curr->isEnd;
    }

    bool search(string word) {
        return utility(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */