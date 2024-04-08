/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:24:57 by codespace         #+#    #+#             */
/*   Updated: 2024/04/08 11:44:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat
{
	public:
		Bureaucrat(const std::string& new_name, const int new_grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& 		operator=(const Bureaucrat& assign);

		const std::string&	getName() const;
		int					getGrade() const;

		void				upgrade();
		void				downgrade();

		Bureaucrat&			operator++(void);
		Bureaucrat 			operator++(int);
		Bureaucrat&	 		operator--(void);
		Bureaucrat	 		operator--(int);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();			//for test purposes
				~GradeTooHighException() throw();	//for test purposes
				const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();				//for test purposes
				~GradeTooLowException() throw();	//for test purposes
				const char *what(void) const throw();
		};

	private:
		Bureaucrat();
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureau);


/*
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const char *msg) : msg(msg) {}
				const char *what(void) const throw();
			private:
				const char *msg;
		};
		defining my own paremeter constructor for the exception:
			it did not work as intended.......

*/

/*

	throw-try-catch-exception and Stack Unwinding

	If the xeception is caught in any of the catch-blocks, all variables inside
	the try-block are destroyed

	throw operand creates an object (the exception)

	https://learn.microsoft.com/en-us/cpp/cpp/exceptions-and-stack-unwinding-in-cpp?view=msvc-170
	"
		If a matching handler is still not found, or if an exception occurs during the
		unwinding process but before the handler gets control, the predefined run-time
		function terminate is called. If an exception occurs after the exception is thrown
		but before the unwind begins, terminate is called.
	"

	function terminate:
		function called at runtime
		-> infused by the compiler when handling exceptions

	automatic objects will be destroy during stack unwinding

	"automatic objects"?
		[Class] hello;   is an automatic object:
			it is constructed on the stack via constructor, either explicit or implicit
			[new] [class] is not automatic, will not be destroyed by stack unwinding since..
				it is not on the stack

	When an exception is thrown, the stack starts unwinding to try to find a try-catch block
	Unwinding starts at the throw statement
		-> all the function calls and associated automatic variables on the stack are
		destroy in reverse order to construction (makes sense, cleaning the call stack)
	If (it doesn't find a try block)
		 it will keep unwinding until destroying the stack
		-> and then calls terminate();
	else if (try block is found)





*/

