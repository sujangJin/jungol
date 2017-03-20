#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int d[1001];
vector<pair<int, int>> a;
int main()
{
	int n, w;
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) {
		int w, val;
		scanf("%d %d", &w, &val);
		a.push_back({ w, val });
	}
	sort(a.begin(), a.end());
	
	d[a.front().first] = a.front().second;
	for (int j = 0; j < a.size(); j++) {
		for (int i = a.front().first; i <= w; i++) {
			if (i - a[j].first >= 0)
				d[i] = max(d[i], d[i-a[j].first] + a[j].second);
		}
	}
	printf("%d",d[w]);
	return 0;
}