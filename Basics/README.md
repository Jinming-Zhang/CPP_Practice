# CPP Basics

## Primitives

src: [Geeksforgeeks](https://www.geeksforgeeks.org/c-data-types/)

- Integer

  Integers typically requires 4 bytes of memory space and ranges from -2147483648 to 2147483647.

- Character

  Characters typically requires 1 byte of memory space and ranges from -128 to 127 or 0 to 255.

- Boolean

- Floating Point

  loat variables typically requires 4 byte of memory space.

- Double Floating Point

  Double variables typically requires 8 byte of memory space.

- Valueless or Void
- Wide Character

  Wide character data type is also a character data type but this data type has size greater than the normal 8-bit datatype. Represented by wchar_t. It is generally 2 or 4 bytes long.

## Data type modifiers

- Signed
- Unsigned
- Short
- Long

## Limit of data types

```cpp
cout<<"Limits of Data types:\n";
    cout<<"char\t\t\t: "<<static_cast<int>(numeric_limits<char>::min())<<" to "<<static_cast<int>(numeric_limits<char>::max())<<endl;
    cout<<"unsigned char\t\t: "<<static_cast<int>(numeric_limits<unsigned char>::min())<<" to "<<static_cast<int>(numeric_limits<unsigned char>::max())<<endl;
    cout<<"short\t\t\t: "<<numeric_limits<short>::min()<<" to "<<numeric_limits<short>::max()<<endl;
    cout<<"unsigned short\t\t: "<<numeric_limits<unsigned short>::min()<<" to "<<numeric_limits<unsigned short>::max()<<endl;
    cout<<"int\t\t\t: "<<numeric_limits<int>::min()<<" to "<<numeric_limits<int>::max()<<endl;
    cout<<"unsigned int\t\t: "<<numeric_limits<unsigned int>::min()<<" to "<<numeric_limits<unsigned int>::max()<<endl;
    cout<<"long\t\t\t: "<<numeric_limits<long>::min()<<" to "<<numeric_limits<long>::max()<<endl;
    cout<<"unsigned long\t\t: "<<numeric_limits<unsigned long>::min()<<" to "<<numeric_limits<unsigned long>::max()<<endl;
    cout<<"long long\t\t: "<<numeric_limits<long long>::min()<<" to "<<numeric_limits<long long>::max()<<endl;
    cout<<"unsiged long long\t: "<<numeric_limits<unsigned long long>::min()<<" to "<<numeric_limits<unsigned long long>::max()<<endl;
    cout<<"float\t\t\t: "<<numeric_limits<float>::min()<<" to "<<numeric_limits<float>::max()<<endl;
    cout<<"double\t\t\t: "<<numeric_limits<double>::min()<<" to "<<numeric_limits<double>::max()<<endl;
    cout<<"long double\t\t: "<<numeric_limits<long double>::min()<<" to "<<numeric_limits<long double>::max()<<endl;
```

- char : -128 to 127

- unsigned char : 0 to 255

- short : -32768 to 32767

- unsigned short : 0 to 65535

- int : -2147483648 to 2147483647

- unsigned int : 0 to 4294967295

- long : -2147483648 to 2147483647

- unsigned long : 0 to 4294967295

- long long : -9223372036854775808 to 9223372036854775807

- unsigned long long : 0 to 18446744073709551615

- float : 1.17549e-038 to 3.40282e+038

- double : 2.22507e-308 to 1.79769e+308

- long double : 3.3621e-4932 to 1.18973e+4932

## Input / Output to console

- use _insert_ operator '<<' to insert what we want to output to the console into the **cout** object.
- use **endl** or **flush** to tell the system flush the text to the console.

```cpp
    // flush the output to console with a newline char
    cout << "Something..." << endl;
    // flush the output to the console without a newline char
    cout << "Something..." << flush;
```

- use the _extract_ operator '>>' to extract input from the **cin** object and store it in a proper variable.

```cpp
string input;
cin >> input;
cout << "the input is: " << input <<endl;
```

## Pointer vs Reference

[geeksforgeeks](https://www.geeksforgeeks.org/references-in-c/)

### Reference

> When a variable is declared as reference, it becomes an alternative name for an existing variable. A variable can be declared as reference by putting ‘&’ in the declaration.

### Pointer

Stores a memory address. Can be anywhere, or Null.

### Differences

> - Once a reference is created, it cannot be later made to reference another object; it cannot be reseated.
>
> - References cannot be NULL. Pointers are often made NULL to indicate that they are not pointing to any valid thing.
>
> - A reference must be initialized when declared. There is no such restriction with pointers
>
> - References don’t need dereferencing operator to access the value. They can be used like normal variables. ‘&’ operator is needed only at the time of declaration.

## Constructor List

An easier syntax to write constructors for objects

```cs
class Wolf{
public:
  string name age;
  Wolf():name(name), age(age){

  }
};
```

This is equivalent to:

````cs
class Wolf{
public:
  string name age;
  Wolf(string name, string age){
    this->name = name;
    this->age = age;
  }
};
## Copy Constructor

Objects in C++ has an implicit Copy Constructor which invokes when initializing an object's value with another object. The copy constructor make a copy of the other object so the newly created object is independent from the another object.

```cs
Wolf wolf1(someProperties);
// this will let the '=', equal operator, invoke the copy constructor that returns a copy of wolf1 object
Wolf wolf2 = wolf1;
// or use this to call the copy constructor directly
Wolf wolf2 = Wolf(wolf1);
// this will only effect wolf2.
wolf2.someProperties = somethingElse;
````

To explicitly define the copy constructor in the object:

```cs
class Wolf{
public:
  // this is default constructor
  Wolf();
  // here is the explicit copy constructor
  // it takes a constant reference of the Wolf object to copy
  Wolf(const Wolf &anotherWolf){
    // if we explicitly defined this copy construcor, the default copy constructor will be override and then we have to manually copy the object, or it will not function as it 'suppose' to be
    this.something = anotherWolf.something;
  }
};
```
