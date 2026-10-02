#include <iostream>
using namespace std;

#define INF 9999

class Electricity
{
public:
    void prims(int graph[10][10], int n)
    {
        int selected[10] = {0};
        int edges = 0;
        int totalCost = 0;

        selected[0] = 1;

        cout << "\nPrim's MST:" << endl;

        while (edges < n - 1)
        {
            int min = INF;
            int x = 0, y = 0;

            for (int i = 0; i < n; i++)
            {
                if (selected[i])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (!selected[j] && graph[i][j] != 0 &&
                            graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

            cout << "Station " << x + 1 << " - Station " << y + 1
                 << " : " << min << " units" << endl;

            totalCost += min;
            selected[y] = 1;
            edges++;
        }

        cout << "Minimum Distribution Cost = " << totalCost << endl;
    }

    int findParent(int parent[], int vertex)
    {
        while (parent[vertex] != vertex)
            vertex = parent[vertex];

        return vertex;
    }

    void kruskals(int graph[10][10], int n)
    {
        int parent[10];

        for (int i = 0; i < n; i++)
            parent[i] = i;

        int edges = 0;
        int totalCost = 0;

        cout << "\nKruskal's MST:" << endl;

        while (edges < n - 1)
        {
            int min = INF;
            int x = 0, y = 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (graph[i][j] != 0 && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }

            int rootX = findParent(parent, x);
            int rootY = findParent(parent, y);

            if (rootX != rootY)
            {
                cout << "Station " << x + 1 << " - Station " << y + 1
                     << " : " << min << " units" << endl;

                totalCost += min;
                parent[rootX] = rootY;
                edges++;
            }

            graph[x][y] = INF;
            graph[y][x] = INF;
        }

        cout << "Minimum Distribution Cost = " << totalCost << endl;
    }
};

int main()
{
    Electricity electricity;

    int n;

    cout << "Enter number of electricity stations: ";
    cin >> n;

    int graph[10][10];

    cout << "Enter connection cost matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    int graphCopy[10][10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            graphCopy[i][j] = graph[i][j];
    }

    electricity.prims(graph, n);
    electricity.kruskals(graphCopy, n);

    return 0;
}