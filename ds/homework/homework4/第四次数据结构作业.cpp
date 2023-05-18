#include<bits/stdc++.h>
using namespace std;
#include "../../Graph/Graph.h"

int main() {
    // ����һ���� 10�����������ͼ
    Graph g(10);

    // ��ӱ�
    g.add(0, 1, 2);
    g.add(0, 4, 3);
    g.add(1, 2, 6);
    g.add(1, 3, 5);
    g.add(1, 4, 1);
    g.add(2, 3, 9);
    g.add(3, 4, 2);
    g.add(1, 7, 1);
    g.add(2, 6, 7);
    g.add(0, 5, 7);
    g.add(5, 4, 17);
    g.add(3, 8, 2);
	g.add(6, 9, 15);
    // ִ��������ȱ����͹�����ȱ���
    cout << "DFS: ";
    g.DFS();
    cout << endl;

    cout << "BFS: ";
    g.BFS();
    cout << endl;

    // ִ��Dijkstra�㷨
    vector<int> dist; 
    g.dijkstra(0, dist); 
    cout << "Dijkstra distances from source vertex 0: "; 
    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    // ִ����С�������㷨
    cout << "Minimum Spanning Tree: " << endl;
    g.primMST();

    return 0;
}
