#include "satpch.h"
#include "windowsWindow.h"

namespace Satellite {
	
	static bool s_GLFWInitialized = false;

	Window* Window::create(const WindowProperties& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props) {
		init(props);
	}
	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		glfwSwapInterval(enabled ? 1 : 0);
		m_Data.vSync = enabled;
	}
	// GLFW WINDOW INIT
	// ----------------------------------------------------------
	void WindowsWindow::init(const WindowProperties & props) {
		m_Data.title = props.title;
		m_Data.width = props.width;
		m_Data.height = props.height;

		SAT_CORE_INFO("(at {0}) Creating window '{1}' [DIMENSIONS:\t{2}x{3}]", __FUNCTION__,
			m_Data.title, m_Data.width, m_Data.height);

		if (!s_GLFWInitialized) {
			int success = glfwInit();
			SAT_CORE_ASSERT(success, "(at {0}) Failed to initialize GLFW.", __FUNCTION__);
			
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
		if (!m_Window) {
			SAT_CORE_CRIT("(at {0}) Failed to create window: m_Window was null.", __FUNCTION__);
		}
		
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);
	}
	// ----------------------------------------------------------
	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_Window);
	}
}
