// ����ϵر�֤��
    
// ���Լ��������������������ӷ�������Ƶ���������й�����
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ������
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��

// �ڴˣ��Ҹ�л�ҵ�ͬѧ���ҵ������Ͱ���������ı����У��һ��������ᵽ
// �����ڸ����������ҵİ�����
 
// �ҵĳ������з������õ�����������ĵ�֮����
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����

// �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��

    // �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��
    
    // <����>

#include<iostream>
#include<queue>
#include<string>
using namespace std;
int visitedf[20]={0};  
struct ArcNode
{
	int adjvex;               //�û���ָ��Ķ����λ��
	ArcNode * next;           //ָ����һ������ָ��
	                          //int weight;�����Ƿ���Ȩ
};

typedef struct VNode
{
	char vertex;              //������Ϣ
	ArcNode * firstarc;       //ָ���һ�������ö���Ļ���ָ�� 
}AdjList[20];

struct ALGraph
{
	AdjList adjList;
	int vexNum;               //ͼ�Ķ�����
	int arcNum;               //ͼ�Ļ���
};

bool visited[20];//���ñ�־����

void CreateGraph(ALGraph & graph);
void PrintGraph(ALGraph & graph);
void DFSTraverse(ALGraph & graph);
void BFSTraverse(ALGraph & graph);



void CreateGraph(ALGraph & graph)
{
	////////1.���붥�����ͻ���
	cout << "������ͼ�Ķ�����: ";
	cin >> graph.vexNum;
	cout << "������ͼ�Ļ���: ";
	cin >> graph.arcNum;

	///////2.���붥����Ϣ
	cout << "������" << graph.vexNum << "��������Ϣ: ";
	for (int i = 0; i < graph.vexNum; i++)
	{
		cin >> graph.adjList[i].vertex;
		graph.adjList[i].firstarc = NULL;
	}

	///////3.��������Ļ�����Ϣ�����ڽӱ�
	cout << "������" << graph.arcNum << "��������Ϣ: \n";
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
	for (int i = 0; i < graph.vexNum; i++)//��ʼ�����ʱ�־����
		visited[i] = false;

	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//���û�з���
			DFS(graph, i);
	}
}

void BFSTraverse(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)//��ʼ�����ʱ�־���� 
		visited[i] = false;

	queue<int> q;

	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//���û�з��ʹ�
		{
			visited[i] = true;
			q.push(i);//���ʹ��������
			cout << graph.adjList[i].vertex << " ";

			while (!q.empty())//���в�Ϊ��ʱ
			{
				int x = q.front();
				q.pop();//��ȡ�����׵�һ��Ԫ�أ�Ȼ�󽫵�һ��Ԫ��ɾ��
				ArcNode * p = graph.adjList[x].firstarc;
				while (p)//����δ�����ʹ����ڽӶ���
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
//������Ҫ���Ѿ����ʵĵ�������Ϊ0����Ϊ�����ǰ�����ڳ���Ϊk  
//����j�㣬��ô����㻹�ǿ���ʹ�õģ���Ϊ�п��ܴ����������  
//���Ե���j�㲢�ҳ���Ϊk   
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

	//1.�����ڽӱ�
	CreateGraph(graph);

	//2.��ӡ�ڽӱ�
	cout << "\n�ڽӱ��ӡΪ: \n";
	PrintGraph(graph);

	//3.�����������DFS
	cout << "\n�����������DFS: ";
	DFSTraverse(graph);
	cout << endl;

	//4.�����������BFS
	cout << "\n�����������BFS: ";
	BFSTraverse(graph);
	cout << endl<<endl;
	exist_path_len(graph,0,5,3)  ;
	return 0;
}
