#include <iostream>
using namespace std;

class Food
{
public:
    void knapsack(int weight[], int nutrition[], int n, int capacity)
    {
        float ratio[100];

        for (int i = 0; i < n; i++)
            ratio[i] = (float)nutrition[i] / weight[i];

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(weight[i], weight[j]);
                    swap(nutrition[i], nutrition[j]);
                }
            }
        }

        float totalNutrition = 0;
        int remaining = capacity;

        for (int i = 0; i < n; i++)
        {
            if (weight[i] <= remaining)
            {
                remaining -= weight[i];
                totalNutrition += nutrition[i];
            }
            else
            {
                totalNutrition += ratio[i] * remaining;
                break;
            }
        }

        cout << "Maximum nutrition value = " << totalNutrition << endl;
    }
};

int main()
{
    Food food;

    int n, capacity;

    cout << "Enter number of food items: ";
    cin >> n;

    int *weight = new int[n];
    int *nutrition = new int[n];

    cout << "Enter weights of food items:" << endl;

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter nutrition values:" << endl;

    for (int i = 0; i < n; i++)
        cin >> nutrition[i];

    cout << "Enter maximum capacity: ";
    cin >> capacity;

    food.knapsack(weight, nutrition, n, capacity);

    delete[] weight;
    delete[] nutrition;

    return 0;
}