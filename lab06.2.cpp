#include <iostream>
#include <vector>
#include <algorithm>
class Set {
private:
 std::vector<int> elements;
public:
 Set() {}
 Set(const Set& other) {
 elements = other.elements;
 }
 void addElement(int element) {
 elements.push_back(element);
 }
 Set operator+(const Set& other) {
 Set result = *this;
 for (int element : other.elements) {
 if (std::find(result.elements.begin(), result.elements.end(), element) ==
result.elements.end()) {
 result.elements.push_back(element);
 }
 }
 return result;
 }
 Set operator-(const Set& other) {
 Set result;
 for (int element : elements) {
 if (std::find(other.elements.begin(), other.elements.end(), element) ==
other.elements.end()) {
 result.elements.push_back(element);
 }
 }
 return result;
 }
 int& operator[](int index) {
 return elements[index];
 }
 Set& operator=(const Set& other) {
 if (this != &other) {
 elements = other.elements;
 }
 return *this;
 }
 bool operator==(const Set& other) const {
 return elements == other.elements;
 }
 bool operator!=(const Set& other) const {
 return elements != other.elements;
 }
};
int main() {
 Set set1;
 set1.addElement(1);
 set1.addElement(2);
 set1.addElement(3);
 Set set2;
 set2.addElement(3);
 set2.addElement(4);
 set2.addElement(5);
 Set set3 = set1 + set2;
 Set set4 = set1 - set2;
 std::cout << "Set 1 + Set 2: ";
 for (int i = 0; i < set3[0]; ++i) {
 std::cout << set3[i] << " ";
 }
 std::cout << "\n";
 std::cout << "Set 1 - Set 2: ";
 for (int i = 0; i < set4[0]; ++i) {
 std::cout << set4[i] << " ";
 }
 std::cout << "\n";
 return 0;
}