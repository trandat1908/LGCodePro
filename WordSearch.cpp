// https://leetcode.com/problems/word-search/
/*
Practice link:  1. https://leetcode.com/problems/longest-mountain-in-array/ (mandatory) Use Dynamic Programming

                      2. https://leetcode.com/problems/domino-and-tromino-tiling/ (mandatory) Use Dynamic Programming

                      3. https://leetcode.com/problems/jump-game/ (mandatory)

                      4. https://leetcode.com/problems/container-with-most-water/ (mandatory)

Additional practice:

                      https://codepro.lge.com/exam/19/overseas-questions-for-previous-test/quiz/5 Use Dynamic Programming

                      https://leetcode.com/problems/longest-palindromic-substring/ Use Dynamic Programming

                      https://leetcode.com/problems/cheapest-flights-within-k-stops/ Use Dynamic Programming

                      

                      https://leetcode.com/problems/jump-game-ii/description/ Greedy

                      https://leetcode.com/problems/gas-station/ Greedy

                      https://leetcode.com/problems/partition-labels/ Greedy

　                  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/ Greedy
                   */



#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int,int>> pos;
    int visited[10][10] = {0};
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m, l;
    bool dfs(vector<vector<char>>& board,const string& word, pair<int, int> p, string s) {
        if((int)s.length() == l) {
            return true;
        }
        for(int i=0; i<4; ++i) {
            int tx = p.first + dx[i];
            int ty = p.second + dy[i];
            cout<<"tx= "<<tx<<" ty= "<<ty<<endl;
            cout<<"s= "<<s<<endl;
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&visited[tx][ty]==0) {
                if(board[tx][ty]==word[s.length()]) {
                    visited[tx][ty] = 1;
                    s.push_back(board[tx][ty]);
                    pair<int,int> pp = {tx, ty};
                    return dfs(board, word, pp, s);
                    s.pop_back();
                    visited[tx][ty] = 0;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();
        l = word.length();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(board[i][j]==word[0]) {
                    pos.push_back(make_pair(i, j));
                }
            }
        }


        for(int i=0; i<(int) pos.size(); ++i) {
            string s = "";
            visited[pos[i].first][pos[i].second] = 1;
            s.push_back(word[0]);
            if(dfs(board, word, pos[i], s))
                return true;
            visited[pos[i].first][pos[i].second] = 0;
        }
        return false;
    }
};

int main() {
    Solution *s = new Solution;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCEFSADEESE";
    cout << s->exist(board, word) << endl;
    return 0;
}
