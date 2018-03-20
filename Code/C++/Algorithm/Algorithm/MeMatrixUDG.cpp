#include <iomanip>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10

class MeMatrixUDG
{
public:
	//

	MeMatrixUDG(int edges[][2], int vexs[]);
	~MeMatrixUDG();
	void DFS(int edges[6][2], int vexs[5]);
	void BFS(int edges[6][2], int vexs[5]);
	void DFS(int edges[6][2], int vexs[5], int i);
private:
	int visited[MAX];

	int mMatrix[MAX][MAX];
};

MeMatrixUDG::MeMatrixUDG(int edges[6][2], int vexs[5])
{
	int verSize = 5;
	int edgeLen = 6;

	int i, j, p1, p2 = 0;

	
	for (i = 0; i < MAX;i++)
	{
		for (j = 0; j < MAX; j++)
		{
			mMatrix[i][j] = 0;
		}
	}

	for (i = 0; i < edgeLen; i++)
	{
		// 读取边的起始顶点和结束顶点
		p1 =edges[i][0] -1;
		p2 =edges[i][1] -1;

		mMatrix[p1][p2] = 1;
	//mMatrix[p2][p1] = 1;
	}


	for (i = 0; i < verSize; i++)
	{
		for (j = 0; j < verSize; j++)
			cout << mMatrix[i][j] << " ";
		cout << endl;
	}

	cout << "DFS ";

	
}

void MeMatrixUDG::DFS(int edges[6][2], int vexs[5])
{
	int i;
	for (i = 0; i < 5;i++)
	{
		visited[i] = 0;
	}

	for (i = 0; i < 5; i++)
	{
		if (!visited[i])
		{
			DFS(edges,vexs, i);
		}
	}

}

void MeMatrixUDG::DFS(int edges[6][2], int vexs[5] ,int i)
{
	int j;
	visited[i] = 1;
	cout << vexs[i] << " ";
	for (j = 0; j < 5; j++)
	{
		if (mMatrix[i][j] == 1 && !visited[j])
		{
			DFS(edges, vexs, j);
		}
	}

}

void MeMatrixUDG::BFS(int edges[6][2], int vexs[5])
{
	cout << "BFS \n";
	int i, j = 0;
	queue<int> q1;
	for (i = 0; i < 5; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < 5; i++)
	{
		if (!visited[i])
		{
			cout << "push " << vexs[i] << " ";
			
			q1.push(vexs[i]);
			visited[i] = 1;

			while (!q1.empty())
			{
				int m = q1.front();
				//cout << "m=" << m << "  ";
				q1.pop();

				for (j = 0; j < 5; j++)
				{
					if (edges[m][j] == 1 && !visited[j])
					{
						visited[j] = 1;
						cout <<"push " << vexs[j] << " \n";
						q1.push(vexs[j]);
					}
				}

			}
		
		}
	}

}



void main1()
{
	int vexs[5] = { 1, 2, 3, 4, 5 };
	int edges[6][2] = {
		{ 1, 2 },
		{ 2, 4 },
		{ 1, 3 },
		{ 3, 5 },
		{ 2, 3 },
		{ 4, 5 }
	};

	MeMatrixUDG *udg = new MeMatrixUDG(edges, vexs);

	udg->DFS(edges, vexs);
	udg->BFS(edges, vexs);
	getchar();

}
