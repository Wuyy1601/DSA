#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    float x, y, z;
    Point* next;
};

struct LinkedList {
    Point* head;
    Point* tail;
};

void CreateList(LinkedList& list) {
    list.head = list.tail = nullptr;
}

Point* CreatePoint(float x, float y, float z) {
    Point* point = new Point;
    point->x = x;
    point->y = y;
    point->z = z;
    point->next = nullptr;
    return point;
}

void AddTail(LinkedList& list, float x, float y, float z) {
    Point* point = CreatePoint(x, y, z);
    if (list.head == nullptr) {
        list.head = list.tail = point;
    }
    else {
        list.tail->next = point;
        list.tail = point;
    }
}

bool SoSanh(const Point& p1, const Point& p2) {
    if ((p1.x - p2.x)>0) {
        if ((p1.y - p2.y)>0) {
            return p1.z < p2.z;
        }
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}

int BinarySearch(LinkedList& list, float x, float y, float z) {
    int steps = 0;
    int left = 0, right = 0;

    Point* current = list.head;
    while (current != nullptr) {
        right++;
        current = current->next;
    }
    right--;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        current = list.head;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }

        Point target;
        target.x = x;
        target.y = y;
        target.z = z;
        target.next = nullptr;
        if ((current->x == x) && (current->y == y) && (current->z == z)) {
            return steps;
        }
        else if (SoSanh(*current, target)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}


int main() {
    LinkedList list;
    CreateList(list);

    int n, m;
    float x, y, z;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        AddTail(list, x, y, z);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        int result = BinarySearch(list, x, y, z);
        if (result == -1) {
            cout << "KHONG" << endl;
        }
        else {
            cout << result << endl;
        }
    }


    Point* current = list.head;
    while (current != nullptr) {
        Point* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
