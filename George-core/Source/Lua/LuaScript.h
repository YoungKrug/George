#pragma once
#ifndef LUASCRIPT_H
#define LUASCRIPT_H
#include<lua.hpp>
#include<luaconf.h>
#include<iostream>
#include<string>
#include<vector>
namespace george
{
	class LuaScript
	{
	public:
		///Lua Files have to be in the lua folder in order for this to work.
		///Change the path to your path inorder for this to work.
		LuaScript(const std::string& fileName)
		{
			L = luaL_newstate();
			luaL_openlibs(L);
			// Since all lua files will be in the lua folder, they have to be!
			std::string filePath = "C:/Users/Gregory/Documents/Visual Studio 2017/Projects/George/George-core/Source/Lua/" + fileName;
			if (luaL_loadfile(L, filePath.c_str()) || lua_pcall(L, 0, 1, 0)) {
				std::cout << "Error: script not loaded (" << fileName << ")" << std::endl;
				L = 0;
			}
			path = filePath;
		}
		~LuaScript()
		{
			if (L)
				lua_close(L);
		}
		void clean() {
			int n = lua_gettop(L);
			lua_pop(L, n);
		}
		std::vector<int> LuaScript::getIntVector(const std::string& name) {
			std::vector<int> v;
			lua_getglobal(L, name.c_str());
			if (lua_isnil(L, -1)) {
				return std::vector<int>();
			}
			lua_pushnil(L);
			while (lua_next(L, -2)) {
				v.push_back((int)lua_tonumber(L, -1));
				lua_pop(L, 1);
			}
			clean();
			return v;
		}
		std::string GetPath()
		{
			return path;
		}
		std::vector<std::string> getTableKeys(const std::string& name);
		//std::vector<int> getTableKeysInt(const std::string& name);
		void PrintError(const std::string& variableName, const std::string& reason);
		template<typename T>
		T get(const std::string& variableName)
		{
			if (!L)
			{
				PrintError(variableName, "Script is not loaded");
				return lua_getdefault<T>(variableName);
			}
			T result;
			if (lua_gettopstack(variableName))
			{
				result = lua_get<T>(variableName);
			}
			else
			{
				result = lua_getdefault<T>(variableName);
			}
			lua_pop(L, level + 1);
			return result;
		}
		bool lua_gettopstack(const std::string & variableName);
		//Generic get
		template <typename T>
		T lua_get(const std::string& variableName)
		{
			return 0;
		}
		template<typename T>
		T lua_getdefault(const std::string& variableName)
		{
			return 0;
		}
	private:
		lua_State * L;
		int level = 0;
		std::string path;
	};
	// Learn these, template specializations
	template <>
	inline std::string LuaScript::lua_getdefault<std::string>(const std::string& varName)
	{
		return "null";
	}
	template <>
	inline bool LuaScript::lua_get(const std::string& variableName) {
		return (bool)lua_toboolean(L, -1);
	}

	template <>
	inline float LuaScript::lua_get(const std::string& variableName) {
		if (!lua_isnumber(L, -1)) {
			PrintError(variableName, "Not a number");
		}
		return (float)lua_tonumber(L, -1);
	}

	template <>
	inline int LuaScript::lua_get(const std::string& variableName) {
		if (!lua_isnumber(L, -1)) {
			PrintError(variableName, "Not a number");
		}
		return (int)lua_tonumber(L, -1);
	}

	template <>
	inline std::string LuaScript::lua_get(const std::string& variableName) {
		std::string s = "null";
		if (lua_isstring(L, -1)) {
			s = std::string(lua_tostring(L, -1));
		}
		else {
			PrintError(variableName, "Not a string");
		}		
		return s;
	}
}
#endif
