#ifndef LAMBDA_H
#define LAMBDA_H

/** A C++ lambda expression, at its core, results in the creation of a function object, also known as a closure.
 *  While it might appear to "return a value" in the conventional sense when used within a function, what's actually happening is
 *  the function object's operator() is being invoked, and the result of that invocation is being returned.
 *
 * A lambda expression is syntactic sugar for defining an anonymous function object. When you define a lambda,
 * the compiler generates a class with an operator(). This operator() contains the code you wrote in the lambda body.
 * When the lambda is "called," it's actually this operator() that gets executed. If the lambda has a return statement, the value
 * returned by that statement becomes the result of the operator() call.
*/


#endif // LAMBDA_H
