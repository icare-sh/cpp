#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(/*args*/);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& rhs);
    // More to go

private:
// Private Member functions here (if necessary)

// Member variables are ALWAYS private, and they go here

};

// Nonmember function operators go here