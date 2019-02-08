#include "satpch.h"
#include "windowsWindow.h"

#include "Satellite/events/appEvent.h"
#include "Satellite/events/keyEvent.h"
#include "Satellite/events/mouseEvent.h"



namespace Satellite {
	
	static bool s_GLFWInitialized = false;
	
	static void glfwErrorCallback(int error, const char* description) {
		SAT_CORE_ERROR("(at {0}) GLFW ERROR[1]: {2}", __FUNCTION__, error, description);

	}

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
			glfwSetErrorCallback(glfwErrorCallback);
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
		if (!m_Window) {
			SAT_CORE_CRIT("(at {0}) Failed to create window: m_Window was null.", __FUNCTION__);
		}
		
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;
			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.eventCallback(event);
		});
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			switch (action) {
				case GLFW_PRESS: {
					KeyDownEvent event(key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE: {
					KeyUpEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT: {
					KeyDownEvent event(key, 1);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action) {
				case GLFW_PRESS: {
					MouseButtonDownEvent event(button);
					data.eventCallback(event);
					break;
				}				
				case GLFW_RELEASE: {
					MouseButtonUpEvent event(button);
					data.eventCallback(event);
					break;
				}
			}

		});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			
			MouseScrolledEvent event((float)xoffset, (float)yoffset);
			data.eventCallback(event);
		});
		
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event(xpos,ypos);
			data.eventCallback(event);
		});
	}
	// ----------------------------------------------------------
	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_Window);
	}
}
