#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
#include <variant>
#define ToInt GetValue<int>
#define ToUInt GetValue<unsigned int>
#define ToLInt GetValue<long int>
#define ToFloat GetValue<float>
#define ToDouble GetValue<double>
#define ToLDouble GetValue<long double>
#define ToChar GetValue<char>
#define ToBool GetValue<bool>
using namespace std;

enum Type {
    TypeBegin = -1,
    TypeInt, TypeUnsignedInt, TypeLongInt, TypeFloat,
    TypeDouble, TypeLongDouble, TypeChar, TypeBool,
    TypeEnd
};

//the class template std::variant represents a type-safe union
using FundamentalTypes = variant<int, unsigned int, long int, float, double, long double,
                                char, bool>;

class AnyType {
private:
    FundamentalTypes myData;
    const int GetEnumIndex(const string&) const;
public:
    void Swap(AnyType&);
    template<typename Type>
    Type GetValue() const;
    string GetType() const;
    AnyType() = default;
    AnyType(FundamentalTypes data);
    //copy constructor
    AnyType(const AnyType&);
    //move constructor - compiler does not know how to move variant
//    AnyType(const AnyType&&) = delete;
    template<typename Type>
    //copy assignment
    AnyType& operator=(const Type&);
    AnyType& operator=(const AnyType&);
    ~AnyType() = default;
};

//Fix type_info::name method
const string FixTypeidName(const string &typeName);

#include "AnyType.inl"
