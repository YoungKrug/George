#pragma once
#include<iostream>
#include<GLFW\glfw3.h>

namespace george 
{
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
