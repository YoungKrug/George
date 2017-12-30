#pragma once
#include <iostream>
namespace george
{
	namespace maths 
	{

		// making the struct name lowercase to collide well with glfw
		// FUNCTION OVERLOADERS!!!
		struct vec2
		{
			float x, y;
			vec2();
			vec2(const float&x, const float& y);

			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);
			// FUNCTION OVERLOADERS!!! LEARN
			// allows for adding vectors with the + operator.. im asumming it is called when you are adding them
			friend vec2 operator+(vec2 left, const vec2 right);
			friend vec2 operator*(vec2 left, const vec2 right);
			friend vec2 operator/(vec2 left, const vec2 right);
			friend vec2 operator-(vec2 left, const vec2 right);
			
			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);
			// if we want to use += instead of a= a+b;
			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			
			
			// we can basically change how operators function
			// such as changing the + operator to add to variables kinda.
			friend std::ostream& operator << (std::ostream&, const vec2& vector);
		};
		 





	}
}

