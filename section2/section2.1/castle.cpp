
/*
ID: ninanxi2
PROG: castle
LANG: C++11
*/


#include <fstream>
using namespace std;

int m, n;
int roomN;			// room Number
int room[51][51];		// room[1][1] == 1 means vertex(1,1) belongs to room1
int size[50*50+1];		// size[1] = 5; means room1 consists of 5 vertices
int Smax;			// max Room Size
int wall[51][51][4];	 // wall[1][1][0] means if there is a wall in the west , similar to east, north and south 默认0有墙方便
int check[51][51];		// check[1][1] means vertex(1,1) has been visited or not
void dfs(int i, int j);


int main()
{
	ifstream fin("castle.in");
	ofstream fout("castle.out");

	fin >> m >> n;
	
	int tmp;
	int i, j, k;
	for(i=1; i<=n; i++)		
		for(j=1; j<=m; j++)
		{
			fin >> tmp;
			for(k=0; k<4; k++) wall[i][j][k] = (tmp >> k) & 1;		//set the wall     利用二进制 [0]=1=1(W)   [1]=10=2(N)  
		}                                                           //                           [2]=100=4(E) [3]=1000=8(S)

	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
		{
			if(!check[i][j])
			{
				++roomN;	//update room Number
				dfs(i,j);	//dfs
				Smax = (size[roomN] > Smax) ? size[roomN]:Smax;
			}
		}

	fout << roomN << endl << Smax << endl;

	Smax = 0;
	int roomA, roomB, roomC;		//roomB is the vertex upon roomA, roomC is the vertex in the right of roomA
	int ans_x, ans_y;
	char di;                                                                 //     roomB 
	//traverse all the vertex and try to remove north wall and east wall            roomA roomC  决定于输出方式
	//
	//要多个相同最优里面最左里面最下的，就从最左开始从下往上垂直遍历，依次向右
	//先靠西(水平)优先 再靠南(垂直) 所以 垂直循环要嵌套在水平循环里面
	//
	for(i=1; i<=m; i++)
		for(j=n; j>=1; j--)
		{
			roomA = room[j][i];
			roomB = room[j-1][i];	
			roomC = room[j][i+1];	
			if(j >1 && wall[j][i][1] && roomA!=roomB && size[roomA]+size[roomB] > Smax)
			{
				Smax = size[roomA]+size[roomB];
				ans_x = j;
				ans_y = i;
				di = 'N';
			}
			else if(i<m && wall[j][i][2]  && roomA!=roomC && size[roomA]+size[roomC] > Smax)
			{
				Smax = size[roomA]+size[roomC];
				ans_x = j;
				ans_y = i;
				di = 'E';
			}
		}

	fout << Smax << endl << ans_x << " " << ans_y << " " << di << endl;

	return 0;
}

void dfs(int i, int j)
{
	if(room[i][j] == roomN) return;
	check[i][j] = 1;
	size[roomN]++;
	room[i][j] = roomN;
	if(!wall[i][j][0]) dfs(i,j-1);
	if(!wall[i][j][1]) dfs(i-1,j);
	if(!wall[i][j][2]) dfs(i,j+1);
	if(!wall[i][j][3]) dfs(i+1,j);           // 利用二进制    [0]=1=1(W)    [1]=10=2(N)
										    //	             [2]=100=4(E)  [3]=1000=8(S)
}
