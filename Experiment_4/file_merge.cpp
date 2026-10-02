#include <iostream>
using namespace std;

class FileMerge
{
public:
    int calculateCost(int arr[], int n)
    {
        int totalCost = 0;

        while (n > 1)
        {
            int first = 0;
            int second = 1;

            if (arr[first] > arr[second])
                swap(arr[first], arr[second]);

            for (int i = 2; i < n; i++)
            {
                if (arr[i] < arr[first])
                {
                    second = first;
                    first = i;
                }
                else if (arr[i] < arr[second])
                {
                    second = i;
                }
            }

            int mergeCost = arr[first] + arr[second];
            totalCost += mergeCost;

            arr[first] = mergeCost;
            arr[second] = arr[n - 1];
            n--;
        }

        return totalCost;
    }
};

int main()
{
    FileMerge file;

    int n;

    cout << "Enter number of files: ";
    cin >> n;

    int *size = new int[n];

    cout << "Enter file sizes:" << endl;

    for (int i = 0; i < n; i++)
        cin >> size[i];

    int totalCost = file.calculateCost(size, n);

    cout << "Minimum total merge cost = " << totalCost << endl;

    delete[] size;

    return 0;
}