#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

class ray
{
private:
    point3 start;   // Denotes the starting point of the ray, i.e., its origin
    vec3 direction; // Denotes the direction in which the ray travels in space

    /*
     * In the equation of a ray, P(t) = A + tb,
     * A is represented here as start,
     * b is represented as direction.
     */

public:
    ray() {}
    /**
     * Constructs a ray with an origin and a direction
     * @param _start the starting point
     * @param _dir the direction vector along which the ray is traveling
     */
    ray(const point3 &_start, const vec3 &_dir)
    {
        start = _start;
        direction = _dir;
    }

    /**
     * @returns the origin point of this ray
     */
    point3 origin() const { return start; }
    /**
     * @returns the direction vector along which this ray is traveling
     */
    vec3 dir() const { return direction; }

    /**
     * Finds a point from the ray equation P(t) = A + bt, where A is the starting point and b is the vector representing teh ray's direction of travel
     * @param t the parameter used to calculate the coordinates of the point on the ray
     * @return a point on the ray at parameter t
     */
    point3 at(const double t)
    {
        return start + (t * direction);
    }
};

#endif  // RAY_H 