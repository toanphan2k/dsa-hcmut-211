#ifndef __JAVM_EXCEPTIONS_H__
#define __JAVM_EXCEPTIONS_H__

#include <string>

/*
This exception occurs when the type of the operand is not compatible with the required type of the operation.
*/
class TypeMisMatch : public std::exception {
    std::string message; // exception message

public:
    /*
    Constructor of TypeMismatch
    @param line the line number where the exception occurs, starting at 1
    */
    TypeMisMatch(int line) {
        message = "Type mismatch: line " + std::to_string(line);
    }

    /*
    Get the exception's message
    @return The exception's message
    */
    const char* what() const throw() {
        return message.c_str();
    }
};

/*
This exception occurs when the second operand of a division is zero.
*/
class DivideByZero : public std::exception {
    std::string message; // exception message

public:
    /*
    Constructor of DivideByZero
    @param line the line number where the exception occurs, starting at 1
    */
    DivideByZero(int line) {
        message = "Divide by zero: line " + std::to_string(line);
    }

    /*
    Get the exception's message
    @return The exception's message
    */
    const char* what() const throw() {
        return message.c_str();
    }
};

/*
This exception occurs when an element is pushed to a full operand stack.
*/
class StackFull : public std::exception {
    std::string message; // exception message

public:
    /*
    Constructor of StackFull
    @param line the line number where the exception occurs, starting at 1
    */
    StackFull(int line) {
        message = "Stack full: line " + std::to_string(line);
    }

    /*
    Get the exception's message
    @return The exception's message
    */
    const char* what() const throw() {
        return message.c_str();
    }
};

/*
This exception occurs when trying to pop an element out of an empty operand stack.
*/
class StackEmpty : public std::exception {
    std::string message; // exception message

public:
    /*
    Constructor of StackEmpty
    @param line the line number where the exception occurs, starting at 1
    */
    StackEmpty(int line) {
        message = "Stack empty: line " + std::to_string(line);
    }

    /*
    Get the exception's message
    @return The exception's message
    */
    const char* what() const throw() {
        return message.c_str();
    }
};

/*
This exception occurs when trying to access an element that is out of the bound of the local variable array.
*/
class ArrayOutOfRange : public std::exception {
    std::string message; // exception message

public:
    /*
    Constructor of ArrayOutOfRange
    @param line the line number where the exception occurs, starting at 1
    */
    ArrayOutOfRange(int line) {
        message = "Array out of range: line " + std::to_string(line);
    }

    /*
    Get the exception's message
    @return The exception's message
    */
    const char* what() const throw() {
        return message.c_str();
    }
};

/*
This exception occurs when trying to access an element of the local variable array that has not been defined.
*/
class UndefinedVariable : public std::exception {
    std::string message; // exception message

public:
    /*
    Constructor of UndefinedVariable
    @param line the line number where the exception occurs, starting at 1
    */
    UndefinedVariable(int line) {
        message = "Undefined variable: line " + std::to_string(line);
    }

    /*
    Get the exception's message
    @return The exception's message
    */
    const char* what() const throw() {
        return message.c_str();
    }
};

#endif // !__JAVM_EXCEPTIONS_H__