#include <message.h>
#include <stdio.h>
#include "oops.h"
#include <algorithm>
using namespace std;

#define MASTER_NODE 7
#define DONE -1

const long long INF = 1e18 + 20;

int main() {
  long long N = GetN();
  long long nodes = NumberOfNodes();
  long long my_id = MyNodeId();

  long long bestmin = INF;
  long long bestmax = -INF;


  // interval 
  long long left = N * (my_id) / nodes;
  long long right = N * (my_id+1) / nodes;
  long long zero = 0LL;
  left = max(zero, left - nodes - 5);
  right = min(N, right + nodes + 5);

  for(long long i = left;i < right; ++i){
    long long number = GetNumber(i);
    bestmax = max(bestmax, number);
    bestmin = min(bestmin, number);
  }

  // for (long long i = 0; i < N; ++i) {
  //   for (long long j = 0; j < N; ++j) {
  //     if (j % nodes == my_id) {
  //       long long candidate = GetNumber(i) - GetNumber(j);
  //       if (candidate > best_so_far) {
  //         best_so_far = candidate;
  //         PutLL(MASTER_NODE, candidate);
  //         Send(MASTER_NODE);
  //       }
  //     }
  //   }
  // }
  PutLL(MASTER_NODE, bestmax);
  PutLL(MASTER_NODE, bestmin);
  Send(MASTER_NODE);

  if (my_id == MASTER_NODE) {
    long long global_best_so_far = 0;
    long long valMax = -INF, valMin = INF;
    for (int node = 0; node < nodes; ++node) {
      Receive(node);
      valMax = max(valMax, GetLL(node));
      valMin = min(valMin, GetLL(node));
    }
    global_best_so_far = valMax - valMin;
    printf("%lld\n", global_best_so_far);
  }
  return 0;
}