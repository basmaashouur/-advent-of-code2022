#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int sz = 8;
    vector<int> holdings(sz, 0);
    vector<deque<int>>inspection(sz) ;
    // .first operation, .second the number, if the number is 0 then by old
    vector<pair<char, int>> op(sz);
    vector<int>checkDiv(sz);
    // .frist when true, .second when false
    vector<pair<int,int> >throww(sz);

    for(int x = 0; x < sz; x++){
        int n, level, val; 
        char ops;
        cin >> n;
        while(n--){
            cin >> level;
            inspection[x].push_back(level);
            //holdings[x]++;
        }
        cin >> ops >> val;
        pair <char, int> opsVal(ops,val);
        op[x] = opsVal;

        cin >> val;checkDiv[x] = val;
        cin >> val;throww[x].first = val;
        cin >> val;throww[x].second = val;
    }

    // 20 rounds
    
    for(int x = 0; x < 20; x++){
        
        for(int i = 0; i < sz; i++){
            holdings[i] += inspection[i].size();
            // check the holdings with every monkey
            for(int ii = 0; ii < inspection[i].size(); ii++){
                
                int val = op[i].second == 0 ? inspection[i][ii]: op[i].second;
                if(op[i].first == '+')val += inspection[i][ii];
                else val *= inspection[i][ii];
                val /= 3;
                if(val % checkDiv[i] == 0){
                    inspection[throww[i].first].push_back(val);
                    //holdings[throww[i].first]++;
                }
                else{
                    inspection[throww[i].second].push_back(val);
                    //holdings[throww[i].second]++;
                }
            }
            // delete all the holdings from current monkey
            inspection[i].clear();
        }
    }
    sort(holdings.begin(), holdings.end());
    cout << holdings[sz-1] * holdings[sz-2] << endl;

    return 0;
}
