#include "foo.h"

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