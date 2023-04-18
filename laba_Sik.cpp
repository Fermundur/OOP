// підключаємо потрібні бібліотеки
#include <iostream> // input output stream
#include <conio.h> // console input output

using namespace std;    // використовуємо простір стандартної бібліотеки
                        // щоб не писати перед кожною командою "std::"

class Vector{
    // приватні елементи класу
    private:
    float x;
    float y;
    float z;

    // перевірка знаку координати Z
    void CheckSign(){
        // якщо Х*Y<0 і Z>0, то змінюємо знак Z
        if (this->x * this->y < 0 && this->z > 0){
            z *= -1;
        }
        // якщо Х*Y>0 і Z<0, то змінюємо знак Z
        else if (this->x * this->y > 0 && this->z < 0){
            z *= -1;
        }
    }

    // публічні елементи класу
    public:

    // конструктор без параметрів, всі координати дорівнюють нулю
    Vector(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    // конструктор із параметрами
    Vector(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
        // перевірка знаку
        this->CheckSign();
    }

    // сеттер(призначає нове значення) для координати Х
    void setX(float x){
        this->x = x;
    }

    // геттер(дає значення властивості) координати Х
    float getX(){
        return this->x;
    }

    void setY(float y){
        this->y = y;
    }

    float getY(){
        return this->y;
    }

    void setZ(float z){
        this->z = z;
        // перевірка знаку
        this->CheckSign();
    }

    float getZ(){
        return this->z;
    }

    // виводить результат у формі "<0.0 0.0 0.0>"
    void print(){
        cout << "<" << this->x << " " << this->y << " " << this->z << ">" << endl;
    }
};

int main(){
    Vector vector0;           // створено об'єкт(екземпляр) без параметрів
    Vector vector3(3, 3, -3);   // створено об'єкт(екземпляр) з параметрами

    vector0.print();    // 000
    vector3.print();    // 333

    vector0.setX(-1);   //x=-1
    vector0.setY(12.7); //y=12.7
    vector0.setZ(-9.4); //z=-9.4

    vector0.print();

    cout << "X: " << vector3.getX() << "\nY: " << vector3.getY() << "\nZ: " << vector3.getZ() << endl; 

    return 0;
}