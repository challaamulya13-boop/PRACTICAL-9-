#include <iostream>
using namespace std;

#define INF 999

void prim(int graph[10][10], int n)
{
    int selected[10] = {0};
    int edgeCount = 0;
    int totalCost = 0;

    // Start from vertex 1
    selected[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edgeCount < n - 1)
    {
        int min = INF;
        int x = -1, y = -1;

        // Find minimum edge
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        // Add edge to MST
        cout << x + 1 << " - " << y + 1
             << " : " << min << endl;

        totalCost += min;
        selected[y] = 1;
        edgeCount++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;
}

int main()
{
    int n;
    int graph[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            // No edge
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    prim(graph, n);

    return 0;
}
