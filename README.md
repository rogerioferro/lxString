# lxString
Extends std::basic_string and adds more functionality

* Implements very useful constructors and members

* Construct string with the representation of value:
    ```C++    
    string(int value);
    string(long value);
    string(long long value);
    string(unsigned);
    string(unsigned long value);
    string(unsigned long long value);
    string(float value);
    string(double value);
    string(long double value);
   ```

* Useful members
  ```C++
  using namespace lx;
  void main()
  {
    string str = "   123.12 , Hello World!!!   ";

    string upper = str.toUpper();   // return a new string with lowercase letters converted to uppercase;
    string lower = str.toLower();   // return a new string with uppercase letters converted to lowercase;

    string trimStart = str.trimStart();   // return a new string with all spaces from the start removed;
    string trimEnd = str.trimEnd();       // return a new string with all spaces from the end removed;
    string trim = str.trim();             // return a new string with all spaces from the start and from end removed;
  
    string after = str.after(",");     // return the string after the first occurrence of ",";
    string before = str.before(",");   // return the string before the first occurrence of ",";
    string skip = str.skip(10);        // return a new string without the 10 firsts characters;
    string take = str.take(10);        // return a new string with the 10 firsts characters;
  
    bool isDigits = str.isDigits();        // Check if the string is a valid number.
    bool isLower = str.isLower();          // Check if all characters is lowercase.
    bool isUpper = str.isUpper();          //Check if all characters is uppercase.
    bool isAlpha = str.isAlpha();          //Check if all characters is alphabetic.
    bool startsWith = startsWith("abc");   // Check if string starts with "abc";
    bool endsWith = endsWith("abc");       // Check if string ends with "abc";

    std::vector<string> split = str.split(",");  // Splits a string into substrings based on a specified delimiting character;

    string shuffled = str.shuffled(); // return a copy of string with the characters shuffled.
    shuffled.shuffleIt();             // Shuffle the characters of the string.
  
    int i = str.toInt();              // Parses string interpreting its content as an integral number of the specified base,
                                      // which is returned as an int value.
    long l = str.toLong();            // Parses string interpreting its content as an integral number of the specified base,
                                      // which is returned as an long int value.
    long long ll = str.toLongLong();  // Parses string interpreting its content as an integral number of the specified base,
                                      // which is returned as an long long int value.
    unsigned long ul = str.toULong(); // Parses string interpreting its content as an integral number of the specified base,
                                      // which is returned as an unsigned long int value.
    unsigned long long ull = str.toULongLong(); // Parses string interpreting its content as an integral number of the specified base,
                                                // which is returned as an unsigned long long int value.
    float f = str.toFloat();              // Parses string interpreting its content as a floating-point number,
                                          // which is returned as a value of type float.
    double d = str.toDouble()             // Parses string interpreting its content as a floating-point number,
                                          // which is returned as a value of type double.
    long double ld = str.toLongDouble();  //Parses string interpreting its content as a floating-point number,
                                          // which is returned as a value of type long double.
  }
  ```

