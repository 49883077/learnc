#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int DIR_XY[8][2] = { { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 } };
const int DIR_G[8] = { 10, 14, 10, 14, 10, 14, 10, 14 };

struct _AstarNode
{
	unsigned int F, G;					// F, G值
	struct _AstarNode *Father;			// 父亲指针
	struct _AstarNode *Next;			// OpenList中下一个节点
	unsigned short X, Y;				// 在地图上的XY坐标
	unsigned char Value;				// 格子值, 越大表示越难于通行
	unsigned char Status;				// 0:Init  1:Opened  2:Clsoed
};

struct Size
{
	int width;
	int height;
};

char MapBlocks[16][16] = {
	{ "               " },
	{ "  *****        " },
	{ "  *****        " },
	{ "    ****       " },
	{ "      ****     " },
	{ "          **** " },
	{ "     ******  **" },
	{ "     ***      *" },
	{ "     *        *" },
	{ "              *" },
	{ "   *           " },
	{ "  ********* ***" },
	{ "    *          " },
	{ "   *****       " },
	{ "        *      " },
	{ " ********      " } };

int MapHeight = 16;
int MapWidth = 16;

struct _AstarNode* NewAstarMap(int width, int height, char MapBlocks[16][16])
{
	struct _AstarNode* AstarMap;
	AstarMap = (struct _AstarNode*)malloc(width * height * sizeof(struct _AstarNode));
	if (AstarMap == nullptr)
	{
		return nullptr;
	}
	memset(AstarMap, 0, width * height * sizeof(struct _AstarNode));
	
	_AstarNode* Node = AstarMap;
	for (int y = 0; y < height ; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Node->X = x;
			Node->Y = y;
			if (MapBlocks[x][y] == '*')
			{
				Node->Value = 1;
			}
			else
			{
				Node->Value = 0;
			}
			Node++;
		}

	}
	return AstarMap;
}

void InitAstarMap(int MapHeight, int MapWidth, struct _AstarNode *AstarMap)
{
	struct _AstarNode *Node = AstarMap;
	for (unsigned int y = 0; y < MapHeight; y++)
	{
		for (unsigned int x = 0; x < MapWidth; x++)
		{
			Node->F = 0;
			Node->G = 0;
			Node->Father = NULL;
			Node->Status = 0;
			Node->Next = NULL;

			Node++;
		}
	}
}

struct _AstarNode *FindNearNode(struct _AstarNode *AstarNode)
{
	struct _AstarNode *Node;
	struct _AstarNode *Max_Node = NULL;
	unsigned int Max_F = 0;
	for (int i = 0; i < 8;i++)
	{
		int X = AstarNode->X + DIR_XY[i][0];
		int Y = AstarNode->X + DIR_XY[i][1];
		// 检查是否已经超过地图界限
		if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
		{
			continue;
		}

		// 通过自己和邻居的相对位于来计算它的地址
		Node = AstarNode + int(DIR_XY[i][1] * MapWidth + DIR_XY[i][0]);

		if (Node->Status != 1)
		{
			continue;
		}

		if (Node->F > AstarNode->F)
		{
			continue;
		}

		if (Node->F > Max_F)
		{
			Max_F = Node->F;
			Max_Node = Node;
		}
	}
	return Max_Node;

}

void InsertNode(struct _AstarNode *AstarNode, struct _AstarNode *OpenList)
{
	struct _AstarNode *Node = OpenList->Next;
	struct _AstarNode *PreNode = OpenList;

	struct _AstarNode *NearNode;
	NearNode = FindNearNode(AstarNode);
	if (NearNode != NULL)
	{
		Node = NearNode;
	}
	AstarNode->Status = 1; //OPEN
	while (Node != NULL)
	{
		if (Node->F > AstarNode->F)
		{
			PreNode->Next = AstarNode;
			AstarNode->Next = Node;
			return;
		}
		PreNode = Node;
		Node = Node->Next;

	}

	// 到了这里，表示AstarNode应该插到OpenList的最后
	PreNode->Next = AstarNode;
	AstarNode->Next = NULL;

}

// 摘取出OpenList的第一个节点
struct _AstarNode *Pop(struct _AstarNode *OpenList)
{
	struct _AstarNode *P = OpenList->Next;
	if (P != NULL)
	{
		OpenList->Next = P->Next;
		P->Next = NULL;
		P->Status = 2;		// Closed
	}
	return(P);
}


