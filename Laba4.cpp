#include <iostream>

// Оголошення класу DynamicArray
class DynamicArray {
private:
    int* arr; // вказівник на динамічний масив
    int size; // розмір масиву
public:
    // Конструктор класу DynamicArray
    // Приймає розмір масиву n
    DynamicArray(int n) {
        size = n; // Зберігає розмір масиву
        arr = new int[n]; // Виділяє пам'ять під масив
    }

    // Деструктор класу DynamicArray
    // Звільняє пам'ять, виділену під масив
    ~DynamicArray() {
        delete[] arr;
    }

    // Метод для отримання розміру масиву
    int getSize() const {
        return size;
    }

    // Метод для отримання елемента масиву за індексом
    int getElem(int index) const {
        return arr[index];
    }

    // Метод для зміни елемента масиву за індексом
    void setElem(int index, int value) {
        arr[index] = value;
    }
};

// Функція для знаходження суми додатніх елементів масиву
// Приймає створений об'єкт класу DynamicArray за посиланням
int sumPositive(const DynamicArray& arr) {
    int sum = 0; // Ініціалізуємо змінну sum нулем
    for (int i = 0; i < arr.getSize(); i++) { // Ітеруємося по всіх елементах масиву
        if (arr.getElem(i) > 0) { // Якщо елемент більше нуля
            sum += arr.getElem(i); // Додаємо його до змінної sum
        }
    }
    return sum; // Повертаємо суму додатніх елементів
}

// Основна функція програми
int main() {
    const int size = 14; // Задаємо розмір масиву
    DynamicArray arr(size); // Створюємо об'єкт класу DynamicArray з розміром size
    for (int i = 0; i < size; i++) {
        arr.setElem(i, i - 1); // Ініціалізуємо масив за варіантом
    }

    // Виводимо масив на екран
std::cout << "Array: ";
for (int i = 0; i < size; i++) {
std::cout << arr.getElem(i) << " ";
}
std::cout << std::endl;
// Знаходимо суму додатніх елементів
int sum = sumPositive(arr);

// Виводимо суму додатніх елементів на екран
std::cout << "Sum of positive elements: " << sum << std::endl;

return 0; // Повертаємо 0, щоб позначити успішне завершення програми
}