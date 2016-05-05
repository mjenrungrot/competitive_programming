template <class T>
T EulerPhi(T n){
	T result = n;
	for(T i=2; i*i <= n; ++i){
		if(n%i == 0){
			while(n % i == 0) n /= i;
			result -= result / i;
		}
	}
	if(n > 1) result -= result / n;
	return result;
}

template <class T>
T gcd(T A, T B){
	if(B == 0) return A;
	return gcd(B, A%B);
}
template <class T>
T gcd(T A, T B, T &x, T &y){
	if(A == 0){
		 x = 0; 
		 y = 1;
		 return B;
	}
	T x1, y1;
	T d = gcd(B%A, A, x1, y1);
	x = y1 - (B/A) * x1;
	y = x1;
	return d;
}

vector <int> generatePrime(int n){
	vector<char> lp(n+1, false);
	vector<int> pr;
 
	for (int i=2; i<=n; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; ++j)
			lp[i * pr[j]] = pr[j];
	}
	return pr;
}

template <class T>
T power(T a, T n){
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return power(a, n-1) * a;
	else {
		T b = power(a, n/2);
		return b * b;
	}
}
template <class T>
T power(T a, T n, T mod){
	if (n == 0)
		return 1 % mod;
	if (n % 2 == 1)
		return ((power(a, n-1) % mod) * a)%mod;
	else {
		T b = power(a, n/2);
		return (b * b)% mod;
	}
}

bignum::bignum(){
	value.clear();
	assert(value.empty());
}
bignum::bignum(const int& rhs){
	ostringstream stringValue;
	stringValue << rhs;
	this->value = bignum(stringValue.str()).value;
}
bignum::bignum(const long long& rhs){
	ostringstream stringValue;
	stringValue << rhs;
	this->value = bignum(stringValue.str()).value;
}
bignum::bignum(const string& rhs){
	for (int i=(int)rhs.length(); i>0; i-=9){
		if (i < 9)
			value.push_back (atoi (rhs.substr (0, i).c_str()));
		else
			value.push_back (atoi (rhs.substr (i-9, 9).c_str()));
	}
	while (value.size() > 1 && value.back() == 0) value.pop_back();
}
bignum::bignum(const char* rhs){
	ostringstream stringValue;
	stringValue << rhs;
	printf("rhs = %s\n",rhs);
	this->value = bignum(stringValue.str()).value;
}
bignum::bignum(const bignum& rhs){
	this->value = rhs.value;
}
bignum bignum::operator=(const bignum& rhs){
	this->value = rhs.value;
	return *this;
}
string bignum::str() const{
	ostringstream outputString;
	outputString << (value.empty() ? 0 : value.back());
	for (int i=(int)value.size()-2; i>=0; --i){
		outputString << setfill('0') << setw(9) << value[i];
	}
	printf("output = %s\n",outputString.str().c_str());
	return outputString.str().c_str();
}
ostream& operator<<(ostream &os, const bignum& x){
	os << (x.value.empty() ? 0 : x.value.back());
	for (int i=(int)x.value.size()-2; i>=0; --i){
		os << setfill('0') << setw(9) << x.value[i];
	}
	return os;
}
bignum bignum::operator+(const bignum& rhs){
	int carry = 0;
	for (size_t i=0; i<max(value.size(),rhs.value.size()) || carry; ++i) {
		if (i == value.size())
			value.push_back (0);
		value[i] += carry + (i < rhs.value.size() ? rhs.value[i] : 0);
		carry = value[i] >= base;
		if (carry)  value[i] -= base;
	}
	return *this;
}
bignum bignum::operator-(const bignum& rhs){
	int carry = 0;
	for (size_t i=0; i<rhs.value.size() || carry; ++i) {
		value[i] -= carry + (i < rhs.value.size() ? rhs.value[i] : 0);
		carry = value[i] < 0;
		if (carry)  value[i] += base;
	}
	while (value.size() > 1 && value.back() == 0)
		value.pop_back();
	return *this;
}
bignum bignum::operator*(const int& rhs){
	int carry = 0;
	for (size_t i=0; i<value.size() || carry; ++i) {
		if (i == value.size())
			value.push_back (0);
		long long cur = carry + value[i] * 1ll * rhs;
		value[i] = int (cur % base);
		carry = int (cur / base);
	}
	while (value.size() > 1 && value.back() == 0){
		value.pop_back();
	}
	return *this;
}
bignum bignum::operator*(const bignum& rhs){
	vector<int> c(value.size()+rhs.value.size());
	for (size_t i=0; i<value.size(); ++i)
		for (int j=0, carry=0; j<(int)rhs.value.size() || carry; ++j) {
			long long cur = c[i+j] + value[i] * 1ll * (j < (int)rhs.value.size() ? rhs.value[j] : 0) + carry;
			c[i+j] = int (cur % base);
			carry = int (cur / base);
		}
	while (c.size() > 1 && c.back() == 0)
		c.pop_back();
	value = c;
	return *this;
}
bignum bignum::operator/(const int& rhs){
	int carry = 0;
	for (int i=(int)value.size()-1; i>=0; --i) {
		long long cur = value[i] + carry * 1ll * base;
		value[i] = int (cur / rhs);
		carry = int (cur % rhs);
	}
	while (value.size() > 1 && value.back() == 0)
		value.pop_back();
	return *this;
}

