#pragma once

#include <Satellite/core.h>




namespace Satellite {
	class SATELLITE_API Input {
	public:
		inline static bool isKeyDown(int keycode) { return s_Instance->isKeyDownImpl(keycode); }
		
		inline static bool isMouseButtonDown(int button) { return s_Instance->isMouseButtonDownImpl(button); }
		inline static std::pair<float, float> GetMousePos() { return s_Instance->getMousePosImpl(); }
		inline static float GetMouseX() { return s_Instance->getMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->getMouseYImpl(); }
	protected:
		virtual bool isKeyDownImpl(int keycode) = 0;

		virtual bool isMouseButtonDownImpl(int keycode) = 0;
		virtual std::pair<float, float> getMousePosImpl() = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
		
	private:
		static Input* s_Instance;

	};
}