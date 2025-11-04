//Programmer: Feliciano Escalante Najera 2941390
//Creation date: 11/3/2025 - 11/4/2025


#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    // Constructor
    DynamicArray(int initialCapacity = 4)
        : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;
    }

    // Copy constructor
    DynamicArray(const DynamicArray& other)
        : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    // Copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    // Move constructor
    DynamicArray(DynamicArray&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    //This moves the assignment operator.
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            capacity = other.capacity;
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    //This adds an element to the end.
    void push_back(const T& value) {
        if (size == capacity)
            resize();
        data[size++] = value;
    }

    //This is the element access with bounds checking. 
    T& at(int index) {
        if (index < 0 || index >= size)
            throw out_of_range("That's out of bounds!! >:(");
        return data[index];
    }

    //Access element.
    T& operator[](int index) {
        return data[index];
    }

    //These are the getters.
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }

    //These are the iterators.
    T* begin() { return data; }
    T* end() { return data + size; }
};

//---------------------------------------------------------------------------

int main() {
    DynamicArray<int> burgers;

    int quantity;
    cout << "How many burgers do you want?: ";
    cin >> quantity;
    cout << endl;

    for (int i = 0; i < quantity; ++i) {
        int patties;
        cout << "How many patties on burger #" << (i + 1) << "?: ";
        cin >> patties;
        cout << endl;
        burgers.push_back(patties);
    }

    cout << "Amount of patties that are on each burger: ";
    for (auto patties : burgers)
        cout << patties << " ";
    cout << endl;

    return 0;
}
