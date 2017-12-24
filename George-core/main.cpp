#include <lua.hpp>
#include<luaconf.h>
#include"Source/Graphics/windows.h"
int getIntField(lua_State* L, const char* key);
int main()
{
	using namespace george;
	using namespace graphics;
	lua_State*L = luaL_newstate();
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
	

		while (!window.Closed())
	{
		window.Clear();
		double x, y;
		window.getMousePosition(x, y);
		std::cout << x <<", " << y <<  std::endl;
		
#if 1
		//std::cout << window.getWidth() << "  " << window.getHeight() << std::endl;
		
		glBegin(GL_QUADS);
		glVertex2f( -0.5f, -0.5f);
		glVertex2f( -0.5f,  0.5f);
		glVertex2f(  0.5f,  0.5f);
		glVertex2f(  0.5f, -0.5f);
		glEnd();
#else 
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
		
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