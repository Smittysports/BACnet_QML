/** \file Optional.h
 *
 *  The std::optional class template was introduced in C++17. It is a container that represents an optional value.
 *  It can be either a value of type T or empty, indicating the absence of a value.
 */

#pragma once

#include <optional>
#include <string>

class Name
{
public:
    Name(const std::string& first, const std::optional<std::string> middle, const std::string last) :
        m_first {first}, m_middle {middle}, m_last {last}
    {}

    Name(const std::string& first, const std::string last) :
        m_first {first}, m_last {last}
    {}

    std::string getName()
    {
        if (m_middle.has_value())
            return std::string(m_first + " " + m_middle.value() + " " + m_last);
        else
            return std::string(m_first + " " + m_last);
    }

    private:
        std::string m_first;
        std::optional<std::string> m_middle;
        std::string m_last;
};

