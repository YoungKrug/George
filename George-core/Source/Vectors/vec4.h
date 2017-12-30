#pragma once
#include <iostream>
namespace george
{
	namespace maths 
	{

		// making the struct name lowercase to collide well with glfw
		// FUNCTION OVERLOADERS!!!
		struct vec4
		{
			float x, y,z,w;
			vec4();
			vec4(const float&x, const float& y, const float& z, const float& w);

			vec4& add(const vec4& other);
			vec4& subtract(const vec4& other);
			vec4& multiply(const vec4& other);
			vec4& divide(const vec4& other);
			// FUNCTION OVERLOADERS!!! LEARN
			// allows for adding vectors with the + operator.. im asumming it is called when you are adding them
			friend vec4 operator+(vec4 left, const vec4 right);
			friend vec4 operator*(vec4 left, const vec4 right);
			friend vec4 operator/(vec4 left, const vec4 right);
			friend vec4 operator-(vec4 left, const vec4 right);
			
			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);
			// if we want to use += instead of a= a+b;
			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			
			
			// we can basically change how operators function
			// such as changing the + operator to add to variables kinda.
			friend std::ostream& operator << (std::ostream&, const vec4& vector);
		};
		 





	}
}

