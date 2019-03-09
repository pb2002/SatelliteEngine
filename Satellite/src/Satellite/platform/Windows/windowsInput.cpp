#include "satpch.h"
#include "windowsInput.h"

#include "Satellite/application.h"
#include <GLFW/glfw3.h>

namespace Satellite {

	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::isKeyDownImpl(int keycode) {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetKey(window,keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::isMouseButtonDownImpl(int button) {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		auto state = glfwGetMouseButton(window, button);

		return state == GLFW_PRESS;
	}

	std::pair<float, float> WindowsInput::getMousePosImpl() {
		auto window = static_cast<GLFWwindow*>(Application::get().getWindow().getNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return { (float)x, (float)y };
	}

	float WindowsInput::getMouseXImpl() {
		return getMousePosImpl().first;
	}

	float WindowsInput::getMouseYImpl() {
		return getMousePosImpl().second;
	}


}