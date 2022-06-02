#include <iostream>
#include <chrono>
using namespace std;
// ������� "�����������" ����� ���� - ������������ ����
void siftDown(int* numbers, int root, int bottom)
{
    int maxChild; // ������ ������������� �������
    int done = 0; // ���� ����, ��� ���� ������������
    // ���� �� ����� �� ���������� ����
    while ((root * 2 <= bottom) and (!done))
    {
        if (root * 2 == bottom)    // ���� �� � ��������� ����,
            maxChild = root * 2;    // ���������� ����� �������
          // ����� ���������� ������� ������� �� ����
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // ���� ������� ������� ������ ������������� �������
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // ������ �� �������
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1; // �������� ������������
    }
}
// ������� ���������� �� ����
void heapSort(int* numbers, int array_size)
{
    // ��������� ������ ��� ��������
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // ���������� ����� �������� ��������� ��������
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
    cout << "������� ������ �������: ";
    cin >> n;
    int* a = new int[n];
    //cout << "������� " << n << " �����: ";
    //input_x(a, n);
    input_rand(a, n);

    auto start = chrono::high_resolution_clock::now();
    //cout << "�������� ������: ";
    //output_x(x, n);
    heapSort(a, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "\n��������������� ������: ";
    //output_x(a, n);
    chrono::duration<float> duration = end - start;
    cout << "\n" << "����� ����������� �� ����������: " << duration.count() << " ���.";
    return 0;
}