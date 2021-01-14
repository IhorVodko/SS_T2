#include "AnyType.h"


int main() {
    AnyType anyType('a');
    //conversion sequence (more than two), only one or zero user-defined conv is allowed
//    AnyType anyType = 12;
    cout << "Stored type is: " << anyType.GetType() << '\n';
    anyType = 12;
    cout << "Stored type is: " << anyType.GetType() << '\n';
    cout << "--------------------------------------------------------\n";
    anyType = "hello";
    cout << "Stored type is: " << anyType.GetType() << '\n';
    cout << "--------------------------------------------------------\n";
    cout << "Stored type is int and a requested type is int" << '\n';
    try {
//        cout << "Stored variable contains a value: " << anyType.GetValue<int>() << '\n';
        cout << "Stored variable contains a value: " << anyType.ToInt() << '\n';
    } catch (const bad_cast &exc) {
        cout << exc.what() << '\n';
    }
    cout << "--------------------------------------------------------\n";
    cout << "Stored type is int and a requested type is char" << '\n';
    try {
        cout << "Stored variable contains a value: "<< anyType.ToChar() << '\n';
    } catch (const bad_cast &exc) {
        cout << exc.what() << '\n';
    }
    cout << "--------------------------------------------------------\n";
    cout << "Before the swap: " << '\n';
    float f = 3.14;
    AnyType anyTypeA(f);
    cout << "Object A has a type of: " << anyTypeA.GetType() << '\n';
    bool b = true;
    AnyType anyTypeB(b);
    cout << "Object B has a type of: " << anyTypeB.GetType() << '\n';
    anyTypeA.Swap(anyTypeB);
    cout << "After the swap: " << '\n';
    cout << "Object A has a type of: " << anyTypeA.GetType() << '\n';
    cout << "Object B has a type of: " << anyTypeB.GetType() << '\n';

    return 0;
}
