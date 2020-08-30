# CPP Exceptions

- We can throw different types of exceptions (int, char\* string, Class, etc.) in a code block.

```cpp
    bool err = false;
    bool err2 = true;
    bool err3 = true;
    if (err)
    {
        // we can throw an int here
        throw 8;
    }
    if (err2)
    {
        // we can also throw an char* (string) description
        throw "Something went wrong...";
    }
    if (err3)
    {
        // or throw a class exception.
        // string is a class
        throw string("Something else went wrong...");
    }
```

- We should catch exception by reference

  > The standard practice for exceptions in C++ is Throw by value, catch by reference
  > Catching by value is problematic in the face of inheritance hierarchies. Suppose for your example that there is another type MyException which inherits from CustomException and overrides items like an error code. If a MyException type was thrown your catch block would cause it to be converted to a CustomException instance which would cause the error code to change.
  >
  > - stack over flow

  - When catching multiple exceptions, We should catch more specific exception first, and genreal exceptions later.

```cpp
try
    {
        goesWrong(false, true);
    }
    catch (bad_alloc &ba)
    {
        cout << "Catching bad_alloc exception" << endl
             << ba.what() << endl;
    }
    catch (exception &e)
    {
        cout << "Catching a general exception" << endl
             << e.what() << endl;
    }
```
