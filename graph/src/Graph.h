
#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef void Graph;
typedef void Vertex;

/* ������������n�������ͼ */
Graph* Graph_Create(int n);

/* ����graph��ָ���ͼ */
void Graph_Destroy(Graph* graph);

/* ��graph��ָͼ�ı߼������ */
void Graph_Clear(Graph* graph);

/* ��graph��ָͼ�е�v1��v2֮����ϱߣ��ұߵ�ȨΪw */
int Graph_AddEdge(Graph* graph, int v1, int v2, int w);

/* ��graph��ָͼ��v1��v2֮��ı�ɾ��������Ȩֵ */
int Graph_RemoveEdge(Graph* graph, int v1, int v2);

/* ��graph��ָͼ��v1��v2֮��ıߵ�Ȩֵ���� */
int Graph_GetEdge(Graph* graph, int v1, int v2);

/* ��graph��ָͼ��v����Ķ��� */
int Graph_TD(Graph* graph, int v);

/* ��graph��ָͼ�еĶ��������� */
int Graph_VertexCount(Graph* graph);

/* ��graph��ָͼ�еı������� */
int Graph_EdgeCount(Graph* graph);

#endif
