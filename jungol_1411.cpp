#include<cstdio>
using namespace std;
int d[100001];
const int MOD = 20100529;
int main()
{
	int n;
	scanf("%d", &n);
	d[0] = d[1] = 1;
	for (int i = 2; i <= n; i++)
		d[i] = (d[i - 1] + 2 * d[i - 2]) % MOD;
	printf("%d", d[n]);
	return 0;
}