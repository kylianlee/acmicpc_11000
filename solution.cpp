//
// Created by Kylian Lee on 2021/09/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main(){
  int class_num;
  scanf("%d", &class_num);
  for (int i = 0; i < class_num; ++i) {
    int start, end;
    scanf("%d %d", &start, &end);
    pq.push({start, end});
  }
  priority_queue<int, vector<int>, greater<>> answer;
  answer.push(pq.top().second);
  pq.pop();
  while(!pq.empty()){
    if(answer.top() <= pq.top().first)
      answer.pop();
    answer.push(pq.top().second);
    pq.pop();
  }

  cout << answer.size() << endl;
  return 0;
}