#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int d[1001][10001];
int main()
{
	int n, w;
	scanf("%d %d", &n, &w);
	vector<pair<int, int>> a(n+1);
	for (int i = 1; i <= n; i++) {
		int wi, pi;
		scanf("%d %d", &wi, &pi);
		a[i] = { wi,pi };
	}
	sort(a.begin(), a.end());
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (j < a[i].first) {
				d[i][j] = d[i - 1][j];
			}
			else {
				d[i][j] = max(d[i - 1][j], d[i - 1][j - a[i].first] + a[i].second);
			}
		}
	}
	
	printf("%d",d[n][w]);
	return 0;
}