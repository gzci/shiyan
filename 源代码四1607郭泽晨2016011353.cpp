// 我真诚地保证：
    
// 我自己独立地完成了整个程序从分析、设计到编码的所有工作。
// 如果在上述过程中，我遇到了什么困难而求教于人，那么，我将在程序实习报告中
// 详细地列举我所遇到的问题，以及别人给我的提示。

// 在此，我感谢我的同学对我的启发和帮助。下面的报告中，我还会具体地提到
// 他们在各个方法对我的帮助。
 
// 我的程序里中凡是引用到其他程序或文档之处，
// 例如教材、课堂笔记、网上的源代码以及其他参考书上的代码段,
// 我都已经在程序的注释里很清楚地注明了引用的出处。

// 我从未没抄袭过别人的程序，也没有盗用别人的程序，
// 不管是修改式的抄袭还是原封不动的抄袭。

    // 我编写这个程序，从来没有想过要去破坏或妨碍其他计算机系统的正常运转。
    
    // <郭泽晨>

#include<iostream>
#include<queue>
#include<string>
using namespace std;
int visitedf[20]={0};  
struct ArcNode
{
	int adjvex;               //该弧所指向的顶点的位置
	ArcNode * next;           //指向下一条弧的指针
	                          //int weight;边上是否有权
};

typedef struct VNode
{
	char vertex;              //顶点信息
	ArcNode * firstarc;       //指向第一条依附该顶点的弧的指针 
}AdjList[20];

struct ALGraph
{
	AdjList adjList;
	int vexNum;               //图的顶点数
	int arcNum;               //图的弧数
};

bool visited[20];//设置标志数组

void CreateGraph(ALGraph & graph);
void PrintGraph(ALGraph & graph);
void DFSTraverse(ALGraph & graph);
void BFSTraverse(ALGraph & graph);



void CreateGraph(ALGraph & graph)
{
	////////1.输入顶点数和弧数
	cout << "请输入图的顶点数: ";
	cin >> graph.vexNum;
	cout << "请输入图的弧数: ";
	cin >> graph.arcNum;

	///////2.输入顶点信息
	cout << "请输入" << graph.vexNum << "个顶点信息: ";
	for (int i = 0; i < graph.vexNum; i++)
	{
		cin >> graph.adjList[i].vertex;
		graph.adjList[i].firstarc = NULL;
	}

	///////3.根据输入的弧的信息构造邻接表
	cout << "请输入" << graph.arcNum << "个弧的信息: \n";
	int h1, h2;
	ArcNode * temp;
	for (int i = 0; i < graph.arcNum; i++)
	{
		cin >> h1 >> h2;

		temp = new ArcNode;
		temp->adjvex = h2;
		temp->next = graph.adjList[h1].firstarc;
		graph.adjList[h1].firstarc = temp;

		temp = new ArcNode;
		temp->adjvex = h1;
		temp->next = graph.adjList[h2].firstarc;
		graph.adjList[h2].firstarc = temp;
	}
}

void PrintGraph(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)
	{
		cout << graph.adjList[i].vertex << "------>";
		ArcNode * p = graph.adjList[i].firstarc;
		while (p)
		{
			cout << graph.adjList[p->adjvex].vertex << "  ";
			p = p->next;
		}

		cout << endl;
	}
}

void DFS(ALGraph & graph, int v)
{
	visited[v] = true;
	cout << graph.adjList[v].vertex << " ";

	ArcNode * p = graph.adjList[v].firstarc;

	while (p)
	{
		if (!visited[p->adjvex])
			DFS(graph, p->adjvex);

		p = p->next;
	}
}

void DFSTraverse(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)//初始化访问标志数组
		visited[i] = false;

	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//如果没有访问
			DFS(graph, i);
	}
}

void BFSTraverse(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)//初始化访问标志数组 
		visited[i] = false;

	queue<int> q;

	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//如果没有访问过
		{
			visited[i] = true;
			q.push(i);//访问过的入队列
			cout << graph.adjList[i].vertex << " ";

			while (!q.empty())//队列不为空时
			{
				int x = q.front();
				q.pop();//先取出队首第一个元素，然后将第一个元素删除
				ArcNode * p = graph.adjList[x].firstarc;
				while (p)//访问未被访问过的邻接顶点
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = true;
						cout << graph.adjList[p->adjvex].vertex << " ";
						q.push(p->adjvex);
					}

					p = p->next;
				}
			}
		}
	}
}
int exist_path_len(ALGraph G,int i,int j,int k)   
{  
    if(i==j&&k==0) {
    	cout<<G.adjList[i].vertex;
        return 1; 
	}
    
    else if(k>0)  
    {  
        visitedf[i]=1;  
        for(ArcNode * p=G.adjList[i].firstarc;p;p=p->next)  
        {  
            int temp=p->adjvex;  
            if(!visitedf[temp]&&exist_path_len(G,temp,j,k-1)) {
            	cout<<G.adjList[i].vertex;
				return 1;  
			}
                 
		}   
        visitedf[i]=0;  
//这里需要把已经访问的点重新置为0，因为如果当前不存在长度为k  
//到达j点，那么这个点还是可以使用的，因为有可能从其他点出发  
//可以到达j点并且长度为k   
    }   
    
    return 0;  
}  

int main()
{

/*

8
9

A B C D E F G H
0 1 2 3 4 5 6 7
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 6

*/

/*

8
9

A B C D E F G H
0 1
0 2
1 3
1 4
2 5
2 6
3 7
4 7
5 6

*/
	ALGraph graph;

	//1.创建邻接表
	CreateGraph(graph);

	//2.打印邻接表
	cout << "\n邻接表打印为: \n";
	PrintGraph(graph);

	//3.深度优先搜索DFS
	cout << "\n深度优先搜索DFS: ";
	DFSTraverse(graph);
	cout << endl;

	//4.广度优先搜索BFS
	cout << "\n广度优先搜索BFS: ";
	BFSTraverse(graph);
	cout << endl<<endl;
	exist_path_len(graph,0,5,3)  ;
	return 0;
}
