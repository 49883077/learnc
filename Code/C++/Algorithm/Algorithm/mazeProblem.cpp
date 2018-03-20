#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


struct Point{
	//行与列
	int row;
	int col;
	Point(int x, int y){
		this->row = x;
		this->col = y;
	}

	bool operator!=(const Point& rhs){
		if (this->row != rhs.row || this->col != rhs.col)
			return true;
		return false;
	}
};

Point getNearNode(vector<vector<int>> maze, vector<vector<int>> visited, Point point, int m, int n){
	//cout << "m=" << m << "  n=" << n;
	//cout << "Point=col" << point.col << "= row" << point.row;
	Point resP(-1, -1);
	if (point.row - 1 >= 0 && maze[point.row - 1][point.col] == 0 && visited[point.row - 1][point.col] == 0){//上节点满足条件
		resP.row = point.row - 1;
		resP.col = point.col;
		return resP;
	}
	if (point.col + 1 < n&&maze[point.row][point.col + 1] == 0 && visited[point.row][point.col + 1] == 0){//右节点满足条件
		resP.row = point.row;
		resP.col = point.col + 1;
		return resP;
	}
	if (point.row + 1 < m&&maze[point.row + 1][point.col] == 0 && visited[point.row + 1][point.col] == 0){//下节点满足条件
		resP.row = point.row + 1;
		resP.col = point.col;
		return resP;
	}
	if (point.col - 1 >= 0 && maze[point.row][point.col - 1] == 0 && visited[point.row][point.col - 1] == 0){//左节点满足条件
		resP.row = point.row;
		resP.col = point.col - 1;
		return resP;
	}
	return resP;
}


void mazePath(vector<vector<int>> maze, int row, int col, Point &start, Point& end, stack<Point>& pointStack)
{
	vector<vector<int>> visited(row, vector<int>(col, 0));
	
	pointStack.push(start);
	visited[start.row][start.col] = 1;
	while (!pointStack.empty() && pointStack.top() != end)
	{
		Point adjP = getNearNode(maze,visited, pointStack.top(), row, col);
		//回溯
		if (adjP.row == -1 || adjP.col == -1)
		{
			pointStack.pop();
			continue;
		}
		visited[adjP.row][adjP.col] = 1;
		pointStack.push(adjP);
	}
	

}


void main()
{
	vector<vector<int>> maze = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 1, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 0, 0, 0, 0 }
	};

	int col = maze[0].size();
	int row = maze.size();

	Point starP(0, 0);
	Point endP(4, 4);
	//mazePath(maze, 5, 5, startP, endP, )
	stack<Point> pointStack;
	mazePath(maze,row, col, starP, endP, pointStack);

	if (pointStack.empty())
	{
		cout << "no right path";
	}
	else
	{
		stack<Point> tmpStack;
		cout << "path:";
		while (pointStack.empty() == false){
			tmpStack.push(pointStack.top());
			pointStack.pop();
		}
		while (tmpStack.empty() == false){
			printf("(%d,%d) ", tmpStack.top().row, tmpStack.top().col);
			tmpStack.pop();
		}
	}

	getchar();
}