struct _AstarNode *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct _AstarNode *AstarMap)
{
	bool IsFounded = false;
	struct _AstarNode *StartNode = AstarMap + SrcY * MapWidth + SrcX;
	struct _AstarNode *StopNode = AstarMap + DstY * MapWidth + DstX;
	struct _AstarNode *CurNode, *ChildNode;
	int G, F, H;
	struct _AstarNode OpenList;
	OpenList.Next = NULL;
	if (SrcX >= MapWidth || SrcY >= MapHeight || SrcX < 0 || SrcY < 0)
	{
		return(NULL);
	}
	if (DstX >= MapWidth || DstY >= MapHeight || DstX < 0 || DstY < 0)
	{
		return(NULL);
	}

	// 如果源本身就是一个阻隔点，直接返回StopNode作为路径的开始点
	if (StartNode->Value > 0)
	{
		return(NULL);
	}

	// 如果目标本身就是一个阻隔点, 直接返回失败
	if (StopNode->Value > 0)
	{
		return(NULL);
	}

	// 源和目标一样，直接返回StartNode作为路径的开始点
	if (StartNode->X == StopNode->X && StartNode->Y == StopNode->Y)
	{
		StartNode->Next = NULL;
		return(StartNode);
	}

	InsertNode(StartNode, &OpenList);

	while (IsFounded == false)
	{
		CurNode = Pop(&OpenList);
		if (CurNode == NULL)
		{
			break;
		}

		static unsigned int DirCount = 0;
		for (int i = 0; i < 8;i++,DirCount++)
		{
			unsigned int DD = DirCount % 8;
			int X = CurNode->X + DIR_XY[DD][0];
			int Y = CurNode->Y + DIR_XY[DD][1];

			// 检查是否已经超过地图界限
			if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
			{
				continue;
			}

			ChildNode = AstarMap + Y * MapWidth + X;

			// 邻居是不可通行格子，下一个。（暂时只支持0,1模式）
			if (ChildNode->Value > 0)
			{
				continue;
			}

			// 邻居为 Closed，下一个
			if (ChildNode->Status == 2)
			{
				continue;
			}

			// 计算邻居的G、H、F值
			G = CurNode->G + DIR_G[DD];
			H = abs(SrcX - DstX) * 10 + abs(SrcY - DstY) * 10;
			F = H + G;

			if (ChildNode->Status != 1)
			{
				ChildNode->Father = CurNode;
				ChildNode->G = G;
				ChildNode->F = F;

				InsertNode(ChildNode, &OpenList);

				// 检查是否为 目标点，是就表示找到，结束寻路
				if (ChildNode->X == StopNode->X && ChildNode->Y == StopNode->Y)
				{
					IsFounded = true;
					break;
				}
			}
			else
			{
				// 邻居在 OpenList 中，
				// 如果邻居现在的G值比在OpenList的G值小，更新它
				// 下面这段代码不能提前，否则会导致G提前被修改
				if (ChildNode->G > G)
				{
					ChildNode->G = G;
					ChildNode->F = F;
					ChildNode->Father = CurNode;
				}
			}
		} //end for

	}//end while

	// 路径存在，从 目标点 回溯到 开始点，产生正向路径
	// 从开始点开始，借用Next来保存路径
	if (IsFounded == true)
	{
		struct _AstarNode *P = StopNode;
		struct _AstarNode *Father = NULL;

		P->Next = NULL;				// 设置路径最后标志

		while (P != NULL)
		{
			Father = P->Father;

			if (Father == NULL)		// 异常检查，保持不会出现Core
			{
				return(NULL);
			}

			Father->Next = P;
			if (Father->X == StartNode->X && Father->Y == StartNode->Y)
			{
				break;
			}
			else
			{
				P = Father;
			}
		}

		return(Father);
	}
	else
	{
		return(NULL);
	}

}



int mainAstar()
{
	struct _AstarNode *AStarMap = NewAstarMap(16, 16, MapBlocks);
	if (AStarMap == NULL)
	{
		printf("Map Init Error\n");
		return(0);
	}
	printf("MapBlocks: [*] OK \n");
	for (int i = 0; i < 16; i++)
	{
		printf("%02d:|%s|\n", i, (unsigned char *)MapBlocks + i * 16);
	}

	InitAstarMap(16,16,AStarMap);

	struct _AstarNode *Path = FindPath(0, 0, 15, 15, AStarMap);
	if (Path == NULL)
	{
		printf("Path Not Found\n");
		

		delete(AStarMap);
		return(0);
	}


	printf("RoutePoint: ");
	while (Path->Next != NULL)
	{
		printf("[%d,%d]->", Path->X, Path->Y);

		Path = Path->Next;
	}

	printf("[%d,%d]  End! ", Path->X, Path->Y);


	delete(AStarMap);

	getchar();
}