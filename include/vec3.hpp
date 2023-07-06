#ifndef VEC3_H
#define VEC3_H

#include <array>
#include <cmath>
#include <iostream>
#include <stdexcept>

/**
 * A basic three-dimensional vector class.
 * Supports most of the simple vector concepts taught in a standard undergraduate linear algebra class.
 * Employs object-oriented programming concepts.
 */
class vec3
{
private:
    std::array<double, 3> e;    // The 3D vector is implemented as an array of 3 doubles.
public:
    /**
     * Initializes the vector of 0 length at the origin.
     */
    vec3()
    {
        e[0] = e[1] = e[2] = 0.0;
    }
    /**
     * @param x component in the x-direction
     * @param y component in the y-direction
     * @param z component in the z-direction
     */
    vec3(const double x, const double y, const double z)
    {
        e[0] = x;
        e[1] = y;
        e[2] = z;
    }

    /// Accessors
    /**
     * @returns the x-component of the vector
     */
    double x() const { return e[0]; }
    /**
     * @returns the y-component of the vector
     */
    double y() const { return e[1]; }
    /**
     * @returns the z-component of the vector
     */
    double z() const { return e[2]; }

    /// Mutators
    /**
     * @param x the new x-component to be set
     */
    void newX(const double x) { e[0] = x; }
    /**
     * @param y the new x-component to be set
     */
    void newY(const double y) { e[1] = y; }
    /**
     * @param z the new x-component to be set
     */
    void newZ(const double z) { e[2] = z; }

    /**
     * @returns a vector with all components negated
     */
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

    /**
     * Index-based vector accessor
     * @param i index of the vector to be accessed (must be 0, 1, or 2)
     * @returns the vector component at index i
     * @throws Index out of bounds error if i is not 0, 1, or 2
     */
    double operator[](unsigned int i) const 
    { 
        if (i > 2)
            throw std::invalid_argument("Index out of bounds: vector index must be 0, 1, or 2!");
        
        return e[i];
    }
    /**
     * Index-based vector accessor
     * @param i index of the vector to be accessed (must be 0, 1, or 2)
     * @returns the vector component at index i
     * @throws Index out of bounds error if i is not 0, 1, or 2
     */
    double& operator[](unsigned int i)
    {
        if (i > 2)
            throw std::invalid_argument("Indexing out of bounds: vector index must be 0, 1, or 2!");
        
        return e[i];
    }

    /**
     * Vector sum shorthand
     * @param v the vector to be added to this vector
     * @returns the vector sum of this vector and vector v
     */
    vec3& operator+=(const vec3 &v)
    {
        this->e[0] += v.x();
        this->e[1] += v.y();
        this->e[2] += v.z();
        return *this;
    }

    /**
     * Scalar-vector product shorthand
     * @param t the scalar to be multiplied with this vector
     * @returns the product of this vector and scalar t
     */
    vec3& operator*=(const double t)
    {
        this->e[0] *= t;
        this->e[1] *= t;
        this->e[2] *= t;
        return *this;
    }

    /**
     * Vector-scalar division shorthand
     * @param t the scalar to divide this vector
     * @returns a vector whose components are the components of this vector divided by t
     */
    vec3& operator/=(const double t)
    {
        return *this *= 1 / t;
    }

    /**
     * Overloaded insertion operator to aid with displaying this vector to stdout
     */
    friend std::ostream& operator<<(std::ostream &out, const vec3 &v)
    {
        return out << '[' << v.x() << ", " << v.y() << ", " << v.z() << ']';
    }

    /**
     * Vector sum operator
     * @param v the vector to be added to this vector
     * @returns the vector sum of this vector and vector v
     */
    vec3 operator+(const vec3 &v)
    {
        return vec3(this->x() + v.x(), this->y() + v.y(), this->z() + v.z());
    }

    /**
     * Vector difference operator
     * @param v the vector to be subtracted from this vector
     * @returns the vector difference of this vector and vector v
     */
    vec3 operator-(const vec3 &v)
    {
        return vec3(this->x() - v.x(), this->y() - v.y(), this->z() - v.z());
    }

    /**
     * Hadamard/elementwise product operator
     * @param v the vector to be multiplied elementwise to the corresponding elements of this vector
     * @returns the hadamard product of this this vector and vector v
     */
    vec3 operator*(const vec3 &v)
    {
        return vec3(this->x() * v.x(), this->y() * v.y(), this->z() * v.z());
    }

    vec3 operator/(const double t)
    {
        return vec3(this->x() / t, this->y() / t, this->z() / t);
    }

    /**
     * Vector dot product
     * @param v the vector with whom this vector has to be "dotted" with
     * @returns the scalar dot product of this and vector v
     */
    double dot(const vec3 &v)
    {
        return (this->x() * v.x()) + (this->y() * v.y()) + (this->z() * v.z());
    }

    /**
     * Vector cross product
     * @param v the vector with whom this vector has to be "crossed" with
     * @returns the vector cross product of this and vector v
     */
    vec3 cross(const vec3 &v)
    {
        return vec3((this->y() * v.z()) - (this->z() * v.y()),
                    (this->z() * v.x()) - (this->x() * v.z()),
                    (this->x() * v.y()) - (this->y() * v.x()));
    }

    /**
     * unit vector is a vector of length 1 that is aligned in the direction of this vector
     * @returns the unit vector of this vector
     */
    vec3 unit_vector()
    {
        return *this / this->length();
    }

    /**
     * Calculates the euclidean length of this vector
     * @returns the scalar distance between the "head" of this vector and the "tail"
     */
    double length() const
    {
        return sqrt(length_squared());
    }

    /**
     * Calculates the square of the vector's euclidean length
     * @returns the square of the scalar distance between the "head" of this vector and the "tail"
     */
    double length_squared() const
    {
        return (x() * x()) + (y() * y()) + (z() * z()); 
    }
};

inline vec3 operator*(const double t, const vec3 &v)
{
    return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3 &v, const double t)
{
    return t * v;
}

// Aliases
using point3 = vec3;    // For a 3D point
using color = vec3;     // For RGB color

#endif  // VEC3_H