/*

	https://medium.com/@sumana.dotnettricks/catch-c-the-ultimate-guide-to-mastering-exception-handling-576051bcb5e

Catch C++: The Ultimate Guide to Mastering Exception Handling
Sumana Dotnettricks
Sumana Dotnettricks

·
Follow

11 min read
·
Jun 13, 2023



Table of Contents
What is Exception Handling?
The Basics of Catching Exceptions
Try-Catch Blocks: Handling Exceptions Gracefully
C++ Exception Classes: Creating Custom Exceptions
Exception Specifications: Declaring Thrown Exceptions
Catching Multiple Exceptions: Handling Different Scenarios
Rethrowing Exceptions: Propagating Errors
Stack Unwinding: Cleaning Up Resources
Nothrow: Dealing with Memory Allocation Failures
Nested Exception Handling: Handling Exceptions within Exceptions
Exception Safety: Writing Robust Code
Standard Exception Classes: Understanding the Hierarchy
Handling Unknown Exceptions: The Catch-All Block
C++17: Improvements in Exception Handling
Common Exception Handling Mistakes: Pitfalls to Avoid
When to Use Exceptions: Guidelines and Considerations
Exception Handling in Real-World Applications
Debugging Techniques: Finding the Root Cause
Performance Considerations: Impact on Code Execution
Error Reporting and Logging: Best Practices
Unit Testing and Exception Handling: Ensuring Code Reliability
Future of Exception Handling: Trends and Innovations
FAQs
Conclusion
What is Exception Handling?
Exception handling is a programming technique that allows developers to deal with unexpected or exceptional situations during program execution. These exceptional situations, known as exceptions, can occur due to various reasons, such as invalid input, resource unavailability, or unexpected runtime errors. By incorporating exception handling mechanisms in their code, developers can gracefully handle these exceptions and prevent their programs from crashing or producing incorrect results.

Exceptions provide a structured way to handle errors and abnormal conditions. When an exceptional situation occurs, the program transfers control to a special code block called the exception handler. The exception handler is responsible for catching and processing the exception, providing an opportunity to perform appropriate actions, such as displaying an error message, logging the error, or taking corrective measures to recover from the exception.

In C++, exception handling is based on the principle of separation of error handling code from the normal flow of the program. This separation allows developers to focus on writing code for the program’s primary functionality, while handling exceptional cases separately. The catch-phrase in C++ exception handling allows developers to catch and handle specific types of exceptions, enabling precise error handling based on the nature of the exception.

The Basics of Catching Exceptions
In C++, exceptions are thrown using the throw keyword and caught using the try-catch construct. Let's take a closer look at the basic syntax and usage of catching exceptions.

cppCopy code
try {
  // Code that may throw an exception
} catch (ExceptionType1& e1) {
  // Exception handling code for ExceptionType1
} catch (ExceptionType2& e2) {
  // Exception handling code for ExceptionType2
} catch (...) {
  // Catch-all block for unknown exceptions
}
In the try block, we place the code that may potentially throw an exception. If an exception is thrown within the try block, the program flow is immediately transferred to the appropriate catch block based on the type of the exception.

The catch blocks provide the exception handling code for specific exception types. Each catch block specifies the type of exception it can handle, followed by a variable name (conventionally named e or ex) that represents the caught exception. The code within the catch block is executed when an exception of the corresponding type is caught.

The last catch block, denoted by catch (...), is a catch-all block that can catch any unknown exception type not caught by the preceding catch blocks. It is useful for handling unexpected exceptions or providing a fallback mechanism when the specific exception types are not known in advance.

It is important to note that the order of the catch blocks matters. If a more specific exception type is caught by a generic catch block, the specific catch block will never be reached. Therefore, it is recommended to order the catch blocks from most specific to least specific.

Example:
cppCopy code
#include <iostream>
void divide(int numerator, int denominator) {
  try {
    if (denominator == 0) {
      throw std::runtime_error("Division by zero!");
    }
    double result = static_cast<double>(numerator) / denominator;
    std::cout << "Result: " << result << std::endl;
  } catch (const std::exception& ex) {
    std::cout << "Exception caught: " << ex.what() << std::endl;
  }
}
int main() {
  divide(10, 2);
  divide(8, 0);
  divide(20, 5);

  return 0;
}
In this example, the divide function performs division between numerator and denominator parameters. If the denominator is zero, a std::runtime_error exception is thrown using the throw statement. The exception is then caught in the catch block, and an appropriate error message is displayed using the what() function of the exception object.

When we run the program, we get the following output:

vbnetCopy code
Result: 5
Exception caught: Division by zero!
Result: 4
As we can see, the first division succeeds and produces the expected result. The second division throws an exception, and the catch block handles the exception by displaying the error message. The third division executes without any exception.

By using exception handling, we can ensure that our programs gracefully handle exceptional cases and provide informative error messages to users or log the errors for later analysis. The catch block allows us to take appropriate actions based on the type of exception, such as providing alternative calculations, rolling back operations, or notifying users about the error.

Try-Catch Blocks: Handling Exceptions Gracefully
In C++, the try-catch block is the fundamental construct used for catching and handling exceptions. The try block encapsulates the code that might throw an exception, while the catch block handles the caught exceptions.

The primary purpose of the try-catch block is to ensure that the program flow gracefully transitions to the exception handler in case an exception is thrown, preventing the program from abruptly terminating or producing incorrect results.

Using Multiple Catch Blocks
In C++, we can have multiple catch blocks to handle different types of exceptions. Each catch block specifies the type of exception it can handle, allowing for precise exception handling based on the nature of the caught exception.

cppCopy code
try {
  // Code that may throw exceptions
} catch (ExceptionType1& e1) {
  // Exception handling code for ExceptionType1
} catch (ExceptionType2& e2) {
  // Exception handling code for ExceptionType2
} catch (ExceptionType3& e3) {
  // Exception handling code for ExceptionType3
}
When an exception is thrown within the try block, the program searches for the appropriate catch block based on the thrown exception's type. If a matching catch block is found, the corresponding exception handling code is executed. If no matching catch block is found, the exception propagates to the calling code or terminates the program if not caught at all.

It is important to order the catch blocks from most specific to least specific. This ensures that the most specific exceptions are caught and handled first, preventing them from being caught by a more generic catch block.

Example:
cppCopy code
#include <iostream>
#include <exception>
void handleException(const std::exception& ex) {
  std::cout << "Exception caught: " << ex.what() << std::endl;
}
int divide(int numerator, int denominator) {
  if (denominator == 0) {
    throw std::runtime_error("Division by zero!");
  }
  return numerator / denominator;
}
int main() {
  try {
    int result1 = divide(10, 2);
    std::cout << "Result 1: " << result1 << std::endl;
    int result2 = divide(8, 0);
    std::cout << "Result 2: " << result2 << std::endl;
    int result3 = divide(20, 5);
    std::cout << "Result 3: " << result3 << std::endl;
  } catch (const std::exception& ex) {
    handleException(ex);
  }

  return 0;
}
In this example, the divide function performs division between numerator and denominator. If the denominator is zero, a std::runtime_error exception is thrown. The exception is caught in the catch block within the main function, and the handleException function is called to handle the exception.

When we run the program, we get the following output:

yamlCopy code
Result 1: 5
Exception caught: Division by zero!
As we can see, the first division succeeds and produces the expected result. The second division throws an exception, and the catch block catches the exception and calls the handleException function to handle it. The program execution resumes after the exception is caught, and the third division is not executed.

Using multiple catch blocks allows us to handle different exception types separately and provide customized error handling based on the specific exception encountered. This fine-grained exception handling enhances the robustness and reliability of our code.

Catching Multiple Exception Types with One Catch Block
In addition to having multiple catch blocks for different exception types, C++ also allows us to catch multiple exception types in a single catch block. This can be useful when multiple exception types require the same handling logic.

cppCopy code
try {
  // Code that may throw exceptions
} catch (ExceptionType1& | ExceptionType2& | ExceptionType3& e) {
  // Exception handling code for ExceptionType1, ExceptionType2, or ExceptionType3
}
In the above syntax, the | symbol is used to specify multiple exception types that can be caught in a single catch block. When an exception of any of the specified types is thrown, the catch block is executed, and the caught exception can be accessed using the variable name specified after the & symbol.

Example:
cppCopy code
#include <iostream>
#include <exception>
void handleException(const std::exception& ex) {
  std::cout << "Exception caught: " << ex.what() << std::endl;
}
int divide(int numerator, int denominator) {
  if (denominator == 0) {
    throw std::runtime_error("Division by zero!");
  }
  return numerator / denominator;
}
int main() {
  try {
    int result1 = divide(10, 2);
    std::cout << "Result 1: " << result1 << std::endl;
    int result2 = divide(8, 0);
    std::cout << "Result 2: " << result2 << std::endl;
    int result3 = divide(20, 5);
    std::cout << "Result 3: " << result3 << std::endl;
  } catch (const std::exception& ex) {
    handleException(ex);
  }

  return 0;
}
In this example, the code is similar to the previous example, but the catch block has been modified to catch both std::runtime_error and std::logic_error exceptions using a single catch block.

When we run the program, we get the following output:

yamlCopy code
Result 1: 5
Exception caught: Division by zero!
As we can see, the output remains the same as before because we are catching the same type of exception. However, by using a single catch block, we can handle multiple exception types in a concise and unified manner.

Using multiple catch blocks and catching multiple exception types in a single catch block enables us to handle exceptions precisely and efficiently, ensuring that our code can handle different exceptional scenarios gracefully.

C++ Exception Classes: Creating Custom Exceptions
In addition to the standard exception classes provided by the C++ Standard Library, C++ allows developers to create custom exception classes to represent application-specific exceptions. Custom exception classes can provide more context-specific information about the exceptional situation and help differentiate between various types of exceptions.

To create a custom exception class, we can derive it from the base std::exception class or any of its derived classes, such as std::runtime_error or std::logic_error. The custom exception class can then define additional members or override base class functions to suit the specific exception requirements.

Let’s create a custom exception class named FileOpenException that represents an exception thrown when a file cannot be opened:

cppCopy code
#include <stdexcept>
class FileOpenException : public std::runtime_error {
public:
  explicit FileOpenException(const std::string& filename)
      : std::runtime_error("Failed to open file: " + filename) {}
};
In this example, the FileOpenException class is derived from std::runtime_error, which itself is derived from std::exception. The constructor of the FileOpenException class takes the filename as a parameter and appends it to the error message passed to the base class constructor.

We can then use this custom exception class to handle file opening errors in our code:

cppCopy code
#include <iostream>
#include <fstream>
void openFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw FileOpenException(filename);
  }
  // File processing code
}
int main() {
  try {
    openFile("nonexistent.txt");
  } catch (const FileOpenException& ex) {
    std::cout << ex.what() << std::endl;
  }

  return 0;
}
In this example, the openFile function attempts to open a file using an std::ifstream. If the file fails to open, a FileOpenException is thrown, passing the filename to the exception constructor. The exception is then caught in the main function, and the error message is displayed using the what() function.

Custom exception classes allow us to create a hierarchy of exceptions that reflect the specific types of exceptional situations encountered in our applications. By providing meaningful error messages and additional information through custom exception classes, we can enhance the clarity and effectiveness of exception handling in our code.

Frequently Asked Questions
Q: Can exceptions be thrown across multiple function calls? A: Yes, exceptions can be thrown across multiple function calls. When an exception is thrown, the program searches for the nearest appropriate catch block in the call stack. If a catch block is found, the exception is caught and handled. If the exception is not caught, it propagates up the call stack until it either encounters a catch block or terminates the program.

Q: What happens if an exception is not caught? A: If an exception is not caught, it propagates up the call stack until it reaches the top-level of the program or an appropriate catch block is encountered. If the exception is not caught at all, the program terminates, and an error message or crash report may be generated, depending on the platform and environment.

Q: Can exceptions be thrown in destructors? A: Yes, exceptions can be thrown in destructors. However, it is generally not recommended to throw exceptions in destructors as it can lead to unexpected behavior and potential resource leaks. It is advisable to handle exceptions within destructors and log or handle the errors without throwing exceptions further.

Q: Can we catch exceptions by value instead of by reference? A: Yes, exceptions can be caught by value instead of by reference. However, it is recommended to catch exceptions by const reference (const ExceptionType&) to avoid unnecessary object copying and to preserve the original exception type information. Catching by value (ExceptionType) creates a copy of the caught exception, which may not be desirable in all cases.

Q: Is exception handling expensive in terms of performance? A: Exception handling incurs a certain overhead compared to regular program execution. However, modern C++ implementations have optimized exception handling mechanisms, and the performance impact is generally negligible in most scenarios. It is important to use exceptions judiciously and limit their usage to exceptional error conditions rather than for regular control flow.

Q: Can we nest try-catch blocks? A: Yes, try-catch blocks can be nested within each other. This allows for more fine-grained exception handling, where inner try-catch blocks handle exceptions specific to their scope, while outer try-catch blocks handle more general exceptions. However, nesting try-catch blocks should be done thoughtfully to avoid unnecessary complexity and ensure clarity in exception handling logic.

Conclusion
Exception handling is a powerful mechanism in C++ that enables us to gracefully handle exceptional situations and prevent our programs from abruptly terminating or producing incorrect results. By using try-catch blocks, we can catch and handle exceptions, providing alternative code paths, error messages, or recovery options.

In this article, we explored the basics of exception handling in C++, including the try-catch block, handling multiple exception types, creating custom exception classes, and best practices for exception handling. We also discussed frequently asked questions related to exception handling to provide a comprehensive understanding of the topic.

By understanding and effectively using exception handling in our C++ programs, we can write more robust and reliable code that handles errors and exceptional situations in a controlled and structured manner.

Q: Can we nest try-catch blocks? A: Yes, try-catch blocks can be nested within each other. This allows for more fine-grained exception handling, where inner try-catch blocks handle exceptions specific to their scope, while outer try-catch blocks handle more general exceptions. However, nesting try-catch blocks should be done thoughtfully to avoid unnecessary complexity and ensure clarity in exception handling logic.

Conclusion
Exception handling is a powerful mechanism in C++ that enables us to gracefully handle exceptional situations and prevent our programs from abruptly terminating or producing incorrect results. By using try-catch blocks, we can catch and handle exceptions, providing alternative code paths, error messages, or recovery options.

In this article, we explored the basics of exception handling in C++, including the try-catch block, handling multiple exception types, creating custom exception classes, and best practices for exception handling. We also discussed frequently asked questions related to exception handling to provide a comprehensive understanding of the topic.

By understanding and effectively using exception handling in our C++ programs, we can write more robust and reliable code that handles errors and exceptional situations in a controlled and structured manner.

*/

#endif
