https://leetcode.com/problems/bus-routes/description/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        set<int> ans;
        vector<bool> visited(n, false);
        unordered_map<int, set<int>> busStop;
        queue<pair<int,int>> mQ;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<routes[i].size(); ++j) {
                busStop[routes[i][j]].insert(i);
                if(routes[i][j] == source) {
                    mQ.push({i,1});
                }
            }
        }

        while(!mQ.empty()) {
            auto p = mQ.front();
            mQ.pop();
            visited[p.first] = true;
            for(auto x : routes[p.first]) {
                if(x==target) {
                    ans.insert(p.second);
                }
                if(busStop[x].size()>=2) {
                    for(auto y : busStop[x]) {
                        if(visited[y]==false) {
                            mQ.push({y, p.second + 1});
                            visited[y] = true;
                        }
                    }
                }
            }
        }
        if(ans.empty())
            return -1;
        set<int>::iterator it = ans.begin();
        return *it;
    }
};
