#pragma once

#include "rubykokuban/Mouse.hpp"
#include "rubykokuban/Touch.hpp"

//------------------------------------------------------------
namespace rubykokuban {
class Input {
public:
    Input();

    /// Update current value
    void update();

    /// @name Basic pad (stick & 1-4 button)
    //@{
    // float x() const;
    // float y() const;
    // bool isDown(int aCode) const;
    // bool isPress(int aCode) const;
    // bool isRelease(int aCode) const;
    //@}

    /// @name Mouse
    //@{
    Mouse& mouse() { return mMouse; }
    const Mouse& mouse() const { return mMouse; }
    //@}

    /// @name Touch
    //@{
    Touch& touch() { return mTouch; }
    const Touch& touch() const { return mTouch; }
    //@}

private:
    // BasicPad mBasicPad;
    Mouse    mMouse;
    // Keyboard mKeyboard;
    // Pad      mPad;
    Touch    mTouch;
};

}
