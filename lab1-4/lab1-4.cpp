#include <iostream>
#include <cmath>

using namespace std;

// Функция для поиска первого вхождения числа x в массив
int findFirst(int arr[], int size, int x) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            return i; // Возвращаем индекс первого вхождения
        }
    }
    return -1; // Если число не найдено, возвращаем -1
}

// Функция для поиска наибольшего по модулю значения в массиве
int maxAbs(int arr[], int size) {
    if (size == 0) {
        cout << "Массив пустой. Невозможно найти максимальное значение." << endl;
        return 0; // Защита от пустого массива
    }

    int maxValue = abs(arr[0]); // Начальное значение - модуль первого элемента
    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) > maxValue) {
            maxValue = abs(arr[i]); // Находим максимальное по модулю значение
        }
    }
    return maxValue;
}

// Функция для добавления массива ins в массив arr на позицию pos
int* add(int arr[], int sizeArr, int ins[], int sizeIns, int pos) {
    if (pos < 0 || pos > sizeArr) {
        cout << "Некорректная позиция для вставки!" << endl;
        return nullptr;
    }

    int newSize = sizeArr + sizeIns;
    int* newArr = new int[newSize];

    // Копируем элементы до позиции вставки
    for (int i = 0; i < pos; ++i) {
        newArr[i] = arr[i];
    }

    // Вставляем элементы массива ins
    for (int i = 0; i < sizeIns; ++i) {
        newArr[pos + i] = ins[i];
    }

    // Копируем оставшиеся элементы массива arr
    for (int i = pos; i < sizeArr; ++i) {
        newArr[i + sizeIns] = arr[i];
    }

    return newArr;
}

// Функция для реверса массива
int* reverseBack(int arr[], int size) {
    if (size <= 0) {
        cout << "Массив пуст или имеет некорректный размер!" << endl;
        return nullptr;
    }

    int* reversedArr = new int[size];
    for (int i = 0; i < size; ++i) {
        reversedArr[i] = arr[size - 1 - i]; // Копируем элементы в обратном порядке
    }

    return reversedArr;
}

// Функция для поиска всех вхождений числа x в массив arr
int* findAll(int arr[], int size, int x, int& foundCount) {
    foundCount = 0;

    // Считаем количество вхождений
    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            foundCount++;
        }
    }

    if (foundCount == 0) {
        return nullptr; // Если нет вхождений, возвращаем nullptr
    }

    // Создаем массив для индексов
    int* indices = new int[foundCount];
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            indices[index++] = i;
        }
    }

    return indices;
}

