// Sample input 2, in CPP.

#include <cassert>

long long GetNumStacks() {
  return 4LL;
}

long long GetStackHeight(long long i) {
  switch ((int)i) {
    case 1: return 0LL;
    case 2: return 4LL;
    case 3: return 4LL;
    case 4: return 0LL;
    default: assert(0);
  }
}
