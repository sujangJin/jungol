#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int M,N, index=0;
int startx[1001], starty[1001];
int used[1001][1001];
int Dx[4] = { 1, -1, 0, 0 };
int Dy[4] = { 0, 0, 1, -1 };
int days = 0;

queue<int> Qx, Qy;


int main()
{
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			used[i][j] = -1;
	
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%d", &used[i][j]);
			if (used[i][j] == 1){
				Qx.push(j);
				Qy.push(i);
				//startx[index] = j; 
				//starty[index] = i;
				//index++;
			}
		}
	}
	
	while (!Qx.empty()){
		int size = Qx.size();
		
		for (int j = 0; j < size; j++){
			
			int curr_x = Qx.front();
			Qx.pop();
			int curr_y = Qy.front();
			Qy.pop();
			
			for (int i = 0; i < 4; i++){
				int tmpx = curr_x + Dx[i];
				int tmpy = curr_y + Dy[i];
				if (tmpx >= 0 && tmpx <= 1000 && tmpy >= 0 && tmpy <= 1000){
					if (used[tmpy][tmpx] == 0)	{
						used[tmpy][tmpx] = 1;
						Qx.push(tmpx);
						Qy.push(tmpy);
					}
				}
			}
		}
		days++;
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (used[i][j] == 0) { printf("-1\n"); return 0; }
		}
	}

	printf("%d", days-1);
}