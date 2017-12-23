
#include"Source/Graphics/windows.h"

int main()
{
	using namespace george;
	using namespace graphics;

	Window window("George!", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	std::cout << glGetString(GL_VERSION) << std::endl;
	while (!window.Closed())
	{
		std::cout << window.getWidth() << "  " << window.getHeight() << std::endl;
		window.Clear();
		glBegin(GL_QUADS);
		glVertex2f( -0.5f, -0.5f);
		glVertex2f( -0.5f,  0.5f);
		glVertex2f(  0.5f,  0.5f);
		glVertex2f(  0.5f, -0.5f);
		glEnd();
		window.Update();
	}
	
	//system("Pause");
	return 0;

}