template <class T>
T abs(T x){
	return x < 0 ? -x : x;
}
template <class T>
bool findSolutionDiophantine(T a, T b, T c, T & x0, T & y0, T & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}
template <class T>
void shiftSolution(T &x, T &y, T a, T b, T cnt){
	x += cnt * b;
	y -= cnt * a;
}
template <class T>
int findAllSolutionsDiophantine(T a, T b, T c, T minx, T maxx, T miny, T maxy) {
	T x, y, g;
	if (!findSolutionDiophantine(a, b, c, x, y, g))
		return 0;
	a /= g;  b /= g;
 
	T sign_a = a>0 ? +1 : -1;
	T sign_b = b>0 ? +1 : -1;
 
	shiftSolution (x, y, a, b, (minx - x) / b);
	if (x < minx)
		shiftSolution (x, y, a, b, sign_b);
	if (x > maxx)
		return 0;
	T lx1 = x;
 
	shiftSolution (x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shiftSolution (x, y, a, b, -sign_b);
	T rx1 = x;
 
	shiftSolution (x, y, a, b, - (miny - y) / a);
	if (y < miny)
		shiftSolution (x, y, a, b, -sign_a);
	if (y > maxy)
		return 0;
	T lx2 = x;
 
	shiftSolution (x, y, a, b, - (maxy - y) / a);
	if (y > maxy)
		shiftSolution (x, y, a, b, sign_a);
	T rx2 = x;
 
	if (lx2 > rx2)
		swap(lx2, rx2);
	T lx = max (lx1, lx2);
	T rx = min (rx1, rx2);
 
	return (rx - lx) / abs(b) + 1;
}

void FFT(cpx *in, cpx *out, int step, int size, int dir){
  if(size < 1) return;
  if(size == 1)
  {
    out[0] = in[0];
    return;
  }
  FFT(in, out, step * 2, size / 2, dir);
  FFT(in + step, out + size / 2, step * 2, size / 2, dir);
  for(int i = 0 ; i < size / 2 ; i++)
  {
    cpx even = out[i];
    cpx odd = out[i + size / 2];
    out[i] = even + EXP(dir * two_pi * i / size) * odd;
    out[i + size / 2] = even + EXP(dir * two_pi * (i + size / 2) / size) * odd;
  }
}

// Dinic Algorihm
void Dinic::AddEdge(int from, int to, int cap){
	if (from == to) return;
	G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
	G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
}
long long Dinic::BlockingFlow(int s,int t) {
    layer.clear(); layer.resize(N, -1);
    layer[s] = 0;
    Lf.clear(); Lf.resize(N);
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i]; if (e.rcap() <= 0) continue;
        if (layer[e.to] == -1) {
          layer[e.to] = layer[e.from] + 1;
          Q[tail++] = e.to;
        }
        if (layer[e.to] > layer[e.from]) {
          Lf[e.from].push_back(&e);
        }
      }
    }
    if (layer[t] == -1) return 0;

    long long totflow = 0;
    vector<Edge *> P;
    while (!Lf[s].empty()) {
      int curr = P.empty() ? s : P.back()->to;
      if (curr == t) { // Augment
        long long amt = P.front()->rcap();
        for (int i = 0; i < P.size(); ++i) {
          amt = min(amt, P[i]->rcap());
        }
        totflow += amt;
        for (int i = P.size() - 1; i >= 0; --i) {
          P[i]->flow += amt;
          G[P[i]->to][P[i]->index].flow -= amt;
          if (P[i]->rcap() <= 0) {
            Lf[P[i]->from].pop_back();
            P.resize(i);
          }
        }
      } else if (Lf[curr].empty()) { // Retreat
        P.pop_back();
        for (int i = 0; i < N; ++i)
          for (int j = 0; j < Lf[i].size(); ++j)
            if (Lf[i][j]->to == curr)
              Lf[i].erase(Lf[i].begin() + j);
      } else { // Advance
        P.push_back(Lf[curr].back());
      }
    }
   return totflow;
}
long long Dinic::GetMaxFlow(int s, int t){
	long long totalflow = 0;
	while(long long flow = BlockingFlow(s, t)){
		totalflow += flow;
	}
	return totalflow;
}

