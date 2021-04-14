#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual float Perimeter() const = 0;
    virtual float Area() const = 0;
};
class Triangle : public Figure {
public:
    Triangle(float first, float second, float third) : first_(first), second_(second), third_(third) {}
    string Name() const override {return name;}
    float Perimeter() const override { return first_ + second_ + third_;}
    float Area() const override {
        float p = Perimeter() / 2;
        return sqrt(p * (p - first_)*(p - second_)*(p - third_));
        }
private:
    const string name = "TRIANGLE";
    const float first_;
    const float second_;
    const float third_;
};
class Rect : public Figure {
public:
    Rect(float width, float height) : width_(width), height_(height) {}
    string Name() const override {return name;}
    float Perimeter() const override { return 2 * (width_ + height_);}
    float Area() const override {return width_ * height_;}
private:
    const string name = "RECT";
    const float width_;
    const float height_;
};
class Circle : public Figure {
public:
    Circle(float radius) : radius_(radius) {}
    string Name() const override {return name;}
    float Perimeter() const override { return 2 * 3.14 * radius_;}
    float Area() const override {return 3.14 * radius_ * radius_;}
private:
    const string name = "CIRCLE";
    const float radius_;
};


shared_ptr<Figure> CreateFigure(istringstream& is) {
    string name;
    is >> name;
    if (name == "TRIANGLE") {
        float first;
        float second;
        float third;
        is >> first;
        is >> second;
        is >> third;
        Triangle t(first, second, third);
        return make_shared<Triangle>(t);
    }
    else if (name == "RECT") {
        float width;
        float height;
        is >> width;
        is >> height;
        Rect r(width, height);
        return make_shared<Rect>(r);
    }
    else if (name == "CIRCLE") {
        float radius;
        is >> radius;
        Circle c(radius);
        return make_shared<Circle>(c);
    }
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}