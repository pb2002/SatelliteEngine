#pragma once
#include "satpch.h"
#include "Satellite/core.h"

namespace Satellite {
#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
							   virtual EventType getEventType() const override { return getStaticType(); }\
							   virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	// Event Types:
	// ----------------------------------------------------------------------
	enum class EventType {
		none = 0,
		windowClose, windowResize, windowFocus, windowLostFocus, windowMoved,
		appTick, appUpdate, appRender,
		keyDown, keyUp, keyTyped,
		mouseButtonDown, mouseButtonUp, mouseMoved, mouseScrolled
	};
	// ----------------------------------------------------------------------
	// Event Catagories:
	// -----------------------------------
	enum EventCategory {
		none = 0,
		eventCategoryApplication = BIT(0),
		eventCategoryInput = BIT(1),
		eventCategoryKeyboard = BIT(2),
		eventCategoryMouse = BIT(3),
		eventCategoryMouseButton = BIT(4)
	};
	// -----------------------------------


	class SATELLITE_API Event {
	public:
		bool handled = false;

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return std::string(getName()); }

		inline bool IsInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}
	};
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		template<typename T>
		bool dispatch(EventFn<T> func) {
			if (m_Event.getEventType() == T::getStaticType()) {
				m_Event.handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.toString();
	}
}