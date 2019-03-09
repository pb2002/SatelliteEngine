#pragma once

#include "Event.h"

namespace Satellite {

	// KeyEvent definition
	class SATELLITE_API KeyEvent : public Event {
	public:
		// returns m_KeyCode (protected member)
		inline int getKeyCode() const { return m_KeyCode; }

		// Event Category macro (see Event.h for definition)
		EVENT_CLASS_CATEGORY(eventCategoryKeyboard | eventCategoryInput);
	protected:
		// Constructor .............
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}
		// .........................
		int m_KeyCode;
	};

	class SATELLITE_API KeyDownEvent : public KeyEvent {
	public:
		// Constructor .......................................
		KeyDownEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		// ...................................................

		// returns m_RepeatCount (private member)
		inline int getRepeatCount() const { return m_RepeatCount; }
	
		// returns string representation of KeyDownEvent: "EVENT[KeyDownEvent: <m_KeyCode> (<m_RepeatCount> repeats)]"
		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[KeyDownEvent:" << m_KeyCode << "(" << m_RepeatCount << " repeats)]";
			return ss.str();
		}

		// Event Type macro (see Event.h for definition)
		EVENT_CLASS_TYPE(keyDown);
	private:
		int m_RepeatCount;
	};

	class SATELLITE_API KeyTypedEvent : public KeyEvent {
	public:
		// Constructor .......................................
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}
		// ...................................................

		// returns string representation of KeyTypedEvent: "EVENT[KeyTypedEvent: <m_KeyCode>]"
		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[KeyTypedEvent:" << m_KeyCode << "]";
			return ss.str();
		}

		// Event Type macro (see Event.h for definition)
		EVENT_CLASS_TYPE(keyTyped);
	};

	class SATELLITE_API KeyUpEvent : public KeyEvent {
	public:
		// Constructor ............
		KeyUpEvent(int keycode)
			: KeyEvent(keycode) {}
		// ........................
		// returns string representation of KeyUpEvent: "EVENT[KeyUpEvent: <m_KeyCode>]"
		std::string toString() const override {
			std::stringstream ss;
			ss << "EVENT[KeyUpEvent: " << m_KeyCode << "]";
			return ss.str();
		}

		// Event Type macro (see Event.h for definition)
		EVENT_CLASS_TYPE(keyUp);
	};
}