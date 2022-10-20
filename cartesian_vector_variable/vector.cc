#include <ostream>
#include <memory>

#include "vector.hh"

Vector::Vector(const Vector& rhs)
    : N(rhs.N)
    , data(new value[N])
{
    for (size_t i = 0; i < N; ++i)
        {
            data[i] = rhs.data[i];
        }
}

Vector& Vector::operator=(const Vector& rhs)
{
    if (this != &rhs)
        {
            N = rhs.N;
            data.reset(new value[N]);
            for (size_t i = 0; i < N; ++i)
                {
                    data[i] = rhs.data[i];
                }
        }
    return *this;
}

Vector::Vector(size_t N) : N(N), data(new value[N]) {
    for (size_t i = 0; i < N; ++i)
        {
            data[i] = 0;
        }
}

Vector::Vector(std::initializer_list<value> l) : N(l.size()), data(new value[N]) {
    size_t i = 0;
    for (auto& v : l)
        {
            data[i++] = v;
        }
}

size_t Vector::size() const {
    return N;
}

Vector& Vector::operator+=(const Vector& rhs) {
    assert(N == rhs.N);
    for (size_t i = 0; i < N; ++i)
        {
            data[i] += rhs.data[i];
        }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    assert(N == rhs.N);
    for (size_t i = 0; i < N; ++i)
        {
            data[i] -= rhs.data[i];
        }
    return *this;
}

Vector& Vector::operator+=(value v) {
    for (size_t i = 0; i < N; ++i)
        {
            data[i] += v;
        }
    return *this;
}

Vector& Vector::operator*=(value v) {
    for (size_t i = 0; i < N; ++i)
        {
            data[i] *= v;
        }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
    Vector result(*this);
    result += rhs;
    return result;
}

Vector Vector::operator+(value v) const {
    Vector result(*this);
    result += v;
    return result;
}

value Vector::operator*(const Vector& rhs) const {
    assert(N == rhs.N);
    value result = 0;
    for (size_t i = 0; i < N; ++i)
        {
            result += data[i] * rhs.data[i];
        }
    return result;
}

Vector Vector::operator*(value v) const {
    Vector result(*this);
    result *= v;
    return result;
}

value& Vector::operator[](size_t idx) {
    assert(idx < N);
    return data[idx];
}

value Vector::operator[](size_t idx) const {
    assert(idx < N);
    return data[idx];
}

Vector operator*(const value& s, const Vector& v) {
    return v * s;
}

Vector operator+(const value& s, const Vector& v) {
    return v + s;
}

std::ostream& operator<<(std::ostream& o, const Vector& v) {
    o << "{";
    for (size_t i = 0; i < v.size(); ++i)
        {
            o << v[i];
            if (i != v.size() - 1)
                {
                    o << ",";
                }
        }
    o << "}";
    return o;
}
