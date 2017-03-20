#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
char a[51][51];
bool chk[51][51];
int dist[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m, ans;
int bfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!chk[nx][ny] && !dist[nx][ny] && a[nx][ny] != 'W') {
				chk[nx][ny] = true;
				cnt = max(cnt,bfs(nx, ny, cnt + 1));
			}
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				chk[i][j] = true;
				ans = max(ans, bfs(i, j, 0));
				memset(chk, false, sizeof(chk));
				memset(dist, 0, sizeof(dist));
			}
		}
	}

	cout << ans;
	return 0;
}