// using mod to keep the stress number small, the result wont be the same if we divided by 3,  but it will keep the number small and that what matters

#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int sz = 8, mod = 1;
    vector<long long> holdings(sz, 0);
    vector<deque<long long>>inspection(sz) ;
    vector<pair<char, int>> op(sz);
    vector<int>checkDiv(sz);
    vector<pair<int,int> >throww(sz);

    for(int x = 0; x < sz; x++){
        int n, level, val; 
        char ops;
        cin >> n;
        while(n--){
            cin >> level;
            inspection[x].push_back(level);
        }
        cin >> ops >> val;
        pair <char, int> opsVal(ops,val);
        op[x] = opsVal;

        cin >> val;checkDiv[x] = val;
        mod *= val;
        cin >> val;throww[x].first = val;
        cin >> val;throww[x].second = val;
    }


    for(int x = 0; x < 10000; x++){
        
        for(int i = 0; i < sz; i++){
            holdings[i] += inspection[i].size();
            for(int ii = 0; ii < inspection[i].size(); ii++){
                
                long long val = op[i].second == 0 ? inspection[i][ii]: op[i].second;
                if(op[i].first == '+')val += inspection[i][ii];
                else val *= inspection[i][ii];
                val %= mod ;
                if(val % checkDiv[i] == 0){
                    inspection[throww[i].first].push_back(val);
                }
                else{
                    inspection[throww[i].second].push_back(val);
                }
            }
            inspection[i].clear();
        }

    }
    for(int x = 0; x < sz; x++)cout << holdings[x] << " ";
    cout << endl;
    sort(holdings.begin(), holdings.end());

    cout << holdings[sz-1] * holdings[sz-2] << endl;

    return 0;
}
