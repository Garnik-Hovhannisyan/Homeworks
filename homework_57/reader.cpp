#include <iostream>
#include <string>

#include "reader.h"

Reader::Reader(const std::string& name)
{
    m_file.open(name);
}

std::string Reader::read()
{
    std::string str;

    if (m_file.is_open())
    {
        std::getline(m_file, str);
    }
    return str;
}

Reader::~Reader()
{
    m_file.close();
}