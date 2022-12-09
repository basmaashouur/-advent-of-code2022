
#include <bits/stdc++.h>

using namespace std;


vector < vector < int >> vec;
pair < int, int > changeTail(pair < int, int > head, pair < int, int > tail) {

  // same row
  if (abs(head.second - tail.second) == 4) cout << head.first << " " << head.second << "    " << tail.first << " " << tail.second << endl;

  if (head.first == tail.first) {
    if (abs(head.second - tail.second) == 2) {

      if (head.second > tail.second) tail.second++;
      else tail.second--;

    }
  }
  // same col
  else if (head.second == tail.second) {
    if (abs(head.first - tail.first) == 2) {
      if (head.first > tail.first) tail.first++;
      else tail.first--;
    }
  }

  // diff row and cols, move dig
  else {
    if (abs(head.first - tail.first) == 2) {
      tail.first = (tail.first + head.first) / 2;
      tail.second = head.second;
    } else if (abs(head.second - tail.second) == 2) {
      tail.second = (tail.second + head.second) / 2;
      tail.first = head.first;
    }

  }
  vec[tail.first][tail.second] = 2;

  return tail;
}
int main() {

  for (int x = 0; x < 1000; x++) {
    vector < int > temp(1000, 0);
    vec.push_back(temp);
  }

  vec[500][500] = 2;

  pair < int, int > head(500, 500);
  pair < int, int > tail(500, 500);
  while (true) {
    string pos;
    cin >> pos;
    if (pos == "100") break;
    int steps;
    cin >> steps;
    int temp;

    if (pos == "R") {
      temp = head.second;
      for (int y = temp + 1; y <= steps + temp; y++) {
        head.second = y;
        tail = changeTail(head, tail);
      }
    } else if (pos == "L") {
      temp = head.second;
      for (int y = temp - 1; y >= temp - steps; y--) {
        head.second = y;
        tail = changeTail(head, tail);
      }
    } else if (pos == "D") {
      temp = head.first;
      for (int x = temp + 1; x <= steps + temp; x++) {
        head.first = x;
        tail = changeTail(head, tail);
      }
    } else if (pos == "U") {
      temp = head.first;
      for (int x = temp - 1; x >= temp - steps; x--) {
        head.first = x;
        tail = changeTail(head, tail);
      }
    }

  }
  int ans = 0;
  for (int x = 0; x < 1000; x++) {
    for (int y = 0; y < 1000; y++) {
      //cout << vec[x][y] << " ";
      if (vec[x][y] == 2) ans++;
    }
    //cout << endl;
  }
  cout << ans << endl;

  return 0;
}
