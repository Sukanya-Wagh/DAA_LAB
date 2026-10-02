#include <iostream>
using namespace std;

class Cargo
{
public:
    void knapsack(int weight[], int value[], int n, int capacity)
    {
        float ratio[100];

        for (int i = 0; i < n; i++)
        {
            ratio[i] = (float)value[i] / weight[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(weight[i], weight[j]);
                    swap(value[i], value[j]);
                }
            }
        }

        float totalValue = 0;
        int remaining = capacity;

        for (int i = 0; i < n; i++)
        {
            if (weight[i] <= remaining)
            {
                remaining -= weight[i];
                totalValue += value[i];
            }
            else
            {
                totalValue += ratio[i] * remaining;
                break;
            }
        }

        cout << "Maximum value that can be loaded = " << totalValue << endl;
    }
};

int main()
{
    Cargo cargo;

    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int *weight = new int[n];
    int *value = new int[n];

    cout << "Enter weights of items:" << endl;

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values of items:" << endl;

    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter truck capacity: ";
    cin >> capacity;

    cargo.knapsack(weight, value, n, capacity);

    delete[] weight;
    delete[] value;

    return 0;
}