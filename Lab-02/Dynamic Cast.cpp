#include <iostream>
using namespace std;

class Duck {
    bool rubber;
public:
    Duck() : rubber(false) {
        cout << "Duck created!" << endl;
    }

    virtual ~Duck() {
        cout << "Duck destroyed!" << endl;
    }

    void setRubber(bool value) {
        rubber = value;
    }

    virtual void quack() {
        if(rubber) cout << "Artificial Quack" << '\n';
        else cout << "Real Quack" << '\n';
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck() {
        setRubber(true);
        cout << "RubberDuck created!" << endl;
    }

    ~RubberDuck() {
        cout << "RubberDuck destroyed!" << endl;
    }
};

class RealDuck : public Duck {
public:
    RealDuck() {
        setRubber(false);
        cout << "RealDuck created!" << endl;
    }

    ~RealDuck() {
        cout << "RealDuck destroyed!" << endl;
    }
};

// Template function to handle different types
template <typename T>
void processData(T data) {
    cout << "Data: " << data << endl;
}

int main() {
    int i = 42;
    double d = 3.14;

    // Using template function instead of void* and casting
    processData(i);
    processData(d);

    Duck* d1 = new RubberDuck();
    Duck* d2 = new RealDuck();

    // Using dynamic_cast to safely cast pointers
    if (RealDuck* rd = dynamic_cast<RealDuck*>(d1)) {
        rd->quack();
    } else {
        cout << "Casting Error: d1 is not a RealDuck" << '\n';
    }

    // Cleaning up memory
    delete d1;  // Calls destructor for the correct object type (RubberDuck)
    delete d2;  // Calls destructor for RealDuck

    return 0;
}
