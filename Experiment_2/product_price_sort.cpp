#include <iostream>
using namespace std;

class Product
{
public:
    void merge(int arr[], int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        int k = 0;

        int temp[100];

        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= high)
            temp[k++] = arr[j++];

        for (i = low, k = 0; i <= high; i++, k++)
            arr[i] = temp[k];
    }

    void mergeSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;

            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);

            merge(arr, low, mid, high);
        }
    }

    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        return i + 1;
    }

    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    void display(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    Product product;
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    int *price = new int[n];

    cout << "Enter product prices:" << endl;

    for (int i = 0; i < n; i++)
        cin >> price[i];

    int *quickArray = new int[n];
    int *mergeArray = new int[n];

    for (int i = 0; i < n; i++)
    {
        quickArray[i] = price[i];
        mergeArray[i] = price[i];
    }

    product.quickSort(quickArray, 0, n - 1);
    product.mergeSort(mergeArray, 0, n - 1);

    cout << "\nSorted Product Prices using Quick Sort: ";
    product.display(quickArray, n);

    cout << "Sorted Product Prices using Merge Sort: ";
    product.display(mergeArray, n);

    delete[] price;
    delete[] quickArray;
    delete[] mergeArray;

    return 0;
}