#include <iostream>
#include <chrono>
using namespace std;
// Функция "просеивания" через кучу - формирование кучи
void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) and (!done))
    {
        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
          // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1; // пирамида сформирована
    }
}
// Функция сортировки на куче
void heapSort(int* numbers, int array_size)
{
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
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
    int* a = new int[n];
    //cout << "Введите " << n << " чисел: ";
    //input_x(a, n);
    input_rand(a, n);

    auto start = chrono::high_resolution_clock::now();
    //cout << "Исходный массив: ";
    //output_x(x, n);
    heapSort(a, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "\nОтсортированный массив: ";
    //output_x(a, n);
    chrono::duration<float> duration = end - start;
    cout << "\n" << "Время потраченное на сортировку: " << duration.count() << " сек.";
    return 0;
}