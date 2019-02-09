#pragma once

#include "Satellite/window.h"

#include <GLFW/glfw3.h>

namespace Satellite {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { 
			return m_Data.width; 
		}
		inline unsigned int getHeight() const override { 
			return m_Data.height; 
		}

		inline void setEventCallback(const EventCallbackFn& callback) override { 
			m_Data.eventCallback = callback; 
		}
		void setVSync(bool enabled) override;
		inline bool isVSync() const override {
			return m_Data.vSync;
		}
	private:
		virtual void init(const WindowProperties& props);
		virtual void shutdown();
	private:
		GLFWwindow* m_Window;
		
		struct WindowData {
			std::string title;
			unsigned int width;
			unsigned int height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_Data;
	};
}


