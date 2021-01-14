//definition of parameterized constructor
AnyType::AnyType(FundamentalTypes data) : myData(data) {}
//definition of copy constructor
AnyType::AnyType(const AnyType& other) : myData(other.myData) {}

//overloading of copy assignment operator,
template<typename Type>
AnyType& AnyType::operator=(const Type& other) {
    //typeid() returns type_info object which has .name() method
    int enum_index = GetEnumIndex(FixTypeidName(typeid(other).name()));
    if ((enum_index > TypeBegin) && (enum_index < TypeEnd))  {
        this->myData = other;
        return *this;
    } else {
        cout << "Wrong type to store. Only int, unsigned int, long int, float, double, long double, char, bool.\n";
        return *this;
    }
}

//overloading of assignment operator, no throw
AnyType& AnyType::operator=(const AnyType& other) {
    if (this->myData == other.myData) {
        return *this;
    } else {
        this->myData = other.myData;
        return *this;
    }
}

//definition of GetType() method
string AnyType::GetType() const {
    //1st arg - callable, 2nd arg - list of variants to pass to a visitor
    const string type = visit([](auto const &data){return typeid(data).name();}, this->myData);
    return FixTypeidName(type);
}

//definition of GetValue() method
template<typename Type>
Type AnyType::GetValue() const {
    //create variable og type Type to compare to the stored variable type
    Type t;
    if (this->GetType() == FixTypeidName(typeid(t).name())) {
        //variant::Type-based value accessor: If an arg holds the alternative T, returns a reference
        // to the value stored in arg
        Type value = get<Type>(myData);
        return value;
    }  else {
        throw bad_cast();
    }
}

//definition of Swap() method
void AnyType::Swap(AnyType& other) {
    FundamentalTypes temp = this->myData;
    this->myData = other.myData;
    other.myData = temp;
}

const int AnyType::GetEnumIndex(const string &str) const {
    if (str == "int") {
        return TypeInt;
    } else if (str == "unsigned int") {
        return TypeUnsignedInt;
    } else if (str == "long int") {
        return TypeLongInt;
    } else if (str == "float") {
        return TypeFloat;
    } else if (str == "double") {
        return TypeDouble;
    } else if (str == "long double") {
        return TypeLongDouble;
    } else if (str == "char") {
        return TypeChar;
    } else if (str == "bool") {
        return TypeBool;
    } else {
        return TypeBegin;
    }
}

//Fix type_info::name method
const string FixTypeidName(const string &typeName) {
    string type = typeName;
    if (type == typeid(int).name()) {
        return "int";
    } else if (type == typeid(unsigned int).name()) {
        return "unsigned int";
    } else if (type == typeid(long int).name()) {
        return "long int";
    } else if (type == typeid(float).name()) {
        return "float";
    } else if (type == typeid(double).name()) {
        return "double";
    } else if (type == typeid(long double).name()) {
        return "long double";
    } else if (type == typeid(char).name()) {
        return "char";
    } else if (type == typeid(bool).name()) {
        return "bool";
    } else {
        return "ERROR: Wrong type. Only int, unsigned int, long int, float, double, long double, char, bool";
    }
}
