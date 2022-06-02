#include <iostream>
using namespace std;
const int N = 100;

void fill(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int find_max(int arr[], int n) {
    static int max;
    if (n == 1)
        max = arr[0];
    else {
        if (find_max(arr, n - 1) > arr[n - 1]) {
            max = max;
        }
        else {
            max = arr[n - 1];
        }
    }
    return max;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "¬ведите количество чисел в массиве: ";
    cin >> n;
    int arr[N];
    fill(arr, n);
    cout << find_max(arr, n);
}