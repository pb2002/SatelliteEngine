#pragma once
#include "Event.h"

namespace Satellite {

	class SATELLITE_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int getWidth() const { return m_Width; }
		inline unsigned int getHeight() const { return m_Height; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[WindowResizeEvent: " << m_Width << ", " << m_Height << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(windowResize);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	private:
		unsigned int m_Width, m_Height;
	};

	class SATELLITE_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(windowClose);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
			std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[WindowCloseEvent]";
			return ss.str();
		}
	};

	class SATELLITE_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(appTick);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	};

	class SATELLITE_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(appUpdate);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	};

	class SATELLITE_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(appRender);
		EVENT_CLASS_CATEGORY(eventCategoryApplication);
	};
}