#pragma once

#include "IPerson.h"
#include "PersonImpl.h"

class CPerson : public CPersonImpl<IPerson>
{ };