// PushRelabel Algorithm
void PushRelabel::AddEdge(int from, int to, int cap) {
	G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
	if (from == to) G[from].back().index++;
	G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
}
void PushRelabel::Enqueue(int v) { 
	if (!active[v] && excess[v] > 0) { 
		active[v] = true; Q.push(v);
	} 
}
void PushRelabel::Push(Edge &e) {
	int amt = int(min(excess[e.from], (long long)(e.cap - e.flow)));
	if (dist[e.from] <= dist[e.to] || amt == 0) return;
	e.flow += amt;
	G[e.to][e.index].flow -= amt;
	excess[e.to] += amt;    
	excess[e.from] -= amt;
	Enqueue(e.to);
}
void PushRelabel::Gap(int k) {
	for (int v = 0; v < N; v++) {
		if (dist[v] < k) continue;
		count[dist[v]]--;
		dist[v] = max(dist[v], N+1);
		count[dist[v]]++;
		Enqueue(v);
	}
}
void PushRelabel::Relabel(int v) {
	count[dist[v]]--;
	dist[v] = 2*N;
	for (int i = 0; i < G[v].size(); i++) 
		if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
	count[dist[v]]++;
	Enqueue(v);
}
void PushRelabel::Discharge(int v) {
	for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
	if (excess[v] > 0) {
		if (count[dist[v]] == 1)	Gap(dist[v]); 
		else						Relabel(v);
	}
}
long long PushRelabel::GetMaxFlow(int s, int t) {
	count[0] = N-1;
	count[N] = 1;
	dist[s] = N;
	active[s] = active[t] = true;
	for (int i = 0; i < G[s].size(); i++) {
		excess[s] += G[s][i].cap;
		Push(G[s][i]);
	}

	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		active[v] = false;
		Discharge(v);
	}

	long long totflow = 0;
	for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
	return totflow;
}

// Min Cost Matching
double MinCostMatching(const vector< vector<double> > &cost, vector<int> &Lmate, vector<int> &Rmate) {
  int n = int(cost.size());

  // construct dual feasible solution
  vector<double> u(n);
  vector<double> v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
  
  // construct primal solution satisfying complementary slackness
  Lmate = vector<int>(n, -1);
  Rmate = vector<int>(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
	Lmate[i] = j;
	Rmate[j] = i;
	mated++;
	break;
      }
    }
  }
  
  vector<double> dist(n);
  vector<int> dad(n);
  vector<int> seen(n);
  
  // repeat until primal solution is feasible
  while (mated < n) {
    
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
    
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];
    
    int j = 0;
    while (true) {
      
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      
      // termination condition
      if (Rmate[j] == -1) break;
      
      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
	if (seen[k]) continue;
	const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
	if (dist[k] > new_dist) {
	  dist[k] = new_dist;
	  dad[k] = j;
	}
      }
    }
    
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    
    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    
    mated++;
  }
  
  double value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
  
  return value;
}

// Maximum Bipartite Matching 
bool FindMatch(int i, const vector< vector<int> >  &w, vector<int> &mr, vector<int> &mc, vector<int> &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}
int BipartiteMatching(const vector< vector<int> > &w, vector<int> &mr, vector<int> &mc) {
  mr = vector<int>(w.size(), -1);
  mc = vector<int>(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    vector<int> seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

// Min cost Maximum flow
void MinCostMaxFlow::AddEdge(int from, int to, long long cap, long long cost) {
	this->cap[from][to] = cap;
	this->cost[from][to] = cost;
}
void MinCostMaxFlow::Relax(int s, int k, long long cap, long long cost, int dir) {
	long long val = dist[s] + pi[s] - pi[k] + cost;
	if (cap && val < dist[k]) {
		dist[k] = val;
		dad[k] = make_pair(s, dir);
		width[k] = min(cap, width[s]);
	}
}
long long MinCostMaxFlow::Dijkstra(int s, int t) {
	fill(found.begin(), found.end(), false);
	fill(dist.begin(), dist.end(), numeric_limits<long long>::max() / 4);
	fill(width.begin(), width.end(), 0);
	dist[s] = 0;
	width[s] = numeric_limits<long long>::max() / 4;

	while (s != -1) {
	  int best = -1;
	  found[s] = true;
	  for (int k = 0; k < N; k++) {
	    if (found[k]) continue;
	    Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
	    Relax(s, k, flow[k][s], -cost[k][s], -1);
	    if (best == -1 || dist[k] < dist[best]) best = k;
	  }
	  s = best;
	}

	for (int k = 0; k < N; k++)
	  pi[k] = min(pi[k] + dist[k], numeric_limits<long long>::max() / 4);
	return width[t];
}
pair<long long, long long> MinCostMaxFlow::GetMaxFlow(int s, int t) {
	long long totflow = 0, totcost = 0;
	while (long long amt = Dijkstra(s, t)) {
		totflow += amt;
		for (int x = t; x != s; x = dad[x].first) {
			if (dad[x].second == 1) {
				flow[dad[x].first][x] += amt;
				totcost += amt * cost[dad[x].first][x];
			} else {
				flow[x][dad[x].first] -= amt;
				totcost -= amt * cost[x][dad[x].first];
			}
		}
	}
	return make_pair(totflow, totcost);
}
