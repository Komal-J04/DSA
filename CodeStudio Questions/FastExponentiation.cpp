#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// x^ n = x * x * x * x ...... n times
	// (x*x) % m = (x%m)*(x%m)
	// (x^n)%m = (x%m) * (x%m) * (x%m) * ......

	int64_t res=1;
	while(n>0)
	{
		if(n&1) res = (1LL * res * x)%m; //odd
		x = (1LL * x * x)%m;

		n = n>>1;
	}

	return res;
}