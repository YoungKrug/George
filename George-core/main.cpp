#include<string>
#include<lua.hpp>
#include<luaconf.h>
#include<vector>
#include"Source/Lua/LuaScript.h"
#include"Source/Graphics/windows.h"
#include"Source/Vectors/maths.h"
// Vectors is for maths as well
// you can only create a namepace in a header file btw
int sum(int x, int y);
static int l_sum(lua_State* L);
void write(const char* str);
int getIntField(lua_State* L, const char* key);
void LuaMain(); // The Lua Functions that run side by side
static int l_write(lua_State* L);
	//template<typename T>
int main()
{// Get lua working tommorrow!!!!!!!!!!!!!! LUA IS WORKING// NOW you have to allow lua and call c++ functions <- soon
	using namespace george;
	using namespace graphics;
	using namespace maths;

	lua_State* L = luaL_newstate();
	luaL_openlibs(L); // load default Lua libs
	LuaScript test("test.lua");
	if (luaL_loadfile(L, test.GetPath().c_str())) {
		std::cout << "Error loading script" << std::endl;
	}
	lua_pushcfunction(L, l_write);
	lua_setglobal(L, "write"); // this is how function will be named in Lua
	lua_pcall(L, 0, 0, 0);
	// run script


	LuaScript vectorInfo("LuaTables.lua");
	std::vector<std::string> ac = vectorInfo.getTableKeys("arr");
	LuaScript windowSize("windowInformation.lua");
	LuaScript playerScript("PlayerScript.lua");
	int width = windowSize.get<int>("windowL.width"); // Lua convention for getting information
	int height = windowSize.get<int>("windowL.height");
	Window window("George!", height, width);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	//std::cout << glGetString(GL_VERSION) << std::endl;
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);
	vec4 c = a * b;

	mat4 position = mat4::Translation(vec3(2, 3, 4));
	position *= mat4::Identity();
	// c will be equal to a in this case...
	// we can actually add them together becasue of the plus operator, crazy
	// he made the function a reference type because we can just constantly do stuff like this etc.
	float up = playerScript.get<float>("Player.startSpeed");
	float right = playerScript.get<float>("Player.startSpeed");
	float speed = playerScript.get<float>("Player.speed");
	while (!window.Closed())
	{

		window.Clear();
		if (window.isKeyPressed(GLFW_KEY_A))//<- to figure out if key is pressed
		{
			 up += -speed;
		}
		if (window.isKeyPressed(GLFW_KEY_D))//<- to figure out if key is pressed
		{
			up += speed;
		}
		if (window.isKeyPressed(GLFW_KEY_W))//<- to figure out if key is pressed
		{
			right += speed;
		}
		if (window.isKeyPressed(GLFW_KEY_S))//<- to figure out if key is pressed
		{
			right += -speed;
		}
		

		//std::cout << c << std::endl;

#if 1
		//std::cout << window.getWidth() << "  " << window.getHeight() << std::endl;

		glBegin(GL_POLYGON);
		glVertex2f(-0.5f + up, -0.5f + right);
		glVertex2f(-0.5f + up, 0.5f + right);
		glVertex2f(0.5f + up, 0.5f + right);
		glVertex2f(0.5f + up, -0.5f + right); // Basic movement with graphics didnt even think about it until I did it by accident lol
		glEnd();

#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);

#endif
		window.Update();

	}

	//system("Pause");
	return 0;

}

void LuaMain()
{

}

static int l_write(lua_State* L) {
	const char* str = lua_tostring(L, 1); // get function argument
	write(str); // calling C++ function with this argument...
	return 0; // nothing to return!
}
int getIntField(lua_State* L, const char* key)
{
	lua_pushstring(L, key);
	lua_gettable(L, -2);  // get table[key]

	int result = (int)lua_tonumber(L, -1);
	lua_pop(L, 1);  // remove number from stack
	return result;
}
void write(const char* str) {
	std::cout << str << std::endl;
}

//Examples
int sum(int x, int y) {
	return x + y;
}

static int l_sum(lua_State* L) {
	int x = lua_tonumber(L, 1);
	int y = lua_tonumber(L, 2); // get function arguments
	lua_pushnumber(L, sum(x, y)); // push the result of a call
	return 1; // we're returning one result
}
