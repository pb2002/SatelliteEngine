#pragma once
#include "Satellite/layer.h"

#include "Satellite/events/event.h"
#include "Satellite/events/mouseEvent.h"
#include "Satellite/events/appEvent.h"
#include "Satellite/events/keyEvent.h"

namespace Satellite {
	class SATELLITE_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void onAttach();
		void onDetach();
		void onUpdate();
		void onEvent(Event& event);
	private:
		bool onMouseButtonDownEvent(MouseButtonDownEvent& e);
		bool onMouseButtonUpEvent(MouseButtonUpEvent& e);
		bool onMouseMovedEvent(MouseMovedEvent& e);
		bool onMouseScrolledEvent(MouseScrolledEvent& e);
		bool onKeyDownEvent(KeyDownEvent& e);
		bool onKeyTypedEvent(KeyTypedEvent& e);
		bool onKeyUpEvent(KeyUpEvent& e);
		bool onWindowResizeEvent(WindowResizeEvent& e);
	private:
		float m_Time = 0;
	};
}