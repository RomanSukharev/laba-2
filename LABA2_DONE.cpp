#include <cmath>
#include <iostream>
#include <string>
constexpr auto PI = 3.1415;
using namespace std;

class cilinder { // начало области действия класса
public:
    // статические поля и методы классы
    static int  count;
    static void countcilinder() { count++; }
    static int getCount() { return count; }
private: // закрытые поля радиус и высота
    double radius;
    double height;
public: // открытые члены класса 
    
    //конструктор по умолчанию 
    cilinder() { radius = 1; height = 1; countcilinder(); }
    //конструктор с параметрами
    cilinder(double Vradius, double Vheight)
    {
        setcilinder(Vradius, Vheight); countcilinder();
    }
    //конструктор копирования
    cilinder(cilinder& C) { radius = C.radius; height = C.height; countcilinder(); }
    // метод – 1устанавливает значение полей класса
    void setcilinder(double r, double h) { radius = r; height = h; };
    void setRadius(double Vradius = 1) { radius = abs(Vradius); }
    // метод - возвращает параметры цилиндра 
    double getRadius() { return radius; }
    double getHeight() { return height; }
    // метод - вычисляет площадь основания цилиндра
    double getArea() { return PI * radius * radius; }
    //метод - вычисляет объем цилиндра
    double getVolume() { return PI * radius * radius * height; }
    // метод – возвращает строку информации о цилиндре
    string info() { return "Радиус = " + to_string(radius) + "\nВысота = " + to_string(height); }
    //метод - масштабирует, преобразование подобия с коэффициентом k
    void zoomcilinder(double k) { radius = radius * k; }
    // перегрузка операций сравнения
    bool operator > (cilinder& C) { return radius > C.radius; }
    bool operator == (cilinder& C) { return radius == C.radius; }
    // деструктор - пустое тело функции, так как в составе класса нет динамических полей
    ~cilinder() {};
};

//статическое поле класса, объявленное как глобальная переменная программы
int cilinder::count = 0;

int main()
{
    setlocale(LC_ALL, "ru");
    // создаем объекты 
    cilinder H1(3, 7); //конструктор с параметрами
    cilinder H2; //конструктор по умолчанию 
    // выводим информацию о цилиндрах
    cout << H1.info() << endl; cout << H2.info() << endl;
    // создаем указатель на объект
    cout << "создаем копию 1-ого цилиндра:" << endl;
    cilinder* pH = new cilinder(H1); //конструктор копирования 
    cout << pH->info() << endl;
    //проверяем методы
    cout << "Площадь основания цилиндра: " << pH->getArea() << endl;
    cout << "Объем цилиндра: " << pH->getVolume() << endl;
     cout << H1.getRadius() << " ( " << H1.getRadius() << " , " << H1.getHeight() << " )" << endl;
     H2.setcilinder(4.5, 0); cout << H2.info() << endl;
  
    cout << "сравним радиусы цилиндров H1 и H2:" << endl;
    if (H1.operator>(H2))
        cout << H1.getRadius() << '>' << H2.getRadius() << endl;
    else cout << H1.getRadius() << '<' << H2.getRadius() << endl;
    if (H1.operator==(H2))
        cout << H1.getRadius() << "=" << H2.getRadius() << endl;
    else cout << H1.getRadius() << "!=" << H2.getRadius() << endl;
    // вызываем статический метод для проверки работы 
    cout << "Количество объектов типа cilinder =  " << cilinder::getCount() << endl;


    return 0;
}