#include"pch.h"
#pragma warning (disable:4996)
using namespace std;

int m, n; // m row n col, max 25;
char mat[25][25];
int vis[25][25];
int sx, sy, tx, ty;
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 }; // 0 Right, 1 Down, 2 Left, 3 Up 
struct node{
	int x, y, step;
	bool operator < (const node &b) const{
		return step > b.step;
	}
};
void bfs() {
	node u, v;
	u.x = sx; u.y = sy; u.step = 0;
	memset(vis, -1, sizeof(vis));
	vis[sx][sy] = 0;
	priority_queue<node> q;
	q.push(u);
	//cout<<"BFS"<<endl;
	while (!q.empty()) {
		u = q.top(); q.pop();
		// cout << u.x << " " << u.y << " "<<u.step<<endl;
		// ����ǰ���ж��յ�����Ϊ ��ֱ��ʱ��+2�ˣ�
		// ��������жϣ�ͬ��ʱ�䣨+2�����յ㣩�ڣ�+1�����յ㣩֮ǰ�����
		// �����ȶ���һ����ʱ���ٵ���ǰ������͵����
		if (u.x == tx && u.y == ty) {
			cout << u.step << endl;
			return;
		}
		// 0 Right, 1 Down, 2 Left, 3 Up
		for (int i = 0; i < 4; i++) {
			v = u; v.x += dir[i][0]; v.y += dir[i][1];
			v.step++;
			if (v.x < 0 || v.y < 0 || v.x == m || v.y == n || mat[v.x][v.y] =='*') continue;
			// ����ż��ʱ���൱�ڴ���0ʱ��¥�ݲ���
			if ((u.step & 1) == 0) {
				if (mat[v.x][v.y] == '-') {
					v.x += dir[i][0]; v.y += dir[i][1];
					// 1 3 Down Up
					if (i & 1) {
						v.step++;
					}
				}
				else if (mat[v.x][v.y] == '|') {
					v.x += dir[i][0]; v.y += dir[i][1];
					// 0 2 Right Left
					if ((i & 1) == 0) {
						v.step++;
					}
				}
			}
			else {
				if (mat[v.x][v.y] == '|') {
					v.x += dir[i][0]; v.y += dir[i][1];
					// 1 3 Down Up
					if (i & 1) {
						v.step++;
					}
				}
				else if (mat[v.x][v.y] == '-') {
					v.x += dir[i][0]; v.y += dir[i][1];
					// 0 2 Right Left
					if ((i & 1) == 0) {
						v.step++;
					}
				}
			}
			if (v.x < 0 || v.y < 0 || v.x == m || v.y == n) continue;
			if (vis[v.x][v.y] == -1 || v.step < vis[v.x][v.y]) {
				vis[v.x][v.y] = v.step;
				q.push(v);
			}
		}
	}
}
int main() {
	// read
	while (~scanf("%d%d", &m, &n)) {
		for (int i = 0; i < m; i++) {
			getchar();
			for (int j = 0; j < n; j++) {
				mat[i][j] = getchar();
				if (mat[i][j] == 'S') {
					sx = i; sy = j;
				}
				else if (mat[i][j] == 'T') {
					tx = i; ty = j;
				}
			}
		}
		//cout << sx << sy << tx << ty << endl;
		// bfs
		bfs();
	}
}