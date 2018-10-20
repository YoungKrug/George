#pragma once

#define _USE_MATH_DEFINES
#include <math.h>


namespace george
{
	namespace maths
	{
		//float toRadians(float degrees);
		//float toDegress(float radian);
		struct mat4 // Matrix Classes
		{
			float elements[4 * 4];

			mat4();
			mat4(float diagonal);
			static mat4 Identity(); // Identity Matrix
			mat4& Multiply(const mat4& other); // Going to be add and subtracting aswell
			friend mat4 operator*(mat4 left, const mat4& right); // Operation overloading
		    mat4& operator*=(const mat4& other);
			static mat4 Othographic(float left, float right, float bottom, float top, float near, float far);
			static mat4 Perspective(float fov, float aspectRatio, float near, float far);

			static mat4 Translation(const vec3& translation);
			static mat4 Rotation(float angle, const vec3& axis);
			static mat4 Scale(const vec3& scale);

		};
	}
}
