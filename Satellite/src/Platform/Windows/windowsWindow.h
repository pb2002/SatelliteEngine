#pragma once

#include "Satellite/window.h"

#include <GLFW/glfw3.h>

class WindowsWindow : public Window {
public:
	WindowsWindow();
	virtual ~WindowsWindow();
	
	void onUpdate() override;

	inline
};

