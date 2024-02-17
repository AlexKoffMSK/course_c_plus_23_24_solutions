#include <iostream>
#include <string>
/*
Класс Car
Определите класс Car с приватными атрибутами 
для года выпуска (year), цвета (color), 
количества дверей (count_doors), уровня топлива 
(fuel_level) и пробега (mileage).
Реализуйте конструктор для инициализации этих
атрибутов. Уровень топлива и пробег должны иметь 
значения по умолчанию 50.0 и 0.0 соответственно.

Реализуйте метод drive(double distance), 
который уменьшает уровень топлива в зависимости от 
пройденного расстояния и увеличивает пробег.
 Предположите, что автомобиль расходует 1 литр 
 топлива на 10 км.
Реализуйте метод refuel(double amount), чтобы
 добавлять топливо в бак.
Добавьте метод stop(), который выводит сообщение 
о том, что автомобиль остановлен.
Реализуйте метод info(), который выводит информацию 
об автомобиле: год выпуска, цвет, количество дверей, 
уровень топлива и пробег.

Реализуйте методы для изменения цвета 
автомобиля и получения текущих значений цвета, 
уровня топлива и пробега.

В функции main, создайте несколько объектов класса Car с разными характеристиками.
Протестируйте все методы класса, чтобы убедиться, что они работают корректно. Попробуйте пройти некоторое расстояние, заправить автомобиль, изменить его цвет и затем вывести информацию о нем.
*/
class Car {
 private:
  int year;
  std::string color;
  int count_doors;
  double fuel_level;
  double mileage;

 public:
  Car(int yr, std::string clr, int doors, double fuel = 50.0, double miles = 0.0) : year(yr), color(clr), count_doors(doors), fuel_level(fuel), mileage(miles) {}

  void drive(double distance) {
    double fuel_needed = distance / 10.0;
    if (fuel_level >= fuel_needed) {
      fuel_level -= fuel_needed;
      mileage += distance;
      std::cout << "Driving " << distance << " km. Fuel left: " << fuel_level << " L\n";
    } else {
      std::cout << "Not enough fuel to drive " << distance << " km\n";
    }
  }

  void refuel(double amount) {
    fuel_level += amount;
    std::cout << "Refueled " << amount << " L. Total fuel: " << fuel_level << " L\n";
  }

  void stop() {
    std::cout << "Car stopped\n";
  }

  void info() const {
    std::cout << "Year: " << year << ", Color: " << color << ", Doors: " << count_doors
              << ", Fuel: " << fuel_level << " L, Mileage: " << mileage << " km\n";
  }

  void setColor(std::string newColor) {
    color = newColor;
  }

  std::string getColor() const {
    return color;
  }

  double getFuelLevel() const {
    return fuel_level;
  }

  double getMileage() const {
    return mileage;
  }
};

int main() {
  Car car1(2000, "white", 5);
  car1.info();
  car1.drive(20);
  car1.refuel(10);
  car1.drive(50);
  car1.stop();
  car1.info();

  Car car2(2010, "black", 3, 60, 15000);
  car2.info();
  car2.drive(100);
  car2.setColor("red");
  car2.info();

  return 0;
}
