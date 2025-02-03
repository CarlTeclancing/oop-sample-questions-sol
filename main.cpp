#include <iostream>
#include <string>
using namespace std;

// School Management System
class School {
protected:
    string name;
    string students[100];
    string teachers[50];
    int studentCount, teacherCount;

public:
    School(string n) : name(n), studentCount(0), teacherCount(0) {}

    void addStudent(string student) {
        if (studentCount < 100) {
            students[studentCount++] = student;
        }
    }

    void assignTeacher(string teacher) {
        if (teacherCount < 50) {
            teachers[teacherCount++] = teacher;
        }
    }

    void display() {
        cout << "School: " << name << "\nStudents: ";
        for (int i = 0; i < studentCount; i++) cout << students[i] << ", ";
        cout << "\nTeachers: ";
        for (int i = 0; i < teacherCount; i++) cout << teachers[i] << ", ";
        cout << endl;
    }
};

class HighSchool : public School {
    string specialization;
public:
    HighSchool(string n, string spec) : School(n), specialization(spec) {}

    void display() {
        School::display();
        cout << "Specialization: " << specialization << endl;
    }
};

// Employee Management System
class Employee {
protected:
    int id;
    string name, department;
    double salary;
public:
    Employee(int i, string n, string d, double s) : id(i), name(n), department(d), salary(s) {}
    void updateDepartment(string newDept) { department = newDept; }
    void updateSalary(double newSalary) { salary = newSalary; }
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Department: " << department << ", Salary: " << salary << endl;
    }
};

// Library Management System
class LibraryItem {
protected:
    int itemID, quantity;
    string title, author, category;
public:
    LibraryItem(int id, string t, string a, string c, int q) : itemID(id), title(t), author(a), category(c), quantity(q) {}
    void updateQuantity(int q) { quantity = q; }
    void display() {
        cout << "ID: " << itemID << ", Title: " << title << ", Author: " << author << ", Category: " << category << ", Quantity: " << quantity << endl;
    }
};

// Hotel Reservation System
class Reservation {
protected:
    int resID, nights;
    string guestName, roomType;
    double roomRate;
public:
    Reservation(int id, string g, string r, int n, double rate) : resID(id), guestName(g), roomType(r), nights(n), roomRate(rate) {}
    void updateRoomType(string r) { roomType = r; }
    void updateNights(int n) { nights = n; }
    void display() {
        cout << "ID: " << resID << ", Guest: " << guestName << ", Room: " << roomType << ", Nights: " << nights << ", Revenue: " << (nights * roomRate) << endl;
    }
};

// Inventory Management System
class InventoryItem {
protected:
    int itemID, quantity;
    string name;
    double price;
public:
    InventoryItem(int id, string n, int q, double p) : itemID(id), name(n), quantity(q), price(p) {}
    void updateQuantity(int q) { quantity = q; }
    void display() {
        cout << "ID: " << itemID << ", Name: " << name << ", Quantity: " << quantity << ", Price: " << price << ", Total Value: " << (quantity * price) << endl;
    }
};

// Stack Implementation
class Stack {
private:
    int arr[100];
    int top;
public:
    Stack() : top(-1) {}
    void push(int val) {
        if (top < 99) arr[++top] = val;
    }
    void pop() {
        if (top >= 0) top--;
    }
    void display() {
        for (int i = 0; i <= top; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

// Binary Search
int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    School s("Greenwood Academy");
    s.addStudent("Alice");
    s.assignTeacher("Mr. Brown");
    s.display();
    
    Employee e(1, "John Doe", "IT", 50000);
    e.display();
    
    LibraryItem book(101, "C++ Programming", "Bjarne Stroustrup", "Book", 10);
    book.display();
    
    Reservation r(201, "Jane Doe", "Deluxe", 5, 100);
    r.display();
    
    InventoryItem item(301, "Laptop", 5, 1000);
    item.display();
    
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.display();
    
    int arr[] = {5, 2, 9, 1, 5, 6};
    mergeSort(arr, 0, 5);
    for (int i = 0; i < 6; i++) cout << arr[i] << " ";
    return 0;
}
