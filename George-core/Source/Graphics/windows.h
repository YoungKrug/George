#pragma once
#include<iostream>
#include<string>
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
			
			 bool m_Keys[MAX_KEYS];
			 bool m_MouseButtons[MAX_BUTTONS];
			 double mx, my;
		public:
			Window(const char*title, int width, int height);
			~Window();
			bool Closed() const;
			void Update();
			void Clear() const;
		    inline int getHeight() const
			{
				return m_Width;
			}
			inline int getWidth() const
			{
				return m_Height;
			}
			 bool isKeyPressed(unsigned int keyCode) const;
			 bool isMouseButtonPressed(unsigned int button)const;
			 void getMousePosition(double& x, double& y) const;
		private:
			bool Init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); 
			friend static void mouse_button_callback(GLFWwindow* window, int button,int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);



		};



	}




}
