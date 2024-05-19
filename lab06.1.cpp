#include <iostream>
#include <vector>
class Point {
protected:
 double x, y;
public:
 Point(double x, double y) : x(x), y(y) {}
 virtual void draw() = 0;
 double getX() const { return x; }
 double getY() const { return y; }
};
class Shape : public Point {
public:
 Shape(double x, double y) : Point(x, y) {}
};
class Line : public Shape {
public:
 Line(double x1, double y1, double x2, double y2) : Shape((x1 + x2) / 2, (y1 + y2)
/ 2), x1(x1), y1(y1), x2(x2), y2(y2) {}
 void draw() override {
 std::cout << "Drawing line: " << x1 << "," << y1 << " -> " << x2 << "," << y2
<< "\n";
 }
private:
 double x1, y1, x2, y2;
};
class BrokenLine : public Shape {
public:
 BrokenLine(const std::vector<Point>& points) : Shape(points[0].getX(),
points[0].getY()), points(points) {}
 void draw() override {
 for (size_t i = 1; i < points.size(); ++i) {
 Line(points[i - 1].getX(), points[i - 1].getY(), points[i].getX(),
points[i].getY()).draw();
 }
 }
private:
 std::vector<Point> points;
};
class ConcretePoint : public Point {
public:
 ConcretePoint(double x, double y) : Point(x, y) {}
 void draw() override {
 std::cout << "Drawing point at: " << x << "," << y << "\n";
 }
};
int main() {
 int choice;
 do {
 std::cout << "\nMenu:\n";
 std::cout << "1. Create point\n";
 std::cout << "2. Create line\n";
 std::cout << "3. Create broken line\n";
 std::cout << "8. Exit\n";
 std::cout << "Enter your choice: ";
 std::cin >> choice;
 switch (choice) {
 case 1: {
 double x, y;
 std::cin >> x >> y;
 ConcretePoint point(x, y); // Create concrete point object
 point.draw(); // Draw point
 break;
 }
 case 2: {
 double x1, y1, x2, y2;
 std::cin >> x1 >> y1 >> x2 >> y2;
 Line(x1, y1, x2, y2).draw(); // Create and draw line directly
 break;
 }
 case 3: {
 int n;
 std::cin >> n;
 std::vector<Point> points;
 for (int i = 0; i < n; ++i) {
 double x, y;
 std::cin >> x >> y;
 points.push_back(ConcretePoint(x, y));
 }
 BrokenLine(points).draw();
 break;
 }
 }
 } while (choice != 8);
 return 0;
}