// Функция для безопасного ввода целого числа
int safeInput() {
    int value;
    while (true) {
        cin >> value;
        if (!cin.fail()) { // Если ввод прошел успешно
            break;
        }
        else {
            cout << "Некорректный ввод, пожалуйста, введите целое число: ";
            cin.clear(); // Очищаем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        }
    }
    return value;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");

    int choice;
    do {
        cout << "Выберите задание: " << endl;
        cout << "1) Поиск первого вхождения числа в массив." << endl;
        cout << "2) Поиск наибольшего по модулю значения в массиве." << endl;
        cout << "3) Вставка одного массива в другой." << endl;
        cout << "4) Реверс массива." << endl;
        cout << "5) Поиск всех вхождений числа в массив." << endl;
        cout << "0) Выйти из программы." << endl;
        cout << "Ваш выбор: ";
        choice = safeInput();

        if (choice == 1) {
            // Задание 1 - Поиск первого вхождения числа в массив
            int size;
            cout << "Введите размер массива: ";
            size = safeInput();

            if (size <= 0) {
                cout << "Размер массива должен быть положительным!" << endl;
                continue;
            }

            int* arr = new int[size];
            cout << "Введите элементы массива:" << endl;
            for (int i = 0; i < size; ++i) {
                cout << "Элемент " << i + 1 << ": ";
                arr[i] = safeInput();
            }

            int x;
            cout << "Введите число для поиска его первого вхождения в массив: ";
            x = safeInput();

            int index = findFirst(arr, size, x);
            if (index != -1) {
                cout << "Первое вхождение числа " << x << " находится на индексе: " << index << endl;
            }
            else {
                cout << "Число " << x << " не найдено в массиве." << endl;
            }

            delete[] arr; // Освобождаем память

        }
        else if (choice == 2) {
            // Задание 2 - Поиск наибольшего по модулю значения в массиве
            int size;
            cout << "Введите размер массива: ";
            size = safeInput();

            if (size <= 0) {
                cout << "Размер массива должен быть положительным!" << endl;
                continue;
            }

            int* arr = new int[size];
            cout << "Введите элементы массива:" << endl;
            for (int i = 0; i < size; ++i) {
                cout << "Элемент " << i + 1 << ": ";
                arr[i] = safeInput();
            }

            int maxAbsValue = maxAbs(arr, size);
            cout << "Наибольшее по модулю значение в массиве: " << maxAbsValue << endl;

            delete[] arr; // Освобождаем память

        }
        else if (choice == 3) {
            // Задание 3 - Вставка одного массива в другой
            int sizeArr, sizeIns, pos;

            // Ввод первого массива
            cout << "Введите размер первого массива: ";
            sizeArr = safeInput();

            if (sizeArr <= 0) {
                cout << "Размер массива должен быть положительным!" << endl;
                continue;
            }

            int* arr = new int[sizeArr];
            cout << "Введите элементы первого массива:" << endl;
            for (int i = 0; i < sizeArr; ++i) {
                cout << "Элемент " << i + 1 << ": ";
                arr[i] = safeInput();
            }

            // Ввод второго массива
            cout << "Введите размер второго массива (для вставки): ";
            sizeIns = safeInput();

            if (sizeIns <= 0) {
                cout << "Размер массива должен быть положительным!" << endl;
                delete[] arr;
                continue;
            }

            int* ins = new int[sizeIns];
            cout << "Введите элементы второго массива:" << endl;
            for (int i = 0; i < sizeIns; ++i) {
                cout << "Элемент " << i + 1 << ": ";
                ins[i] = safeInput();
            }

            // Ввод позиции для вставки
            cout << "Введите позицию для вставки второго массива: ";
            pos = safeInput();

            // Выполняем вставку
            int* newArr = add(arr, sizeArr, ins, sizeIns, pos);
            if (newArr != nullptr) {
                cout << "Результирующий массив: ";
                for (int i = 0; i < sizeArr + sizeIns; ++i) {
                    cout << newArr[i] << " ";
                }
                cout << endl;
                delete[] newArr; // Освобождаем память нового массива
            }

            delete[] arr; // Освобождаем память первого массива
            delete[] ins; // Освобождаем память второго массива

        }
        else if (choice == 4) {
            // Задание 4 - Реверс массива
            int size;
            cout << "Введите размер массива: ";
            size = safeInput();

            if (size <= 0) {
                cout << "Размер массива должен быть положительным!" << endl;
                continue;
            }

            int* arr = new int[size];
            cout << "Введите элементы массива:" << endl;
            for (int i = 0; i < size; ++i) {
                cout << "Элемент " << i + 1 << ": ";
                arr[i] = safeInput();
            }

            int* reversedArr = reverseBack(arr, size);
            if (reversedArr != nullptr) {
                cout << "Массив в обратном порядке: ";
                for (int i = 0; i < size; ++i) {
                    cout << reversedArr[i] << " ";
                }
                cout << endl;
                delete[] reversedArr; // Освобождаем память реверсированного массива
            }

            delete[] arr; // Освобождаем память оригинального массива

        }
        else if (choice == 5) {
            // Задание 5 - Поиск всех вхождений числа в массив
            int size;
            cout << "Введите размер массива: ";
            size = safeInput();

            if (size <= 0) {
                cout << "Размер массива должен быть положительным!" << endl;
                continue;
            }

            int* arr = new int[size];
            cout << "Введите элементы массива:" << endl;
            for (int i = 0; i < size; ++i) {
                cout << "Элемент " << i + 1 << ": ";
                arr[i] = safeInput();
            }

            int x;
            cout << "Введите число для поиска всех его вхождений в массиве: ";
            x = safeInput();

            int foundCount;
            int* indices = findAll(arr, size, x, foundCount);
            if (indices != nullptr) {
                cout << "Число " << x << " встречается на следующих индексах: ";
                for (int i = 0; i < foundCount; ++i) {
                    cout << indices[i] << " ";
                }
                cout << endl;
                delete[] indices; // Освобождаем память массива индексов
            }
            else {
                cout << "Число " << x << " не найдено в массиве." << endl;
            }

            delete[] arr; // Освобождаем память массива
        }
        else if (choice != 0) {
            cout << "Некорректный выбор, попробуйте снова." << endl;
        }

    } while (choice != 0);

    cout << "Программа завершена." << endl;
    return 0;
}
