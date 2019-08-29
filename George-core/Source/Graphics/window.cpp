#include "windows.h"
// name spaces , learn they seem so cool
namespace george
{
	
	namespace graphics
	{
		
		void window_resize(GLFWwindow  *window, int width, int height);
		Window::Window(const char*title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!Init())
			{
				glfwTerminate();
			}
			// Initialize  bool array
			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
			
		}
		Window::~Window()
		{
			glfwTerminate();

		}
		// checks for key inputs
		bool Window::isKeyPressed(unsigned int keyCode) const
		{
			//TODO LOG THIS
			if (keyCode >= MAX_KEYS)
				return false;
			return m_Keys[keyCode];
		}
		// checks for mouse inputs
		bool Window::isMouseButtonPressed(unsigned int button) const 
		{
			//TODO LOG THIS
			if (button >= MAX_BUTTONS)
				return false;
			return m_MouseButtons[button];
		}
		// checks for mouse postition
		void Window::getMousePosition(double& x, double& y) const
		{
			x = mx;
			y = my;
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
			// A call pack is a function pointer... crazy
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
			 // callbacks calls the functions and grabs information from them
			 glfwMakeContextCurrent(m_Window);			 
			 glfwSetWindowUserPointer(m_Window, this);
			 glfwSetWindowSizeCallback(m_Window,window_resize);
			 glfwSetKeyCallback(m_Window,key_callback);
			 glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			 glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			 // Do not do this before the glfw stuff
			 // has to be after
			 if (glewInit() != GLEW_OK)
			 {
				 std::cout << "Could Not Initialize GLEW!!" << std::endl;
				 return false;
			 }
			 std::cout << "OpenGl " << glGetString(GL_VERSION) << std::endl;




			 return 1;


		}
		 // how we close the window
		 bool Window::Closed() const
		 {
			 return glfwWindowShouldClose(m_Window) == 1;

		 }
	// new way to resize the window. Using a viewport
		 void window_resize(GLFWwindow  *window, int width, int height)
		 {
			 glViewport(0, 0, width, height);

		 }
		 void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		 {
			 Window* win = (Window*)glfwGetWindowUserPointer(window);
			 win->m_MouseButtons[button] = action != GLFW_RELEASE;

		 }
		 void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		 {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			
			win->m_Keys[key] = action != GLFW_RELEASE;
		 }
		 void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		 {
			 Window* win = (Window*)glfwGetWindowUserPointer(window);
			 win->mx = xpos;
			 win->my = ypos;
		 }
	}

}