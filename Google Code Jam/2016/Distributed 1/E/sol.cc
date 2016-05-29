#include <message.h>
#include <stdio.h>
#include "winning_move.h"
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define MASTER_NODE 9
#define DONE -1

int main() {
  long long N = GetNumPlayers();
  long long nodes = NumberOfNodes();
  long long my_id = MyNodeId();

  set <long long> S;
  set <long long> banned;
  for(long long i=0;i < N;++i){
    long long val = GetSubmission(i);
    if(S.count(val)) banned.insert(val);
    else S.insert(val);
  }

  long long answer;
  for(set<long long>::iterator it=S.begin();it!=S.end();it++){
    if(not banned.count(*it)){
      answer = *it;
      break;
    }
  }

  if (my_id == MASTER_NODE) {
    printf("%lld\n",answer);
  }
  return 0;
}