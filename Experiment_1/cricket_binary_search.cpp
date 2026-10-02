#include <iostream>
using namespace std;

class Cricket
{
public:
    int binarySearch(int arr[], int low, int high, int key)
    {
        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);

        return binarySearch(arr, mid + 1, high, key);
    }
};

int main()
{
    Cricket cricket;
    int n, key;

    cout << "Enter number of players: ";
    cin >> n;

    int *scores = new int[n];

    cout << "Enter player scores in sorted order:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    cout << "Enter score to search: ";
    cin >> key;

    int result = cricket.binarySearch(scores, 0, n - 1, key);

    if (result != -1)
        cout << "Score " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "Score " << key << " not found." << endl;

    delete[] scores;

    return 0;
}