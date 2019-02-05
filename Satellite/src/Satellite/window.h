#pragma once

#include "satpch.h"

#include "Satellite/core.h"
#include "Satellite/events/event.h"

namespace Satellite {

	// STRUCT: WindowProperties
	// ======================================
	// Contains all properties of a Window 
	// object.
	struct WindowProperties {

		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(const std::string& title = "Satellite Engine",
					unsigned int width = 1280,
					unsigned int height = 720) 
			: title(title), width(width), height(height) {

		}
	};
	
	// CLASS: Window
	// ======================================
	// Window object from which other classes 
	// derive to allow for platform specific 
	// window types.
	class SATELLITE_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0; // called every update

		virtual unsigned int getWidth() const = 0; // returns window width
		virtual unsigned int getHeight() const = 0; // returns window height

		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0; // enable or disable VSync
		virtual bool isVSync() const = 0; // check VSync enable state.
		static Window* create(const WindowProperties& props = WindowProperties());
	};
}