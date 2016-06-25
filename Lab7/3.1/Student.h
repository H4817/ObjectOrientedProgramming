#pragma once

#include "StudentImpl.h"
#include "IStudent.h"

class CStudent : public CStudentImpl<IStudent>
{ };
