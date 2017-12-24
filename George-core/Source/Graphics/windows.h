#pragma once
#include<iostream>
#include<GL\glew.h>
#include<GLFW\glfw3.h>

namespace george 
{
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
	namespace graphics
	{
		class Window
		{
		
			
		private :
			
			const char *m_Title;
			int m_Width;
			int m_Height;
			bool m_Closed;
			GLFWwindow *m_Window;
			// like unity, when keys get pressed we get a key code
			
			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BUTTONS];
			static double mx, my;
		public:
			Window(const char*title, int width, int height);
			~Window();
			bool Closed() const;
			void Update();
			void Clear() const;
			int getHeight() const
			{
				return m_Width;
			}
			int getWidth() const
			{
				return m_Height;
			}

		private:
			bool Init();
		

		};



	}




}
