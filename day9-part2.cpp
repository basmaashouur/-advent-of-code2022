// not working right!!
#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> vec;
vector<pair<int, int> > knots;

void changeKnots(){

    for(int x = 1; x < 10; x++){


        // same row
        if(knots[x-1].first == knots[x].first){
            if(abs(knots[x-1].second - knots[x].second)  >= 2){
                if(knots[x-1].second > knots[x].second)knots[x].second = knots[x-1].second -1;
                else knots[x].second = knots[x-1].second + 1;
            }
        }
        // same col
        else if(knots[x-1].second == knots[x].second){
            if(abs(knots[x-1].first - knots[x].first)  >= 2){
                if(knots[x-1].first > knots[x].first)knots[x].first = knots[x-1].first-1;
                else knots[x].first = knots[x-1].first+1;
            } 
        }
        
        // diff row and cols, move dig
        else{
            if(abs(knots[x-1].first - knots[x].first)  >= 2){
                knots[x].first = (knots[x].first + knots[x-1].first)/2;
                knots[x].second = knots[x-1].second;
            }
            else if(abs(knots[x-1].second - knots[x].second)  >= 2){
                knots[x].second = (knots[x].second + knots[x-1].second)/2;
                knots[x].first = knots[x-1].first;
            }
        }
    }

    vec[knots[9].first][knots[9].second] = 2;
}

int main()
{
    for(int x = 0; x < 1000; x++){
        vector<int>temp(1000, 0);
        vec.push_back(temp);
    }
    
    vec[500][500] = 2;
    // 9 knots + the head
    // the head is at 0
    for(int x = 0; x < 10; x++){
        pair<int, int> knot(500, 500);
        knots.push_back(knot);
        
    }
    while(true){
        string pos; cin >> pos;
        if(pos == "100")break;
        int steps; cin >> steps;
        int temp;
        
        if(pos == "R"){
            temp = knots[0].second;
            for(int y = temp+1; y <= steps + temp; y++){
                knots[0].second = y;
                changeKnots();
            }
        }
        
        else if(pos == "L"){
            temp = knots[0].second;
            for(int y = temp-1; y >= temp- steps; y--){
                knots[0].second = y;
                changeKnots();
            }
        }
        
        else if(pos == "D"){
            temp = knots[0].first;
            for(int x = temp+1; x <= steps + temp ; x++){
                knots[0].first = x;
                changeKnots();
            }
        }
        
        else if(pos == "U"){
            temp = knots[0].first;
            for(int x = temp-1; x >= temp -steps ; x--){
                knots[0].first = x;
                changeKnots();
            } 
        }
        
    }
    
    int ans = 0;
    for(int x = 0; x < 1000; x++){
        for(int y = 0; y < 1000; y++){
            //cout << vec[x][y] << " ";
            if(vec[x][y] == 2)ans++;
        }
       //cout << endl;
    }
    cout << ans << endl;
        

    
    return 0;
}
