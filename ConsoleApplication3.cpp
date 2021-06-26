#include <iostream>


using namespace std;

void func(int* arr, int size, int* summ, int* mult)
{
    for (int i = 0; i < size; i++)
    {
        *summ += *(arr + i);
    }
    cout << "Sum: " << *summ << endl;
    for (int j = 0; j < size; j++)
    {
        *mult *= (*arr + j);
    }
    cout << "Mult: " << *mult << endl;
}

int main()
{
    srand(time(0));
    const int size = 5;
    int arr[size];
    int summ = 0, multi = 1;
    int* psumm = &summ;
    int* pmulti = &multi;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    int* pa = &arr[0];
    func(pa, size, psumm, pmulti);

    return 0;
}



#include<iostream>
using namespace std;
int* proverca(int* A, int* B, int size1, int size2) {
    int* ptr;
    int i = 0;
    for (i = 0; i < size1; i++) {
        int j = i, k = 0;
        while (j < size1 && k < size2 && B[k] == A[j]) {
            j++;
            k++;
        }if (k == size2)
            return ptr = A + i;
        else
            return 0;
    }
}int main() {
    setlocale(LC_ALL, "rus");
    int size1, size2;
    cout << "Введите размер массива A: ";
    cin >> size1;
    int* A = new int[size1 + 1];
    cout << "Заполните массив: ";
    for (int i = 0; i < size1; i++)
        cin >> A[i];
    cout << "Введите размер массива B: ";
    cin >> size2;
    int* B = new int[size2];
    cout << "Заполните массив: ";
    for (int i = 0; i < size2; i++)
        cin >> B[i];
    cout << "Элемент должен стоять на позиции " << proverca(A, B, size1, size2) << endl;
    delete[]A;
    delete[]B;
    return 0;
}





#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

int* remove_negatives(const int* array, size_t& count) {
    size_t pos_count = std::count_if(array, array + count, std::bind2nd(std::greater<int>(), -1));
    if (!pos_count) {
        return NULL;
    }
    else {
        int* tmp = new int[pos_count];
        std::remove_copy_if(array, array + count, tmp, std::bind2nd(std::less<int>(), 0));
        count = pos_count;
        return tmp;
    }
}

int main() {
    int array[] = { 1, -2, -3, 4, 5, -6 };
    size_t count = sizeof(array) / sizeof(*array);
    int* no_negative = remove_negatives(array, count);

    if (!no_negative)
        std::cout << "Only negative values, nothing to return!";
    else
        std::copy(no_negative, no_negative + count, std::ostream_iterator<int>(std::cout, " "));

    delete[] no_negative;
    std::cout << std::endl;

    return 0;
}







#include <iostream>
using namespace std;

int* add_element(int* source, int size) {
    int* dest = new int[size + 1], i;
    for (i = 0, dest[size] = 0; i < size; i++)
        dest[size] += (dest[i] = source[i]);
    delete[] source;
    return dest;
}

int main()
{
    const int size = 5;
    int* initial = new int[size], i;
    for (i = 0; i < size; i++)
        initial[i] = i;
    int* result = add_element(initial, size);
    for (i = 0; i <= size; i++)
        cout << result[i] << endl;
    return 0;
}
