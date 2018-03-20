/**
* C++: �ڽӾ���ͼ
*
* @author skywang
* @date 2014/04/19
*/

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
class MatrixDG {
private:
	char mVexs[MAX];    // ���㼯��
	int mVexNum;             // ������
	int mEdgNum;             // ����
	int mMatrix[MAX][MAX];   // �ڽӾ���

public:
	// ����ͼ(�Լ���������)
	MatrixDG();
	// ����ͼ(�����ṩ�ľ���)
	MatrixDG(char vexs[], int vlen, char edges[][2], int elen);
	~MatrixDG();

	// ���������������ͼ
	void DFS();
	// ����������������������Ĳ�α�����
	void BFS();
	// ��ӡ�������ͼ
	void print();

private:
	// ��ȡһ�������ַ�
	char readChar();
	// ����ch��mMatrix�����е�λ��
	int getPosition(char ch);
	// ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
	int firstVertex(int v);
	// ���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
	int nextVertex(int v, int w);
	// ���������������ͼ�ĵݹ�ʵ��
	void DFS(int i, int *visited);

};

/*
* ����ͼ(�Լ���������)
*/
MatrixDG::MatrixDG()
{
	char c1, c2;
	int i, p1, p2;

	// ����"������"��"����"
	cout << "input vertex number: ";
	cin >> mVexNum;
	cout << "input edge number: ";
	cin >> mEdgNum;
	if (mVexNum < 1 || mEdgNum < 1 || (mEdgNum >(mVexNum * (mVexNum - 1))))
	{
		cout << "input error: invalid parameters!" << endl;
		return;
	}

	// ��ʼ��"����"
	for (i = 0; i < mVexNum; i++)
	{
		cout << "vertex(" << i << "): ";
		mVexs[i] = readChar();
	}

	// ��ʼ��"��"
	for (i = 0; i < mEdgNum; i++)
	{
		// ��ȡ�ߵ���ʼ����ͽ�������
		cout << "edge(" << i << "): ";
		c1 = readChar();
		c2 = readChar();

		p1 = getPosition(c1);
		p2 = getPosition(c2);
		if (p1 == -1 || p2 == -1)
		{
			cout << "input error: invalid edge!" << endl;
			return;
		}

		mMatrix[p1][p2] = 1;
	}
}

/*
* ����ͼ(�����ṩ�ľ���)
*
* ����˵����
*     vexs  -- ��������
*     vlen  -- ��������ĳ���
*     edges -- ������
*     elen  -- ������ĳ���
*/
MatrixDG::MatrixDG(char vexs[], int vlen, char edges[][2], int elen)
{
	int i, p1, p2;

	// ��ʼ��"������"��"����"
	mVexNum = vlen;
	mEdgNum = elen;
	// ��ʼ��"����"
	for (i = 0; i < mVexNum; i++)
		mVexs[i] = vexs[i];



	// ��ʼ��"��"
	for (i = 0; i < mEdgNum; i++)
	{
		// ��ȡ�ߵ���ʼ����ͽ�������
		p1 = getPosition(edges[i][0]);
		p2 = getPosition(edges[i][1]);

		mMatrix[p1][p2] = 1;
	}
}

/*
* ��������
*/
MatrixDG::~MatrixDG()
{
}

/*
* ����ch��mMatrix�����е�λ��
*/
int MatrixDG::getPosition(char ch)
{
	int i;
	for (i = 0; i<mVexNum; i++)
	if (mVexs[i] == ch)
		return i;
	return -1;
}

/*
* ��ȡһ�������ַ�
*/
char MatrixDG::readChar()
{
	char ch;

	do {
		cin >> ch;
	} while (!((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')));

	return ch;
}


/*
* ���ض���v�ĵ�һ���ڽӶ����������ʧ���򷵻�-1
*/
int MatrixDG::firstVertex(int v)
{
	int i;

	if (v<0 || v>(mVexNum - 1))
		return -1;

	for (i = 0; i < mVexNum; i++)
	if (mMatrix[v][i] == 1)
		return i;

	return -1;
}

/*
* ���ض���v�����w����һ���ڽӶ����������ʧ���򷵻�-1
*/
int MatrixDG::nextVertex(int v, int w)
{
	int i;

	if (v<0 || v>(mVexNum - 1) || w<0 || w>(mVexNum - 1))
		return -1;

	for (i = w + 1; i < mVexNum; i++)
	if (mMatrix[v][i] == 1)
		return i;

	return -1;
}

/*
* ���������������ͼ�ĵݹ�ʵ��
*/
void MatrixDG::DFS(int i, int *visited)
{
	int w;

	visited[i] = 1;
	cout << mVexs[i] << " ";
	// �����ö���������ڽӶ��㡣����û�з��ʹ�����ô����������
	for (w = firstVertex(i); w >= 0; w = nextVertex(i, w))
	{
		if (!visited[w])
			DFS(w, visited);
	}

}

/*
* ���������������ͼ
*/
void MatrixDG::DFS()
{
	int i;
	int visited[MAX];       // ������ʱ��

	// ��ʼ�����ж��㶼û�б�����
	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;

	cout << "DFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		printf("\n== LOOP(%d)\n", i);
		if (!visited[i])
			DFS(i, visited);
	}
	cout << endl;
}

/*
* ����������������������Ĳ�α�����
*/
void MatrixDG::BFS()
{
	int head = 0;
	int rear = 0;
	int queue[MAX];     // �������
	int visited[MAX];   // ������ʱ��
	int i, j, k;

	for (i = 0; i < mVexNum; i++)
		visited[i] = 0;

	cout << "BFS: ";
	for (i = 0; i < mVexNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << mVexs[i] << " ";
			queue[rear++] = i;  // �����
		}
		while (head != rear)
		{
			j = queue[head++];  // ������
			for (k = firstVertex(j); k >= 0; k = nextVertex(j, k)) //k��Ϊ���ʵ��ڽӶ���
			{
				if (!visited[k])
				{
					visited[k] = 1;
					cout << mVexs[k] << " ";
					queue[rear++] = k;
				}
			}
		}
	}
	cout << endl;
}

/*
* ��ӡ�������ͼ
*/
void MatrixDG::print()
{
	int i, j;

	cout << "Martix Graph:" << endl;
	for (i = 0; i < mVexNum; i++)
	{
		for (j = 0; j < mVexNum; j++)
		if (mMatrix[i][j] < -1)
			cout << 0  << " ";
		else
			cout << mMatrix[i][j] << " ";
		cout << endl;
	}
}


int main2()
{
	char vexs[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
	char edges[][2] = {
		{ 'A', 'B' },
		{ 'B', 'C' },
		{ 'B', 'E' },
		{ 'B', 'F' },
		{ 'C', 'E' },
		{ 'D', 'C' },
		{ 'E', 'B' },
		{ 'E', 'D' },
		{ 'F', 'G' } };
	int vlen = sizeof(vexs) / sizeof(vexs[0]);
	int elen = sizeof(edges) / sizeof(edges[0]);
	MatrixDG* pG;

	// �Զ���"ͼ"(����������)
	//pG = new MatrixDG();
	// �������е�"ͼ"
	pG = new MatrixDG(vexs, vlen, edges, elen);

	pG->print();   // ��ӡͼ
	pG->DFS();     // ������ȱ���
	pG->BFS();     // ������ȱ���
	system("pause");
	return 0;
}