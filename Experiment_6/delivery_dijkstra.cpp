#include <iostream>
using namespace std;

#define INF 9999

class Delivery
{
public:
    void dijkstra(int graph[10][10], int n, int source)
    {
        int distance[10];
        int visited[10] = {0};

        for (int i = 0; i < n; i++)
            distance[i] = INF;

        distance[source] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int minDistance = INF;
            int current = -1;

            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && distance[i] < minDistance)
                {
                    minDistance = distance[i];
                    current = i;
                }
            }

            visited[current] = 1;

            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && graph[current][i] != 0 &&
                    distance[current] + graph[current][i] < distance[i])
                {
                    distance[i] = distance[current] + graph[current][i];
                }
            }
        }

        cout << "\nShortest delivery distances from Location "
             << source + 1 << ":" << endl;

        for (int i = 0; i < n; i++)
        {
            cout << "Location " << i + 1 << " = "
                 << distance[i] << " km" << endl;
        }
    }
};

int main()
{
    Delivery delivery;

    int n, source;
    int graph[10][10];

    cout << "Enter number of locations: ";
    cin >> n;

    cout << "Enter distance matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    cout << "Enter starting location number: ";
    cin >> source;

    delivery.dijkstra(graph, n, source - 1);

    return 0;
}