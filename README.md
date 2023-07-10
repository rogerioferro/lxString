# lxString
Extends std::basic_string and adds more functionality

* Implements very useful constructors and members

* Useful constructors:
  1. string(int value) => Construct string with the representation of value;
  2. string(long value) => Construct string with the representation of value;
  3. string(long long value) => Construct string with the representation of value;
  4. string(unsigned value) => Construct string with the representation of value;
  5. string(unsigned long value) => Construct string with the representation of value;
  6. string(unsigned long long value) => Construct string with the representation of value;
  7. string(float value) => Construct string with the representation of value;
  8. string(double value) => Construct string with the representation of value;
  9. string(long double value) => Construct string with the representation of value;

* Useful members
  1. string toUpper() =>  return a new string with lowercase letters converted to uppercase;
  2. string toLower() =>  return a new string with uppercase letters converted to lowercase;
  3. string trimStart() => return a new string with all spaces from the start removed;
  4. string trimEnd() => return a new string with all spaces from the end removed;
  5. string trim() => return a new string with all spaces from the start and from end removed;
  6. string after(string s) => return the string after the first occurrence of "s";
  7. string before(string s) => return the string before the first occurrence of "s";
  8. string skip(size_t n) => return a new string without the "n" firsts characters;
  9. string take(size_t n) => return a new string with the "n" firsts characters;
  10. bool isDigits() => Check if the string is a valid number.
  11. bool isLower() => Check if all characters is lowercase.
  12. bool isUpper() => Check if all characters is uppercase.
  13. bool isAlpha() => Check if all characters is alphabetic.
  14. bool startsWith(const string &preFix) => Check if string starts with "preFix";
  15. bool endsWith(const string &suffix) => Check if string ends with "preFix";
  16. std::vector<string> split(string_type delimiters) => Splits a string into substrings based on a specified delimiting character;
  17. void shuffleIt() => Shuffle the characters of the string.
  18. string shuffled() => return a copy of string with the characters shuffled.
  19. int toInt(int base = 10) => Parses string interpreting its content as an integral number of the specified base, which is returned as an int value.
  20. long toLong(int base = 10) => Parses string interpreting its content as an integral number of the specified base, which is returned as an long int value.
  21. long long toLongLong(int base = 10) => Parses string interpreting its content as an integral number of the specified base, which is returned as an long long int value.
  22. unsigned long toULong(int base = 10) =>  Parses string interpreting its content as an integral number of the specified base, which is returned as an unsigned long int value.
  23. unsigned long long toULongLong(int base = 10) =>  Parses string interpreting its content as an integral number of the specified base, which is returned as an unsigned long long int value.
  24. float toFloat() => Parses string interpreting its content as a floating-point number, which is returned as a value of type float.
  25. double toDouble() => Parses string interpreting its content as a floating-point number, which is returned as a value of type double.
  26. long double toLongDouble() => Parses string interpreting its content as a floating-point number, which is returned as a value of type long double.

