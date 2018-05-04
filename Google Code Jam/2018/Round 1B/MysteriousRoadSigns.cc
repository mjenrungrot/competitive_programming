/*
 * Problem: Mysterious Road Signs
 * Link: https://codejam.withgoogle.com/2018/challenges/0000000000007764/dashboard/000000000003675b
 * Source: Google Code Jam 2018 Round 1B
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXS = 1e5+100;
int S, M[MAXS], N[MAXS];

void runTest(int testId){
  scanf("%d", &S);
  
  int Di, Ai, Bi;
  for(int i=1;i<=S;i++){
    scanf("%d %d %d", &Di, &Ai, &Bi);
    M[i] = Di + Ai;
    N[i] = Di - Bi;
    fprintf(stderr, "[%d][%d]\n",M[i],N[i]);
  }

  int maxLength = 1, nMaxLength = 1;

  int fixedM_M, fixedM_N, fixedM_start, fixedM_switch;
  int fixedN_M, fixedN_N, fixedN_start, fixedN_switch;
  
  fixedM_M = M[1];   fixedM_N = N[1]; fixedM_start = 1; fixedM_switch = 1;
  fixedN_M = M[1];   fixedN_N = N[1]; fixedN_start = 1; fixedN_switch = 1;

  int newM1, newM2, newM3, newM4;
  int newN1, newN2, newN3, newN4;
  int lengthM, lengthN;
  for(int i=2;i<=S;i++){
    // fixedM
    if(M[i] == fixedM_M){
      newM1 = fixedM_M;
      newM2 = fixedM_N;
      newM3 = fixedM_start;
      newM4 = fixedM_switch;
    }else if(M[i] == fixedN_M){
      newM1 = fixedN_M;
      newM2 = fixedN_N;
      newM3 = fixedN_start;
      newM4 = i;
    }else{
      newM1 = M[i];
      newM2 = fixedN_N;
      newM3 = fixedN_switch;
      newM4 = i;
    }

    // fixedN
    if(N[i] == fixedN_N){
      newN1 = fixedN_M;
      newN2 = fixedN_N;
      newN3 = fixedN_start;
      newN4 = fixedN_switch;
    }else if(N[i] == fixedM_N){
      newN1 = fixedM_M;
      newN2 = fixedM_N;
      newN3 = fixedM_start;
      newN4 = i;
    }else{
      newN1 = fixedM_M;
      newN2 = N[i];
      newN3 = fixedM_switch;
      newN4 = i;
    }

    fixedM_M = newM1; fixedM_N = newM2; fixedM_start = newM3; fixedM_switch = newM4;
    fixedN_M = newN1; fixedN_N = newN2; fixedN_start = newN3; fixedN_switch = newN4;

    fprintf(stderr, "i = %d\n",i);
    fprintf(stderr, "Candidate M [%d][%d][%d][%d]\n", fixedM_M, fixedM_N, fixedM_start, fixedM_switch);
    fprintf(stderr, "Candidate N [%d][%d][%d][%d]\n", fixedN_M, fixedN_N, fixedN_start, fixedN_switch);


    lengthM = i - fixedM_start + 1;
    lengthN = i - fixedN_start + 1;
    if(max(lengthM, lengthN) > maxLength){
      maxLength = max(lengthM, lengthN);
      nMaxLength = 1;
    }else if(max(lengthM, lengthN) == maxLength){
      nMaxLength++;
   }
  }

  printf("Case #%d: %d %d\n", testId, maxLength, nMaxLength);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i=1;i<=T;i++) runTest(i);
  return 0;
}
