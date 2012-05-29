/********************************************************************
	created:	2012/05/29
	created:	29:5:2012   23:33
	filename: 	D:\Work\visual studio 2010\Projects\binary_world\mylib\mylib.h
	file path:	D:\Work\visual studio 2010\Projects\binary_world\mylib
	file base:	mylib
	file ext:	h
	author:		Steve Tan
	
	purpose:	Lua module programming test dll dump.
*********************************************************************/

#ifdef MYLIB_EXPORTS
    #define MYLIB_API __declspec(dllexport)
#else
    #define MYLIB_API __declspec(dllimport)
#endif

struct lua_State;
MYLIB_API int luaopen_mylib(lua_State *L);
