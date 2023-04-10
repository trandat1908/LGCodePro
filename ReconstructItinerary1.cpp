// https://leetcode.com/problems/reconstruct-itinerary/description/

class Solution {
public:
    int n;
    string s;
    vector<string> ans;
    set<pair<string, bool>>::iterator it;
    bool c = false;
    
    void dfs(map<string, vector<pair<string, bool>>>& tickets, vector<string> temp, string src, int count) {
        if(count==n) {
            ans = temp;
            c = true;
            return;
        }
        vector<pair<string, bool>>::iterator it;
        for(it = tickets[src].begin(); it != tickets[src].end(); ++it) {
            if(it->second==false) {
                s = it->first;
                //cout<<"s = "<<s<<endl;
                temp.push_back(s);
                it->second = true;
                dfs(tickets, temp, s, count + 1);
                if(c) return;
                it->second = false;
                temp.pop_back();
            }
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& t) {
        map<string, vector<pair<string, bool>>> tickets;
        vector<string> temp;
        n = t.size();
        string a, b;
        for(int i=0; i<(int) t.size(); ++i) {
            a = t[i][0];
            b = t[i][1];
            tickets[a].push_back({b, false});
        }
        map<string, vector<pair<string, bool>>>::iterator it;
        for(it = tickets.begin(); it != tickets.end(); ++it) {
            sort(it->second.begin(), it->second.end());
        }
        temp.push_back("JFK");
        dfs(tickets, temp, "JFK", 0);
        return ans;
    }
};
