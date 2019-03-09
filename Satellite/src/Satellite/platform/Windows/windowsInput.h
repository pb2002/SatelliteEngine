#pragma once

#include "Satellite/input.h"

namespace Satellite {
	class WindowsInput : public Input {
	protected:
		virtual bool isKeyDownImpl(int keycode) override;

		virtual bool isMouseButtonDownImpl(int keycode) override;
		virtual std::pair<float, float> getMousePosImpl() override;
		virtual float getMouseXImpl() override;
		virtual float getMouseYImpl() override;
	};
}