#include "RenderWindow.h"

CEGUI::Key::Scan RenderWindow::convertKey(sf::Keyboard::Key& key)
{
    using namespace sf;
    switch(key) {
    case Keyboard::A:
        return CEGUI::Key::A;
    case Keyboard::B:
        return CEGUI::Key::B;
    case Keyboard::C:
        return CEGUI::Key::C;
    case Keyboard::D:
        return CEGUI::Key::D;
    case Keyboard::E:
        return CEGUI::Key::E;
    case Keyboard::F:
        return CEGUI::Key::F;
    case Keyboard::G:
        return CEGUI::Key::G;
    case Keyboard::H:
        return CEGUI::Key::H;
    case Keyboard::I:
        return CEGUI::Key::I;
    case Keyboard::J:
        return CEGUI::Key::J;
    case Keyboard::K:
        return CEGUI::Key::K;
    case Keyboard::L:
        return CEGUI::Key::L;
    case Keyboard::M:
        return CEGUI::Key::M;
    case Keyboard::N:
        return CEGUI::Key::N;
    case Keyboard::O:
        return CEGUI::Key::O;
    case Keyboard::P:
        return CEGUI::Key::P;
    case Keyboard::Q:
        return CEGUI::Key::Q;
    case Keyboard::R:
        return CEGUI::Key::R;
    case Keyboard::S:
        return CEGUI::Key::S;
    case Keyboard::T:
        return CEGUI::Key::T;
    case Keyboard::U:
        return CEGUI::Key::U;
    case Keyboard::V:
        return CEGUI::Key::V;
    case Keyboard::W:
        return CEGUI::Key::W;
    case Keyboard::X:
        return CEGUI::Key::X;
    case Keyboard::Y:
        return CEGUI::Key::Y;
    case Keyboard::Z:
        return CEGUI::Key::Z;
    case Keyboard::Return:
        return CEGUI::Key::Return;
    case Keyboard::Num0:
        return CEGUI::Key::Numpad0;
    case Keyboard::Num1:
        return CEGUI::Key::Numpad1;
    case Keyboard::Num2:
        return CEGUI::Key::Numpad2;
    case Keyboard::Num3:
        return CEGUI::Key::Numpad3;
    case Keyboard::Num4:
        return CEGUI::Key::Numpad4;
    case Keyboard::Num5:
        return CEGUI::Key::Numpad5;
    case Keyboard::BackSpace:
        return CEGUI::Key::Backspace;
    default:
        return CEGUI::Key::Unknown;
    }
};
