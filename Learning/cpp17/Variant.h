#pragma once

#include <string>
#include <variant>

/** Visitor:
 *  The visitor pattern is a behavioral design pattern that separates an algorithm from the object structure on which it operates.
 *  It enables adding new operations to existing class hierarchies without modifying the classes themselves. A visitor class defines
 *  operations to perform on specific types of objects in the structure, and the object structure accepts a visitor to execute these
 *  operations. This pattern is useful when there are many distinct and unrelated operations to perform on objects in a hierarchy and
 *  when it's desirable to avoid modifying the classes of these objects.
 */

/** Callable
 * A visitor is a 'callable'.
 *
 * In C++, a callable is an entity that can be invoked using the function call syntax, i.e., parentheses (). Callables are a generalization
 * of functions and encompass several types of entities:
 * - Functions: Regular functions defined using the function keyword.
 * - Function Pointers: Pointers that store the memory address of a function, allowing it to be called indirectly.
 * - Lambda Expressions: Anonymous functions defined inline using the [] syntax.
 * - Functors (Function Objects): Objects of classes that overload the function call operator operator().
 * - Member Function Pointers: Pointers to member functions of a class, which can be invoked on objects of that class.
 * - std::function: A class template that can wrap any callable object, providing a unified way to store and invoke them.
 */

class VariantTest
{
public:
    VariantTest() = default;

    using myVariant = std::variant<int, float>;

    VariantTest(myVariant variantVal) : m_variant(variantVal) {}

    auto getVariant() {return m_variant;}

    /** This method will only accept an int or float as one of the template types.
      *
      * A bool will no longer allowed to be implicitly covnerted since we are using the std::enable_if
      * template metaprogramming utility.
      *
      * \param T newValue: The m_variant will be set to the newValue passed in.
      **/
    template<typename T>
    typename std::enable_if<std::is_same<T, int>::value || std::is_same<T, float>::value, void>::type
    setVariant(T newValue)
    {
        m_variant = newValue;
    }

    std::string getDocLink() {return "https://en.cppreference.com/w/cpp/utility/variant"; }
    std::string getVisitDocLink() {return "https://en.cppreference.com/w/cpp/utility/variant/visit2"; }

private:
    myVariant m_variant;
};
