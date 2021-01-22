#include "AnyType.h"

void CLInterfaceOuter();
void SelectClassMethod(AnyType& anyType);
void SwapMethodInterface(AnyType& anyTypeThis, AnyType& anyTypeOther);
void ValueBasedOnTypeStored(AnyType& anyType);

int main() {
    CLInterfaceOuter();
    return 0;
}

void CLInterfaceOuter() {
    int typeToStore;
    do {
        cout << "\nSelect what type of variable to store?\n"
             << "\"1\" - for int\n"
             << "\"2\" - for unsignedlong int\n"
             << "\"3\" - for long int\n"
             << "\"4\" - for float\n"
             << "\"5\" - for double\n"
             << "\"6\" - for long double\n"
             << "\"7\" - for char\n"
             << "\"8\" - for double\n"
             << "\"9\" - to demonstrate a type safe access\n"
             << "\"0\" - to exit\n\n";
        cin >> typeToStore;
        switch (typeToStore) {
            case 1: {
                cout << "Enter a value:\n";
                int var1;
                while (!(cin >> var1)) {
                    cout << "Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                AnyType anyType1(var1);
                cout << "Class anyType1 was created with int.\n";
                SelectClassMethod(anyType1);
                break;
            }
            case 2: {
                cout << "Enter a value:\n";
                unsigned int var2;
                while (!(cin >> var2)){
                    cout <<"Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                AnyType anyType2(var2);
                cout << "Class anyType2 was created with unsigned int.\n";
                SelectClassMethod(anyType2);
                break;
            } case 3: {
                cout << "Enter a value:\n";
                long int var3;
                while (!(cin >> var3)){
                    cout <<"Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                AnyType anyType3(var3);
                cout << "Class anyType3 was created with int long int.\n";
                SelectClassMethod(anyType3);
                break;
            } case 4: {
                cout << "Enter a value:\n";
                float var4;
                while (!(cin >> var4)){
                    cout <<"Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                AnyType anyType4(var4);
                cout << "Class anyType4 was created with float.\n";
                SelectClassMethod(anyType4);
                break;
            } case 5: {
                cout << "Enter a value:\n";
                double var5;
                while (!(cin >> var5)){
                    cout <<"Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                AnyType anyType5(var5);
                cout << "Class anyType5 was created with double.\n";
                SelectClassMethod(anyType5);
                break;
            } case 6: {
                cout << "Enter a value:\n";
                long double var6;
                while (!(cin >> var6)){
                    cout <<"Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                AnyType anyType6(var6);
                cout << "Class anyType6 was created with long double.\n";
                SelectClassMethod(anyType6);
                break;
            } case 7: {
                cout << "Enter a value (if a string is entered only first character "
                        "will be stored):\n";
                char var7;
                while (!(cin >> var7)){
                    cout <<"Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                AnyType anyType7(var7);
                cout << "Class anyType7 was created with char.\n";
                SelectClassMethod(anyType7);
                break;
            } case 8: {
                cout << "Enter a value:\n";
                bool var8;
                while (!(cin >> var8)) {
                    cout << "Enter a valid input for the selected type.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                AnyType anyType8(var8);
                cout << "Class anyType8 was created with float.\n";
                SelectClassMethod(anyType8);
                break;
            } case 9: {
                cout << "Assume a user stored a variable of type char in an object, \n"
                        "but tries to get a value of type float. Then \"bad_cast\" exception \n"
                        "will be thrown.\n";
                AnyType anyType9('c');
                try {
                    cout << anyType9.ToFloat() << '\n';
                } catch (const bad_cast& ex) {
                    cout << ex.what();
                }
                cout << '\n';
                break;
            } case 0: {
                cout << "Program ended successfully.\n";
                break;
            }
            default: {
                cout << "Incorrect input, only a number in the range of 0-8 is allowed. "
                        "Try again.\n";
            }
        }
    } while (typeToStore != 0 );
}

void SelectClassMethod(AnyType& anyTypeThis) {
    int methodSelected;
    do {
        cout << "\n\"1\" - to get type of the stored variable\n"
             << "\"2\" - to get value of the stored variable\n"
             << "\"3\" - to swap this object with other object\n"
             << "\"0\" - to create one more object\n\n";
        cin >> methodSelected;
        switch (methodSelected) {
            case 1: {
                cout << "Stored variable's type is: " << anyTypeThis.GetType() << '\n';
                break;
            }
            case 2: {
                cout << "Stored variable's value is: ";
                string type = anyTypeThis.GetType();
                if (type == "int") {
                    cout << anyTypeThis.ToInt();
                } else if (type == "unsigned int") {
                    cout << anyTypeThis.ToUInt();
                } else if (type == "long int") {
                    cout << anyTypeThis.ToLInt();
                } else if (type == "float") {
                    cout << anyTypeThis.ToFloat();
                } else if (type == "double") {
                    cout << anyTypeThis.ToDouble();
                } else if (type == "long double") {
                    cout << anyTypeThis.ToLDouble();
                } else if (type == "char") {
                    cout << anyTypeThis.ToChar();
                } else if (type == "bool") {
                    cout << anyTypeThis.ToBool();
                }
                cout << '\n';
                break;
            } case 3: {
                int typeToStore;
                do {
                    cout << "\nCreate other object to be swapped with this object\n"
                         << "Select what type of variable to store in the other object?\n"
                         << "\"1\" - for int\n"
                         << "\"2\" - for unsignedlong int\n"
                         << "\"3\" - for long int\n"
                         << "\"4\" - for float\n"
                         << "\"5\" - for double\n"
                         << "\"6\" - for long double\n"
                         << "\"7\" - for char\n"
                         << "\"8\" - for double\n"
                         << "\"0\" - to return back to class methods\n\n";
                    cin >> typeToStore;
                    switch (typeToStore) {
                        case 1: {
                            cout << "Enter a value:\n";
                            int var1;
                            while (!(cin >> var1)) {
                                cout << "Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            AnyType anyType1(var1);
                            cout << "Class anyType1 was created with int.\n";
                            SwapMethodInterface(anyTypeThis, anyType1);
                            break;
                        }
                        case 2: {
                            cout << "Enter a value:\n";
                            unsigned int var2;
                            while (!(cin >> var2)){
                                cout <<"Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            AnyType anyType2(var2);
                            cout << "Class anyType2 was created with unsigned int.\n";
                            SwapMethodInterface(anyTypeThis, anyType2);
                            break;
                        } case 3: {
                            cout << "Enter a value:\n";
                            long int var3;
                            while (!(cin >> var3)){
                                cout <<"Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            AnyType anyType3(var3);
                            cout << "Class anyType3 was created with int long int.\n";
                            SwapMethodInterface(anyTypeThis, anyType3);
                            break;
                        } case 4: {
                            cout << "Enter a value:\n";
                            float var4;
                            while (!(cin >> var4)){
                                cout <<"Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            AnyType anyType4(var4);
                            cout << "Class anyType4 was created with float.\n";
                            SwapMethodInterface(anyTypeThis, anyType4);
                            break;
                        } case 5: {
                            cout << "Enter a value:\n";
                            double var5;
                            while (!(cin >> var5)){
                                cout <<"Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            AnyType anyType5(var5);
                            cout << "Class anyType5 was created with double.\n";
                            SwapMethodInterface(anyTypeThis, anyType5);
                            break;
                        } case 6: {
                            cout << "Enter a value:\n";
                            long double var6;
                            while (!(cin >> var6)){
                                cout <<"Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            AnyType anyType6(var6);
                            cout << "Class anyType6 was created with long double.\n";
                            SwapMethodInterface(anyTypeThis, anyType6);
                            break;
                        } case 7: {
                            cout << "Enter a value (if a string is entered only first character "
                                    "will be stored):\n";
                            char var7;
                            while (!(cin >> var7)){
                                cout <<"Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            AnyType anyType7(var7);
                            cout << "Class anyType7 was created with char.\n";
                            SwapMethodInterface(anyTypeThis, anyType7);
                            break;
                        } case 8: {
                            cout << "Enter a value:\n";
                            bool var8;
                            while (!(cin >> var8)) {
                                cout << "Enter a valid input for the selected type.\n";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            AnyType anyType8(var8);
                            cout << "Class anyType8 was created with float.\n";
                            SwapMethodInterface(anyTypeThis, anyType8);
                            break;
                        } case 0: {
                            cout << "Returned to class methods selection.\n";
                            break;
                        }
                        default: {
                            cout << "Incorrect input, only a number in the range of 0-8 is allowed. "
                                    "Try again.\n";
                        }
                    }
                } while (typeToStore != 0 );
                break;
            } case 0: {
                cout << "\n";
            } default: {
                cout << "Incorrect input, only a number in the range of 0-2 is allowed. Try again.\n";
            }
        }
    } while (methodSelected != 0);
}

void SwapMethodInterface(AnyType& anyTypeThis, AnyType& anyTypeOther) {
    cout << "Class anyType1 was created with int.\n";
    cout << "--------------------BeforeTheSwap---------------\n"
         << "anyTypeThis object's stored variable type and value: "
         << anyTypeThis.GetType() << " ";
    ValueBasedOnTypeStored(anyTypeThis);
    cout << '\n';
    cout << "anyTypeOther object's stored variable type and value: "
         << anyTypeOther.GetType() << " ";
    ValueBasedOnTypeStored(anyTypeOther);
    cout << '\n';
    anyTypeThis.Swap(anyTypeOther);
    cout << "--------------------AfterTheSwap---------------\n"
         << "anyTypeThis object's stored variable type and value: "
         << anyTypeThis.GetType() << " ";
    ValueBasedOnTypeStored(anyTypeThis);
    cout << '\n';
    cout << "anyTypeOther object's stored variable type and value: "
         << anyTypeOther.GetType() << " ";
    ValueBasedOnTypeStored(anyTypeOther);
    cout << '\n';
}

void ValueBasedOnTypeStored(AnyType& anyType) {
    string type = anyType.GetType();
    if (type == "int") {
        cout << anyType.ToInt();
    } else if (type == "unsigned int") {
        cout << anyType.ToUInt();
    } else if (type == "long int") {
        cout << anyType.ToLInt();
    } else if (type == "float") {
        cout << anyType.ToFloat();
    } else if (type == "double") {
        cout << anyType.ToDouble();
    } else if (type == "long double") {
        cout << anyType.ToLDouble();
    } else if (type == "char") {
        cout << anyType.ToChar();
    } else if (type == "bool") {
        cout << anyType.ToBool();
    }
}
