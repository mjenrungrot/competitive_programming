#include <message.h>
#include <stdio.h>
#include "rps.h"
#include <algorithm>
#include <queue>
using namespace std;

#define DONE -1

typedef pair<char,long long> ii;
const long long INF = 1e18 + 20;

int win(ii ch1, ii ch2){
  if(ch1.first == ch2.first){
    return ch1.second < ch2.second;
  }

  if(ch1.first == 'R' and ch2.first == 'S') return true;
  if(ch1.first == 'P' and ch2.first == 'R') return true;
  if(ch1.first == 'S' and ch2.first == 'P') return true;
  return false;
}

int main() {
  long long N = GetN();
  long long nodes = NumberOfNodes();
  long long my_id = MyNodeId();

  if(N <= 10){
    const int MASTER_NODE = 9;
    long long allN = (1<<N)-1;

    // printf("allN = %lld\n",allN);

    queue <ii> Q;
    for(long long i=0;i<=allN;i++){
      char ch = GetFavoriteMove(i);
      Q.push(ii(ch,i));
    }

    while(Q.size() > 1){
      ii v1 = Q.front(); Q.pop();
      ii v2 = Q.front(); Q.pop();

      if(win(v1, v2)) Q.push(v1);
      else Q.push(v2);
    }
    long long winner = Q.front().second;

    PutLL(MASTER_NODE, 0LL);
    Send(MASTER_NODE);

    if (my_id == MASTER_NODE) {
      printf("%lld\n", winner);
    }

  }else if(N > 10){

    const int MASTER_NODE = 99;
    // N = 10; used = 6
    // N = 6; used = 6;
    long long n_onenode = N - 6LL;
    long long n_used = 6LL;
    n_onenode = (1LL << n_onenode);
    n_used = (1LL << n_used);

    long long OFFSET = n_onenode;
    long long left,right;

    long long st = 0LL;
    for(long long i=1;i<=n_used;i++){
      if(my_id == i){
        left = st;
        right = st+OFFSET-1;
        break;
      }
      st += OFFSET;
    }

    if(my_id >= 1 and my_id <= n_used){
      queue <ii> Q;
      for(long long i=left;i<=right;i++){
        char ch = GetFavoriteMove(i);
        Q.push(ii(ch,i));
      }

      while(Q.size() > 1){
        ii v1 = Q.front(); Q.pop();
        ii v2 = Q.front(); Q.pop();

        if(win(v1, v2)) Q.push(v1);
        else Q.push(v2);
      }
      PutChar(MASTER_NODE, Q.front().first);
      PutLL(MASTER_NODE, Q.front().second);
      Send(MASTER_NODE);
    }

    if (my_id == MASTER_NODE) {      
      queue <ii> Q;
      for(long long i=1;i<=n_used;i++){
        Receive(i);
        char ch = GetChar(i);
        long long idx = GetLL(i);
        Q.push(ii(ch,idx));
      }
      while(Q.size() > 1){
        ii v1 = Q.front(); Q.pop();
        ii v2 = Q.front(); Q.pop();

        if(win(v1, v2)) Q.push(v1);
        else Q.push(v2);
      }
      printf("%lld\n", Q.front().second);
    }
  }
  return 0;
}