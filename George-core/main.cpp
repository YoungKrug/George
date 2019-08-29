#include <lua.hpp>
#include<luaconf.h>
#include"Source/Graphics/windows.h"
#include"Source/Vectors/maths.h"

// Vectors is for maths as well
// you can only create a namepace in a header file btw
int getIntField(lua_State* L, const char* key);
int main()
{
	using namespace george;
	using namespace graphics;
	using namespace maths;

	lua_State*L = luaL_newstate();
	lua_register(L, "Howdy", Howdy);
	luaL_openlibs(L);
	luaL_loadfile(L, "GrabInputTest.lua");
	lua_pcall(L, 0, 1, 0);
	int width = getIntField(L, "width");
	int height = getIntField(L, "height");
	Window window("George!", height, width);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	//std::cout << glGetString(GL_VERSION) << std::endl;
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vec4 a(0.2f,0.3f,0.8f,1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);
	vec3 triangle(-0.3f, -0.1f, 0.5f);
	vec4 c = a * b;
	
	// c will be equal to a in this case...
	// we can actually add them together becasue of the plus operator, crazy
	//Text on window
	std::string test = "Testing";
	//int w = 
	

	// he made the function a reference type because we can just constantly do stuff like this etc.


		while (!window.Closed())
	{
		window.Clear();
		
		//std::cout << c << std::endl;
		
#if 1
		//std::cout << window.getWidth() << "  " << window.getHeight() << std::endl;
		
		
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f( -0.5f, -0.5f, 0.3f);
		glVertex3f( -0.5f,  0.5f, 0.2f);
		glVertex3f(  0.5f,  0.5f, 0.3f);
		glVertex3f(0.5f, -0.5f, 0.2f);
		glEnd();
		
#else 
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0, 0); // Wonder why its still 2d
		
#endif
		window.Update();

	}
	
	//system("Pause");
	return 0;

}
int getIntField(lua_State* L, const char* key)
{
	lua_pushstring(L, key);
	lua_gettable(L, -2);  // get table[key]

	int result = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);  // remove number from stack
	return result;
}
int Howdy(lua_State* L)
{
	int args = lua_gettop(L);
	std::cout << "Howdy was called with " << args << " arguements";
	lua_pushnumber(L, 123);
}