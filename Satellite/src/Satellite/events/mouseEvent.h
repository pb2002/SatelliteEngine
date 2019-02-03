#pragma once
#include "Event.h"

namespace Satellite {

	class SATELLITE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float getX() const { return m_MouseX; }
		inline float getY() const { return m_MouseY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[MouseMovedEvent: " << m_MouseX << ", " << m_MouseY << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseMoved);
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput);
	private:
		float m_MouseX, m_MouseY;
	};

	class SATELLITE_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {}

		inline float getXOffset() const { return m_XOffset; }
		inline float getYOffset() const { return m_YOffset; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[MouseScrolledEvent: " << getXOffset() << ", " << getYOffset() << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseScrolled);
		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput);
	private:
		float m_XOffset, m_YOffset;
	};

	class SATELLITE_API MouseButtonEvent : public Event {
	public:
		inline int getMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(eventCategoryMouse | eventCategoryInput);
	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class SATELLITE_API MouseButtonDownEvent : public MouseButtonEvent {
	public:
		MouseButtonDownEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[MouseButtonDownEvent: " << m_Button << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseButtonDown);
	};

	class SATELLITE_API MouseButtonUpEvent : public MouseButtonEvent {
	public:
		MouseButtonUpEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[MouseButtonUpEvent: " << m_Button << "]";
			return ss.str();
		}

		EVENT_CLASS_TYPE(mouseButtonUp);
	};

}