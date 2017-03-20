#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int end_time, alive, n, m, sx,sy;
int a[100][100];
bool chk[100][100];
int dist[100][100];
queue<pair<int, int>> q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main()
{
	scanf("%d %d\n",&m,&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",&a[i][j]);
		}
	}
	scanf("%d %d", &sy, &sx);
	sy--; sx--;
	chk[sx][sy] = true;
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny] == 1 && !chk[nx][ny] && !dist[nx][ny]) {
					chk[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					end_time = max(end_time, dist[nx][ny]);
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1 && !chk[i][j]) alive++;
		}
	}
	printf("%d\n%d",end_time+3,alive);
	return 0;
}