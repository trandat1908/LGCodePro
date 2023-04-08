//https://leetcode.com/problems/word-search-ii/description/

class TrieNode {
public:
    string word;
    vector<TrieNode*> children;
    bool isWord = false;
    TrieNode() : children(26, nullptr) {
        isWord = false;
    }
};

class Solution {
private:
    void putNode(const string& s, TrieNode *node, int index_) {
        int pos = s[index_] - 'a';
        if(node->children[pos]==nullptr) {
            node->children[pos] = new TrieNode();
            node->children[pos]->word = s[index_];
        }
        if(index_ == (s.length()-1)) {
            node->children[pos]->isWord = true;
            node->children[pos]->word = s;
            return;
        } else {
            putNode(s, node->children[pos], index_ + 1);
        }
    }

    void dfs(vector<vector<char>> &board, set<string> &res, vector<vector<bool>>& visited,TrieNode *curNode, int x, int y) {
        if(x<0||x>=board.size()||y<0||y>=board[0].size()) return;
        int i = board[x][y]-'a';
        curNode = curNode->children[i];
        if(visited[x][y] || curNode==nullptr) return;
        if(curNode->isWord) {
            res.insert(curNode->word);
        }
        visited[x][y] = true;

        dfs(board, res, visited, curNode, x+1, y);
        dfs(board, res, visited, curNode, x-1, y);
        dfs(board, res, visited, curNode, x, y+1);
        dfs(board, res, visited, curNode, x, y-1);
        visited[x][y] = false;
    }
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        set<string> res;
        TrieNode *root = new TrieNode();
        for(string s : words) {
            putNode(s, root, 0);
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0; i<(int) board.size(); ++i) {
            for(int j=0; j<(int) board[0].size(); ++j) {
                dfs(board, res, visited, root, i, j);
            }
        }
        vector<string> ans(res.begin(), res.end());
        return ans;
    }
};


class Solution {
public:
    unordered_map<char, vector<pair<int,int>>> mMap;
    int visited[10][10] = {0};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m, l;
    bool dfs(vector<vector<char>>& board,const string& word, pair<int, int> p, string s) {
        if(s.length() == l) {
            return true;
        }
        for(int i=0; i<4; ++i) {
            int tx = p.first + dx[i];
            int ty = p.second + dy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&visited[tx][ty]==0) {
                if(board[tx][ty]==word[s.length()]) {
                    visited[tx][ty] = 1;
                    s += board[tx][ty];
                    if(dfs(board, word, make_pair(tx, ty), s)) {
                        visited[tx][ty] = 0;
                        return true;
                    }
                    s.pop_back();
                    visited[tx][ty] = 0;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        l = word.length();
        unordered_map<char, vector<pair<int,int>>>::iterator it;
        if(mMap.find(word[0]) != mMap.end()) {
            for(int i=0; i< mMap[word[0]].size(); ++i) {
                string s = "";
                int x = mMap[word[0]][i].first;
                int y = mMap[word[0]][i].second;
                visited[x][y] = 1;
                s += word[0];
                if(dfs(board, word, mMap[word[0]][i], s))
                {
                    visited[x][y] = 0;
                    return true;
                }
                visited[x][y] = 0;     
            }
        }
        
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                mMap[board[i][j]].push_back({i, j});
            }
        }
        vector<string> results;
        for(int i=0; i<words.size(); i++) {
            if(exist(board, words[i])) {
                results.push_back(words[i]);
            }
        }
        return results;
    }
};
