#include <iostream>
using namespace std;

class Library
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
    Library lib;
    int n, key;

    cout << "Enter number of books: ";
    cin >> n;

    int bookID[n];

    cout << "Enter sorted Book IDs:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> bookID[i];
    }

    cout << "Enter Book ID to search: ";
    cin >> key;

    int result = lib.binarySearch(bookID, 0, n - 1, key);

    if (result != -1)
        cout << "Book ID " << key << " found at position " << result + 1 << "." << endl;
    else
        cout << "Book ID " << key << " not found." << endl;

    return 0;
}