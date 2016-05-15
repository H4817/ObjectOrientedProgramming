#pragma once

#include <iostream>

class CUrlParsingError : public std::invalid_argument
{
public:
    CUrlParsingError(std::string invalidArgument);
private:
    std::string m_invalidArgument;
};
