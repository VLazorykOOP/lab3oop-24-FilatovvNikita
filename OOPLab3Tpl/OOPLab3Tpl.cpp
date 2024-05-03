
/*
#include <iostream>
#include <string>
using namespace std;

class Rectangle {
private:
    double height;
    double width;
    string color;

public:
    //конструктор
    Rectangle() {
        height = 0.0;
        width = 0.0;
        color = "білий";
    }

    Rectangle(double h, double w, string c) {
        if (h > 0 && w > 0) {
            height = h;
            width = w;
            color = c;
        }
        else {
            cerr << "Помилка: Недійсні розміри для прямокутника." << endl;
            height = 0.0;
            width = 0.0;
            color = "білий";
        }
    }

    //обчислення площі та периметру
    double calculateArea() {
        return height * width;
    }

    double calculatePerimeter() {
        return 2 * (height + width);
    }

    // встановлюють значення різних полів класу
    void setHeight(double h) {
        if (h > 0)
            height = h;
        else
            cerr << "Помилка: Не правильна висота." << endl;
    }

    void setWidth(double w) {
        if (w > 0)
            width = w;
        else
            cerr << "Помилка: Не правильна ширина." << endl;
    }

    void setColor(string c) {
        color = c;
    }

    // повертають значення різних полів класу
    double getHeight() {
        return height;
    }

    double getWidth() {
        return width;
    }

    string getColor() {
        return color;
    }

    //фція виводу
    void print() {
        cout << "Прямокутник: висота = " << height << ",Ширина = " << width << ",Колір = " << color << endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    Rectangle rect1; //конструктор
    rect1.print();

    Rectangle rect2(5.0, 3.0, "синій"); //конструктор з параметром
    rect2.print();

    cout << "Площа rect2: " << rect2.calculateArea() << endl;
    cout << "Периметр rect2: " << rect2.calculatePerimeter() << endl;

    rect2.setHeight(6.0);
    rect2.setWidth(4.0);
    rect2.setColor("червоний");
    rect2.print();

    return 0;
}
*/
//
//2 Завдання
//

#include <iostream>
using namespace std;
class Vector {
private:
    double* array; // Вказівник на масив
    int size; // Кількість елементів у векторі
    int state; // Змінна стану (код помилки)
public:
    // Конструктори
    Vector() { // Конструктор без параметрів
        size = 1;
        array = new double[size];
        array[0] = 0.0;
        state = 0;
    }
    Vector(int s) { // Конструктор з одним параметром
        size = s;
        array = new double[size];
        for (int i = 0; i < size; i++)
            array[i] = 0.0;
        state = 0;
    }
    Vector(int s, double value) { // Конструктор з двома параметрами
        size = s;
        array = new double[size];
        for (int i = 0; i < size; i++)
            array[i] = value;
        state = 0;
    }
    // Конструктор копії та операція присвоєння
    Vector(const Vector& other) { // Конструктор копії
        size = other.size;
        array = new double[size];
        for (int i = 0; i < size; i++)
            array[i] = other.array[i];
        state = other.state;
    }
    Vector& operator=(const Vector& other) { // Операція присвоєння
        if (this != &other) {
            delete[] array;
            size = other.size;
            array = new double[size];
            for (int i = 0; i < size; i++)
                array[i] = other.array[i];
            state = other.state;
        }
        return *this;
    }
    // Деструктор
    ~Vector() {
        delete[] array;
    }
    // Функція для встановлення значення для елементу масиву (за замовчуванням)
    void setElement(int index, double value = 0.0) {
        if (index >= 0 && index < size) {
            array[index] = value;
            state = 0;
        }
        else {
            state = 1; // Код помилки: виходить за межі масиву
        }
    }
    // Функція для отримання значення елементу масиву
    double getElement(int index) {
        if (index >= 0 && index < size) {
            state = 0;
            return array[index];
        }
        else {
                state = 1; // Код помилки: виходить за межі масиву
            return 0.0;
        }
    }
    // Функція друку
    void print() {
        cout << "Vector: ";
        for (int i = 0; i < size; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    // Функції арифметичних операцій
    Vector operator+(const Vector& other) { // Додавання
        if (size == other.size) {
            Vector result(size);
            for (int i = 0; i < size; i++)
                result.array[i] = array[i] + other.array[i];
            return result;
        }
        else {
            state = 2; // Код помилки: розміри векторів не співпадають
            return *this;
        }
    }
    Vector operator-(const Vector& other) { // Віднімання
        if (size == other.size) {
            Vector result(size);
            for (int i = 0; i < size; i++)
                result.array[i] = array[i] - other.array[i];
            return result;
        }
        else {
            state = 2; // Код помилки: розміри векторів не співпадають
            return *this;
        }
    }
    Vector operator*(double scalar) { // Множення на скаляр
        Vector result(size);
        for (int i = 0; i < size; i++)
            result.array[i] = array[i] * scalar;
        return result;
    }
    Vector operator/(double scalar) { // Ділення на скаляр
        if (scalar != 0) {
            Vector result(size);
            for (int i = 0; i < size; i++)
                result.array[i] = array[i] / scalar;
            return result;
        }
        else {
            state = 3; // Код помилки: ділення на нуль
            return *this;
        }
    }
    // Функції порівняння
    bool operator==(const Vector& other) { // Рівність
        if (size == other.size) {
            for (int i = 0; i < size; i++) {
                if (array[i] != other.array[i])
                    return false;
            }
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<(const Vector& other) { // Менше
        if (size == other.size) {
            for (int i = 0; i < size; i++) {
                if (array[i] >= other.array[i])
                    return false;
            }
            return true;
        }
        else {
            return false;
        }
    }
    bool operator>(const Vector& other) { // Більше
        if (size == other.size) {
            for (int i = 0; i < size; i++) {
                if (array[i] <= other.array[i])
                    return false;
            }
            return true;
        }
        else {
            return false;
        }
    }
    // Функція для отримання коду стану
    int getState() {
        return state;
    }
    // Функція для підрахунку числа об'єктів даного типу
    static int getCount() {
        // Реалізація може варіюватися залежно від вимог
        return 0;
    }
};

int main() {
    // Тестування всіх можливостей класу Vector
    setlocale(LC_CTYPE, "ukr");
    cout << "Конструктор без параметрів:" << endl;
    Vector vec1;
    vec1.print();
    cout << "Конструктор з одним параметром:" << endl;
    Vector vec2(5);
    vec2.print();
    cout << "Конструктор з двома параметрами:" << endl;
    Vector vec3(3, 2.5);
    vec3.print();
    cout << "Конструктор копії:" << endl;
    Vector vec4 = vec3;
    vec4.print();
    cout << "Операція присвоєння:" << endl;
    Vector vec5;
    vec5 = vec4;
    vec5.print();
    cout << "Приклади арифметичних операцій:" << endl;
    cout << "+:" << endl;
    Vector vec6 = vec3 + vec4;
    vec6.print();
    cout << "-:" << endl;
    Vector vec7 = vec4 - vec3;
    vec7.print();
    cout << "*:" << endl;
    Vector vec8 = vec4 * 2.0;
    vec8.print();
    cout << "/:" << endl;
    Vector vec9 = vec4 / 2.0;
    vec9.print();
    return 0;
}
