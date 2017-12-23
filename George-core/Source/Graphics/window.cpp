#include "windows.h"
// name spaces , learn they seem so cool
namespace george
{
	
	namespace graphics
	{
		void WindowResize(GLFWwindow  *window, int width, int height);
		Window::Window(const char*title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!Init())
			{
				glfwTerminate();

			}
		}
		Window::~Window()
		{
			glfwTerminate();

		}
		// that is how we refresh the window
		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		}
		void Window::Update()
		{
			glfwPollEvents();
			// will allow for window resize
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			// That Grabs the current width and height and allows for resizes
			
			glfwSwapBuffers(m_Window);

		}
		// How we initialize the window
		 bool Window::Init()
		{
			 // checks to make sure the window did not fail
			 if (!glfwInit())
			 {
				std::cout << "Faled to Initialize GLFW!" << std::endl;
				return 0;
			 }
			
			 m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			 if (!m_Window)
			 {
				 glfwTerminate();
				 std::cout << "Failed to create window" << std::endl;
				 return 0;
			 }
			 glfwMakeContextCurrent(m_Window);			 
			 glfwSetWindowSizeCallback(m_Window,WindowResize);
			 return 1;
		}
		 // how we close the window
		 bool Window::Closed() const
		 {
			 return glfwWindowShouldClose(m_Window) == 1;

		 }
	
		 void WindowResize(GLFWwindow  *window, int width, int height)
		 {
			 glViewport(0, 0, width, height);

		 }
	}

}