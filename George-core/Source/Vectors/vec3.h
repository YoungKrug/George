#pragma once
#include <iostream>
namespace george
{
	namespace maths 
	{

		// making the struct name lowercase to collide well with glfw
		// FUNCTION OVERLOADERS!!!
		struct vec3
		{
			float x, y, z;
			vec3();
			vec3(const float&x, const float& y, const float&z);

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);
			// FUNCTION OVERLOADERS!!! LEARN
			// allows for adding vectors with the + operator.. im asumming it is called when you are adding them
			friend vec3 operator+(vec3 left, const vec3 right);
			friend vec3 operator*(vec3 left, const vec3 right);
			friend vec3 operator/(vec3 left, const vec3 right);
			friend vec3 operator-(vec3 left, const vec3 right);
			
			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);
			// if we want to use += instead of a= a+b;
			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			
			
			// we can basically change how operators function
			// such as changing the + operator to add to variables kinda.
			friend std::ostream& operator << (std::ostream&, const vec3& vector);
		};
		 





	}
}

