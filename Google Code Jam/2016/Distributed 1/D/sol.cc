// #include <message.h>
#include <stdio.h>
#include "crates.h"
#include <algorithm>

#include <vector>
using namespace std;

const long long MOD = 1000000007LL;
long long A[1000006];
long long target[1000006];

int main() {
  long long N = GetNumStacks();
  // long long nodes = NumberOfNodes();
  long long my_id = 0;// MyNodeId();

  long long sum = 0LL;
  for(long long i=1;i<=N;i++){
    A[i] = GetStackHeight(i);
    sum += A[i];
  }

  long long threshold = sum % N;
  long long v1 = sum / N + 1LL;
  for(long long i=1;i <= threshold;++i) target[i] = v1;
  for(long long i=threshold+1LL;i<=N;i++) target[i] = v1-1LL;
  // printf("threshold = %lld\n",threshold); 
  // for(int i=1;i<=N;i++) printf("[%lld]",target[i]);
  //   printf("\n");

  long long sum_A = 0LL;
  long long sum_target = 0LL;
  for(long long i=1;i<=N;i++){
    sum_A += A[i];
    sum_target += target[i];

    if(sum_A >= sum_target){
      threshold = i;
      break;
    }
  }

  // 1 - threshold   move left
  long long currentidx = 2;
  long long carry = 0;
  for(long long i=1;i<=threshold;i++){
    if(A[i] == target[i]) continue;
    if(i == currentidx) currentidx++;

    if(A[i] != target[i]){
      carry += A[i]-target[i];
      A[i] = target[i];
      answer += 
    }
  }

  // threshold - N   move right




  // for(int i=1;i<=N;i++) printf("[%lld]",A[i]);
  //   printf("\n");

  if(my_id == 0){
    printf("%lld\n",answer);
  }
  return 0;
}