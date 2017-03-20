#include<cstdio>
#include<queue>
using namespace std;
int a[101][101];
bool chk[101][101];
int dist[101][101];
int dx[] = { 1,-1,2,-2,2,-2,1,-1 };
int dy[] = { 2,2,1,1,-1,-1,-2,-2 };
int n, m, sx, sy, ex, ey;
queue<pair<int, int>> q;
int main()
{
	scanf("%d %d\n", &n, &m);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	chk[sx][sy] = true;
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
				if (!chk[nx][ny] && !dist[nx][ny]) {
					chk[nx][ny] = true;
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	printf("%d", dist[ex][ey]);
	return 0;
}