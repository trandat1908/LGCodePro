// https://leetcode.com/problems/reconstruct-itinerary/



class Solution {
public:
    int n;
    string s;
    vector<string> ans;
    set<pair<string, bool>>::iterator it;
    bool c = false;
    struct iPair {
        string s;
        bool v;
        bool operator < (const iPair &other) { return s < other.s;}
    };

    void dfs(map<string, set<iPair>>& tickets, vector<string> temp, string src, int count) {
        if(count==n) {
            ans = temp;
            c = true;
            return;
        }
        set<iPair>::iterator it;
        for(it = tickets[src].begin(); it != tickets[src].end(); ++it) {
            if(it->v==false) {
                s = it->s;
                cout<<"s = "<<s<<endl;
                temp.push_back(s);
                it->v = true;
                dfs(tickets, temp, s, count + 1);
                if(c) return;
                it->v = false;
                temp.push_back(s);
            }
        }
    }
    
    vector<string> findItinerary(vector<vector<string>>& t) {
        map<string, set<iPair>> tickets;
        vector<string> temp;
        n = t.size();
        string a, b;
        for(int i=0; i<(int) t.size(); ++i) {
            iPair *p = new iPair();
            a = t[i][0];
            b = t[i][1];
            p->s = b;
            p->v = false;
            tickets[a].insert(*p);
        }
        temp.push_back("JFK");
        dfs(tickets, temp, "JFK", 0);
        return ans;
    }
};
