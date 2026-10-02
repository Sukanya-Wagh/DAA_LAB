#include <iostream>
using namespace std;

class Investment
{
public:
    void knapsack(int cost[], int profit[], int n, int budget)
    {
        float ratio[100];

        for (int i = 0; i < n; i++)
            ratio[i] = (float)profit[i] / cost[i];

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ratio[i] < ratio[j])
                {
                    swap(ratio[i], ratio[j]);
                    swap(cost[i], cost[j]);
                    swap(profit[i], profit[j]);
                }
            }
        }

        float totalProfit = 0;
        int remaining = budget;

        for (int i = 0; i < n; i++)
        {
            if (cost[i] <= remaining)
            {
                remaining -= cost[i];
                totalProfit += profit[i];
            }
            else
            {
                totalProfit += ratio[i] * remaining;
                break;
            }
        }

        cout << "Maximum profit = " << totalProfit << endl;
    }
};

int main()
{
    Investment investment;

    int n, budget;

    cout << "Enter number of investments: ";
    cin >> n;

    int *cost = new int[n];
    int *profit = new int[n];

    cout << "Enter investment costs:" << endl;

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << "Enter expected profits:" << endl;

    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter available budget: ";
    cin >> budget;

    investment.knapsack(cost, profit, n, budget);

    delete[] cost;
    delete[] profit;

    return 0;
}