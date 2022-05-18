#include <bits/stdc++.h>

using namespace std;



struct Name
{
    string key;
    int value;
    int index;
};
bool sortBySec(const pair<string,int> &a,
              const pair<string,int> &b)
{
    return (a.second > b.second);
}

bool sortByIndex(const struct Name &a,
              const struct Name &b)
{
    return (a.index < b.index);
}

int find_(pair<string,int>& p, vector<pair<string,int>>& v)
{
    vector<pair<string,int>>::iterator it1;
    for(it1 = v.begin(); it1 != v.end(); it1++)
    {
        if(it1->first == p.first)
        {
            return it1->second;
        }
    }
    return -1;
}


int main()
{

    freopen("F:/Code/Exam3/input.txt","r",stdin);

    int N,M;

    vector<pair<string,int>> mv ,mv1;
    pair<string,int> p;
    unordered_map<string, int> vParticipants;
    vector<Name> na;

    struct Name name;

    cin>>N;

    for(int i=0;i<N;i++)
    {
        cin >> p.first;
        p.second = 0;
        mv.push_back(p);
        mv1.push_back(make_pair(p.first,i));
    }
    cin >> M;
    unordered_map<string,int>::iterator it;
    for(auto &b : mv)
    {
        vParticipants.emplace (b);
    }

    for(int i = 0;i<M;i++)
    {
        cin >> p.first >> p.second;
        it = vParticipants.find(p.first);
        if( it != vParticipants.end())
        {
            it->second +=p.second;
        }
    }
    mv.clear();
    for(auto &a : vParticipants)
    {
        mv.push_back(a);
    }
    // reverse(mv.begin(),mv.end());
    sort(mv.begin(), mv.end(), sortBySec);
    int x= mv[0].second;
    int y= 0, v= 0, l = 0;

    vector<pair<string,int>>::iterator it1;

    for(it1 = mv.begin();it1 != mv.end(); it1++)
    {
          if(it1->second == x)
          {
              y++;
          }
          else
          {
            break;
          }
    }

    if(y>=3)
    {
        int in;
        for(int j=0;j<y;j++)
        {
           pair<string,int> p = make_pair(mv[j].first,mv[j].second);
           in = find_(p,mv1);
           na.push_back({p.first,p.second,in});
        }

        sort(na.begin(), na.end(), sortByIndex);
        cout << na[0].key <<" "<<na[0].value<<endl;
        cout << na[1].key <<" "<<na[1].value<<endl;
        cout << na[2].key <<" "<<na[2].value<<endl;

    }
    else if(y==2)
    {
        int in;
        for(int j=0;j<y;j++)
        {
           pair<string,int> p = make_pair(mv[j].first,mv[j].second);
           in = find_(p,mv1);
           na.push_back({p.first,p.second,in});
        }

        sort(na.begin(), na.end(), sortByIndex);
        cout << na[0].key <<" "<<na[0].value<<endl;
        cout << na[1].key <<" "<<na[1].value<<endl;
        mv.erase(mv.begin());
        mv.erase(mv.begin());
        x= mv[0].second;
        for(it1 = mv.begin();it1 != mv.end(); it1++)
        {
              if(it1->second == x)
              {
                  v++;
              }
              else
              {
                break;
              }
        }
        if(v == 1)
        {
            cout << mv[0].first <<" "<<mv[0].second<<endl;
        }
        else
        {

            na.clear();
            for(int j=0;j<v;j++)
            {
               pair<string,int> p = make_pair(mv[j].first,mv[j].second);
               in = find_(p,mv1);
               na.push_back({p.first,p.second,in});
            }

            sort(na.begin(), na.end(), sortByIndex);
            cout << na[0].key <<" "<<na[0].value<<endl;
        }

    }
    else if(y==1)
    {
        cout << mv[0].first <<" "<<mv[0].second<<endl;
        mv.erase(mv.begin());
        int in;
        x= mv[0].second;
        for(it1 = mv.begin();it1 != mv.end(); it1++)
        {
              if(it1->second == x)
              {
                  v++;
              }
              else
              {
                break;
              }
        }
        if(v >=2)
        {
            for(int j=0;j<v;j++)
            {
               pair<string,int> p = make_pair(mv[j].first,mv[j].second);
               in = find_(p,mv1);
               na.push_back({p.first,p.second,in});
            }

            sort(na.begin(), na.end(), sortByIndex);
            cout << na[0].key <<" "<<na[0].value<<endl;
            cout << na[1].key <<" "<<na[1].value<<endl;
        }
        if(v==1)
        {
            cout << mv[0].first <<" "<<mv[0].second<<endl;
            mv.erase(mv.begin());
            x= mv[0].second;
            for(it1 = mv.begin();it1 != mv.end(); it1++)
            {
                  if(it1->second == x)
                  {
                      l++;
                  }
                  else
                  {
                    break;
                  }
            }
            if(l==1)
            {
                cout << mv[0].first <<" "<<mv[0].second<<endl;
            }
            else
            {

                for(int j=0;j<l;j++)
                {
                   pair<string,int> p = make_pair(mv[j].first,mv[j].second);
                   in = find_(p,mv1);
                   na.push_back({p.first,p.second,in});
                }

                sort(na.begin(), na.end(), sortByIndex);
                cout << na[0].key <<" "<<na[0].value<<endl;
            }

        }
    }
    return 0;
}
