#pragma once

#include "IPerson.h"

class IWorker : public IPerson
{
protected:
    std::string profession;
};