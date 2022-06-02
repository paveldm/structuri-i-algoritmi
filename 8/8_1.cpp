#include <iostream>
#include <chrono>
using namespace std;

void selection_sort(int x[], int n) {
    int i, j, min, temp, sravn = 0, replace = 0;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (x[j] < x[min])
                min = j;
                sravn++;
        }
        temp = x[i];
        x[i] = x[min];
        x[min] = temp;
        replace++;
    }
    cout << "Тэп=Cф+Mф=" << replace + sravn << "\n";
}

void input_x(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
}

void input_rand(int x[], int n) {
    for (int i = 0; i < n; i++) {
        x[i] = rand() % 1000 + 1;
    }
}

void output_x(int x[], int n) {
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* x = new int[n];
    //cout << "Введите " << n << " чисел: ";
    //input_x(x, n);
    input_rand(x, n);

    auto start = chrono::high_resolution_clock::now();
    //cout << "Исходный массив: ";
    //output_x(x, n);
    selection_sort(x, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "\nОтсортированный массив: ";
    output_x(x, n);
    chrono::duration<float> duration = end - start;
    cout << "\n" << "Время потраченное на сортировку: " << duration.count() << " сек.";
}