#include "DisandriaFalconSAPI.h"

/* Bindings to Disandria C++ classes (or C++ functions) */
#include "dfsapi_GameManager.h"
#include "dfsapi_RenderWindow.h"
#include "dfsapi_DisandriaObjectShare.h"
#include "dfsapi_Input.h"

/* Bindings to SFML C++ classes (underlying library of Disandria) */
#include "dfsapi_sf_Music.h"
#include "dfsapi_sf_Sound.h"
#include "dfsapi_sf_SoundBuffer.h"
#include "dfsapi_sf_Keyboard.h"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/* Bindings to Thor C++ class (heavily used SFML extension) */
#include "dfsapi_thor_Action.h"
#include <Thor/Input.hpp>

Falcon::Module* DisandriaFalconSAPI::module = NULL;

Falcon::Module* DisandriaFalconSAPI::createBinding()
{
    if(module == NULL) {
        module = new Falcon::Module();
        module->name("DisandriaFalcon");
        addConstants(module);
        addMethods(module);
        addClasses(module);
        addSingletons(module);
    }
    return module;
}

void DisandriaFalconSAPI::addConstants(Falcon::Module* mod)
{
    /* sf::SoundSource::Status */
    mod->addConstant("sfSoundSourceStatusStopped", (Falcon::int64)sf::SoundSource::Stopped);
    mod->addConstant("sfSoundSourceStatusPlaying", (Falcon::int64)sf::SoundSource::Playing);
    mod->addConstant("sfSoundSourceStatusPaused", (Falcon::int64)sf::SoundSource::Paused);

    /* sf::Keyboard::Key */
    mod->addConstant("sfKeyboardKeyA", (Falcon::int64)sf::Keyboard::A);
    mod->addConstant("sfKeyboardKeyB", (Falcon::int64)sf::Keyboard::B);
    mod->addConstant("sfKeyboardKeyC", (Falcon::int64)sf::Keyboard::C);
    mod->addConstant("sfKeyboardKeyD", (Falcon::int64)sf::Keyboard::D);
    mod->addConstant("sfKeyboardKeyE", (Falcon::int64)sf::Keyboard::E);
    mod->addConstant("sfKeyboardKeyF", (Falcon::int64)sf::Keyboard::F);
    mod->addConstant("sfKeyboardKeyG", (Falcon::int64)sf::Keyboard::G);
    mod->addConstant("sfKeyboardKeyH", (Falcon::int64)sf::Keyboard::H);
    mod->addConstant("sfKeyboardKeyI", (Falcon::int64)sf::Keyboard::I);
    mod->addConstant("sfKeyboardKeyJ", (Falcon::int64)sf::Keyboard::J);
    mod->addConstant("sfKeyboardKeyK", (Falcon::int64)sf::Keyboard::K);
    mod->addConstant("sfKeyboardKeyL", (Falcon::int64)sf::Keyboard::L);
    mod->addConstant("sfKeyboardKeyM", (Falcon::int64)sf::Keyboard::M);
    mod->addConstant("sfKeyboardKeyN", (Falcon::int64)sf::Keyboard::N);
    mod->addConstant("sfKeyboardKeyO", (Falcon::int64)sf::Keyboard::O);
    mod->addConstant("sfKeyboardKeyP", (Falcon::int64)sf::Keyboard::P);
    mod->addConstant("sfKeyboardKeyQ", (Falcon::int64)sf::Keyboard::Q);
    mod->addConstant("sfKeyboardKeyR", (Falcon::int64)sf::Keyboard::R);
    mod->addConstant("sfKeyboardKeyS", (Falcon::int64)sf::Keyboard::S);
    mod->addConstant("sfKeyboardKeyT", (Falcon::int64)sf::Keyboard::T);
    mod->addConstant("sfKeyboardKeyU", (Falcon::int64)sf::Keyboard::U);
    mod->addConstant("sfKeyboardKeyV", (Falcon::int64)sf::Keyboard::V);
    mod->addConstant("sfKeyboardKeyW", (Falcon::int64)sf::Keyboard::W);
    mod->addConstant("sfKeyboardKeyX", (Falcon::int64)sf::Keyboard::X);
    mod->addConstant("sfKeyboardKeyY", (Falcon::int64)sf::Keyboard::Y);
    mod->addConstant("sfKeyboardKeyZ", (Falcon::int64)sf::Keyboard::Z);
    mod->addConstant("sfKeyboardKeyNum0", (Falcon::int64)sf::Keyboard::Num0);
    mod->addConstant("sfKeyboardKeyNum1", (Falcon::int64)sf::Keyboard::Num1);
    mod->addConstant("sfKeyboardKeyNum2", (Falcon::int64)sf::Keyboard::Num2);
    mod->addConstant("sfKeyboardKeyNum3", (Falcon::int64)sf::Keyboard::Num3);
    mod->addConstant("sfKeyboardKeyNum4", (Falcon::int64)sf::Keyboard::Num4);
    mod->addConstant("sfKeyboardKeyNum5", (Falcon::int64)sf::Keyboard::Num5);
    mod->addConstant("sfKeyboardKeyNum6", (Falcon::int64)sf::Keyboard::Num6);
    mod->addConstant("sfKeyboardKeyNum7", (Falcon::int64)sf::Keyboard::Num7);
    mod->addConstant("sfKeyboardKeyNum8", (Falcon::int64)sf::Keyboard::Num8);
    mod->addConstant("sfKeyboardKeyNum9", (Falcon::int64)sf::Keyboard::Num9);
    mod->addConstant("sfKeyboardKeyNumpad0", (Falcon::int64)sf::Keyboard::Numpad0);
    mod->addConstant("sfKeyboardKeyNumpad1", (Falcon::int64)sf::Keyboard::Numpad1);
    mod->addConstant("sfKeyboardKeyNumpad2", (Falcon::int64)sf::Keyboard::Numpad2);
    mod->addConstant("sfKeyboardKeyNumpad3", (Falcon::int64)sf::Keyboard::Numpad3);
    mod->addConstant("sfKeyboardKeyNumpad4", (Falcon::int64)sf::Keyboard::Numpad4);
    mod->addConstant("sfKeyboardKeyNumpad5", (Falcon::int64)sf::Keyboard::Numpad5);
    mod->addConstant("sfKeyboardKeyNumpad6", (Falcon::int64)sf::Keyboard::Numpad6);
    mod->addConstant("sfKeyboardKeyNumpad7", (Falcon::int64)sf::Keyboard::Numpad7);
    mod->addConstant("sfKeyboardKeyNumpad8", (Falcon::int64)sf::Keyboard::Numpad8);
    mod->addConstant("sfKeyboardKeyNumpad9", (Falcon::int64)sf::Keyboard::Numpad9);
    mod->addConstant("sfKeyboardKeyF1", (Falcon::int64)sf::Keyboard::F1);
    mod->addConstant("sfKeyboardKeyF2", (Falcon::int64)sf::Keyboard::F2);
    mod->addConstant("sfKeyboardKeyF3", (Falcon::int64)sf::Keyboard::F3);
    mod->addConstant("sfKeyboardKeyF4", (Falcon::int64)sf::Keyboard::F4);
    mod->addConstant("sfKeyboardKeyF5", (Falcon::int64)sf::Keyboard::F5);
    mod->addConstant("sfKeyboardKeyF6", (Falcon::int64)sf::Keyboard::F6);
    mod->addConstant("sfKeyboardKeyF7", (Falcon::int64)sf::Keyboard::F7);
    mod->addConstant("sfKeyboardKeyF8", (Falcon::int64)sf::Keyboard::F8);
    mod->addConstant("sfKeyboardKeyF9", (Falcon::int64)sf::Keyboard::F9);
    mod->addConstant("sfKeyboardKeyF10", (Falcon::int64)sf::Keyboard::F10);
    mod->addConstant("sfKeyboardKeyF11", (Falcon::int64)sf::Keyboard::F11);
    mod->addConstant("sfKeyboardKeyF12", (Falcon::int64)sf::Keyboard::F12);
    mod->addConstant("sfKeyboardKeyF13", (Falcon::int64)sf::Keyboard::F13);
    mod->addConstant("sfKeyboardKeyF14", (Falcon::int64)sf::Keyboard::F14);
    mod->addConstant("sfKeyboardKeyF15", (Falcon::int64)sf::Keyboard::F15);
    mod->addConstant("sfKeyboardKeyLControl", (Falcon::int64)sf::Keyboard::LControl);
    mod->addConstant("sfKeyboardKeyRControl", (Falcon::int64)sf::Keyboard::RControl);
    mod->addConstant("sfKeyboardKeyLAlt", (Falcon::int64)sf::Keyboard::LAlt);
    mod->addConstant("sfKeyboardKeyRAlt", (Falcon::int64)sf::Keyboard::RAlt);
    mod->addConstant("sfKeyboardKeyLShift", (Falcon::int64)sf::Keyboard::LShift);
    mod->addConstant("sfKeyboardKeyRShift", (Falcon::int64)sf::Keyboard::RShift);
    mod->addConstant("sfKeyboardKeyLSystem", (Falcon::int64)sf::Keyboard::LSystem);
    mod->addConstant("sfKeyboardKeyRSystem", (Falcon::int64)sf::Keyboard::RSystem);
    mod->addConstant("sfKeyboardKeyLBracket", (Falcon::int64)sf::Keyboard::LBracket);
    mod->addConstant("sfKeyboardKeyRBracket", (Falcon::int64)sf::Keyboard::RBracket);
    mod->addConstant("sfKeyboardKeyEscape", (Falcon::int64)sf::Keyboard::Escape);
    mod->addConstant("sfKeyboardKeyMenu", (Falcon::int64)sf::Keyboard::Menu);
    mod->addConstant("sfKeyboardKeySemiColon", (Falcon::int64)sf::Keyboard::SemiColon);
    mod->addConstant("sfKeyboardKeyComma", (Falcon::int64)sf::Keyboard::Comma);
    mod->addConstant("sfKeyboardKeyPeriod", (Falcon::int64)sf::Keyboard::Period);
    mod->addConstant("sfKeyboardKeyQuote", (Falcon::int64)sf::Keyboard::Quote);
    mod->addConstant("sfKeyboardKeySlash", (Falcon::int64)sf::Keyboard::Slash);
    mod->addConstant("sfKeyboardKeyBackSlash", (Falcon::int64)sf::Keyboard::BackSlash);
    mod->addConstant("sfKeyboardKeyTilde", (Falcon::int64)sf::Keyboard::Tilde);
    mod->addConstant("sfKeyboardKeyEqual", (Falcon::int64)sf::Keyboard::Equal);
    mod->addConstant("sfKeyboardKeyDash", (Falcon::int64)sf::Keyboard::Dash);
    mod->addConstant("sfKeyboardKeySpace", (Falcon::int64)sf::Keyboard::Space);
    mod->addConstant("sfKeyboardKeyReturn", (Falcon::int64)sf::Keyboard::Return);
    mod->addConstant("sfKeyboardKeyBackSpace", (Falcon::int64)sf::Keyboard::BackSpace);
    mod->addConstant("sfKeyboardKeyTab", (Falcon::int64)sf::Keyboard::Tab);
    mod->addConstant("sfKeyboardKeyPageUp", (Falcon::int64)sf::Keyboard::PageUp);
    mod->addConstant("sfKeyboardKeyPageDown", (Falcon::int64)sf::Keyboard::PageDown);
    mod->addConstant("sfKeyboardKeyEnd", (Falcon::int64)sf::Keyboard::End);
    mod->addConstant("sfKeyboardKeyHome", (Falcon::int64)sf::Keyboard::Home);
    mod->addConstant("sfKeyboardKeyInsert", (Falcon::int64)sf::Keyboard::Insert);
    mod->addConstant("sfKeyboardKeyDelete", (Falcon::int64)sf::Keyboard::Delete);
    mod->addConstant("sfKeyboardKeyAdd", (Falcon::int64)sf::Keyboard::Add);
    mod->addConstant("sfKeyboardKeySubtract", (Falcon::int64)sf::Keyboard::Subtract);
    mod->addConstant("sfKeyboardKeyMultiply", (Falcon::int64)sf::Keyboard::Multiply);
    mod->addConstant("sfKeyboardKeyDivide", (Falcon::int64)sf::Keyboard::Divide);
    mod->addConstant("sfKeyboardKeyLeft", (Falcon::int64)sf::Keyboard::Left);
    mod->addConstant("sfKeyboardKeyRight", (Falcon::int64)sf::Keyboard::Right);
    mod->addConstant("sfKeyboardKeyUp", (Falcon::int64)sf::Keyboard::Up);
    mod->addConstant("sfKeyboardKeyDown", (Falcon::int64)sf::Keyboard::Down);
    mod->addConstant("sfKeyboardKeyPause", (Falcon::int64)sf::Keyboard::Pause);
    mod->addConstant("sfKeyboardKeyKeyCount", (Falcon::int64)sf::Keyboard::KeyCount);

    /* thor::Action::ActionType */
    mod->addConstant("thorActionActionTypeHold", (Falcon::int64)thor::Action::Hold);
    mod->addConstant("thorActionActionTypePressOnce", (Falcon::int64)thor::Action::PressOnce);
    mod->addConstant("thorActionActionTypeReleaseOnce", (Falcon::int64)thor::Action::ReleaseOnce);

    /* sf::Mouse::Button (Inaccurate for Key comaptibility) */
    mod->addConstant("sfMouseButtonLeft", (Falcon::int64)sf::Keyboard::KeyCount + 1 + (Falcon::int64)sf::Mouse::Left);
    mod->addConstant("sfMouseButtonRight", (Falcon::int64)sf::Keyboard::KeyCount + 1 + (Falcon::int64)sf::Mouse::Right);
    mod->addConstant("sfMouseButtonMiddle", (Falcon::int64)sf::Keyboard::KeyCount + 1 + (Falcon::int64)sf::Mouse::Middle);
    mod->addConstant("sfMouseButtonXButton1", (Falcon::int64)sf::Keyboard::KeyCount + 1 + (Falcon::int64)sf::Mouse::XButton1);
    mod->addConstant("sfMouseButtonXButton2", (Falcon::int64)sf::Keyboard::KeyCount + 1 + (Falcon::int64)sf::Mouse::XButton2);
    mod->addConstant("sfMouseButtonButtonCount", (Falcon::int64)sf::Mouse::ButtonCount);
}
#include <iostream>
void DisandriaFalconSAPI::addMethods(Falcon::Module* mod)
{
    std::cout << "!" << std::endl;
    mod->addExtFunc("exitDisandria", [](Falcon::VMachine * vm) {
        Falcon::Item* exitCode = vm->param(0);
        if(exitCode == NULL || !exitCode->isInteger()) {
            exit(0);
        }
        exit(exitCode->forceInteger());
    });
}

void DisandriaFalconSAPI::addClasses(Falcon::Module* mod)
{
    /* sf::Music */
    Falcon::Symbol* sfMusic = mod->addClass("sfMusic", &dfsapi_sf_Music::init);
    sfMusic->setWKS(true);
    sfMusic->getClassDef()->factory(&dfsapi_sf_Music::factory);
    mod->addClassMethod(sfMusic, "openFromFile", &dfsapi_sf_Music::openFromFile);
    mod->addClassMethod(sfMusic, "getDuration", &dfsapi_sf_Music::getDuration);
    mod->addClassMethod(sfMusic, "play", &dfsapi_sf_Music::play);
    mod->addClassMethod(sfMusic, "pause", &dfsapi_sf_Music::pause);
    mod->addClassMethod(sfMusic, "stop", &dfsapi_sf_Music::stop);
    mod->addClassMethod(sfMusic, "getChannelCount", &dfsapi_sf_Music::getChannelCount);
    mod->addClassMethod(sfMusic, "getSampleRate", &dfsapi_sf_Music::getSampleRate);
    mod->addClassMethod(sfMusic, "getStatus", &dfsapi_sf_Music::getStatus);
    mod->addClassMethod(sfMusic, "getPlayingOffset", &dfsapi_sf_Music::getPlayingOffset);
    mod->addClassMethod(sfMusic, "setPlayingOffset", &dfsapi_sf_Music::setPlayingOffset);
    mod->addClassMethod(sfMusic, "getLoop", &dfsapi_sf_Music::getLoop);
    mod->addClassMethod(sfMusic, "setLoop", &dfsapi_sf_Music::setLoop);
    mod->addClassMethod(sfMusic, "getPitch", &dfsapi_sf_Music::getPitch);
    mod->addClassMethod(sfMusic, "setPitch", &dfsapi_sf_Music::setPitch);
    mod->addClassMethod(sfMusic, "getVolume", &dfsapi_sf_Music::getVolume);
    mod->addClassMethod(sfMusic, "setVolume", &dfsapi_sf_Music::setVolume);

    /* sf::SoundBuffer */
    Falcon::Symbol* sfSoundBuffer = mod->addClass("sfSoundBuffer", &dfsapi_sf_SoundBuffer::init);
    sfSoundBuffer->setWKS(true);
    sfSoundBuffer->getClassDef()->factory(&dfsapi_sf_SoundBuffer::factory);
    mod->addClassMethod(sfSoundBuffer, "loadFromFile", &dfsapi_sf_SoundBuffer::loadFromFile);
    mod->addClassProperty(sfSoundBuffer, "duration");
    mod->addClassProperty(sfSoundBuffer, "channelCount");
    mod->addClassProperty(sfSoundBuffer, "sampleRate");
    mod->addClassProperty(sfSoundBuffer, "sampleCount");

    /* sf::Sound */
    Falcon::Symbol* sfSound = mod->addClass("sfSound", &dfsapi_sf_Sound::init)->addParam("soundBuffer");
    sfSound->setWKS(true);
    sfSound->getClassDef()->factory(&dfsapi_sf_Sound::factory);
    mod->addClassMethod(sfSound, "play", &dfsapi_sf_Sound::play);
    mod->addClassMethod(sfSound, "getBuffer", &dfsapi_sf_Sound::getBuffer);
    mod->addClassMethod(sfSound, "setBuffer", &dfsapi_sf_Sound::setBuffer);
    mod->addClassMethod(sfSound, "pause", &dfsapi_sf_Sound::pause);
    mod->addClassMethod(sfSound, "stop", &dfsapi_sf_Sound::stop);
    mod->addClassMethod(sfSound, "getStatus", &dfsapi_sf_Sound::getStatus);
    mod->addClassMethod(sfSound, "getPlayingOffset", &dfsapi_sf_Sound::getPlayingOffset);
    mod->addClassMethod(sfSound, "setPlayingOffset", &dfsapi_sf_Sound::setPlayingOffset);
    mod->addClassMethod(sfSound, "getLoop", &dfsapi_sf_Sound::getLoop);
    mod->addClassMethod(sfSound, "setLoop", &dfsapi_sf_Sound::setLoop);
    mod->addClassMethod(sfSound, "getPitch", &dfsapi_sf_Sound::getPitch);
    mod->addClassMethod(sfSound, "setPitch", &dfsapi_sf_Sound::setPitch);
    mod->addClassMethod(sfSound, "getVolume", &dfsapi_sf_Sound::getVolume);
    mod->addClassMethod(sfSound, "setVolume", &dfsapi_sf_Sound::setVolume);

    /* thor::Action */
    Falcon::Symbol* thorAction = mod->addClass("thorAction", &dfsapi_thor_Action::init)->addParam("input")->addParam("inputtype");
    thorAction->setWKS(true);
    thorAction->getClassDef()->factory(&dfsapi_thor_Action::factory);
    mod->addClassMethod(thorAction, "combineAnd", &dfsapi_thor_Action::combineAnd);
    mod->addClassMethod(thorAction, "combineOr", &dfsapi_thor_Action::combineOr);
}

void DisandriaFalconSAPI::addSingletons(Falcon::Module* mod)
{
    /* GameManager */
    Falcon::Symbol* gameManagerSingleton = mod->addSingleton("GameManager");
    Falcon::Symbol* gameManagerClass = gameManagerSingleton->getInstance();
    mod->addClassMethod(gameManagerClass, "getGameFolderName", &dfsapi_GameManager_getGameFolderName);
    mod->addClassMethod(gameManagerClass, "getEngineVersion", &dfsapi_GameManager_getEngineVersion);

    /* DisandriaObjectShare */
    Falcon::Symbol* disandriaObjectShareSingleton = mod->addSingleton("DisandriaObjectShare");
    Falcon::Symbol* disandriaObjectShareClass = disandriaObjectShareSingleton->getInstance();
    mod->addClassMethod(disandriaObjectShareClass, "addObject", &dfsapi_DisandriaObjectShare::addObject);
    mod->addClassMethod(disandriaObjectShareClass, "getObject", &dfsapi_DisandriaObjectShare::getObject);
    mod->addClassMethod(disandriaObjectShareClass, "removeObject", &dfsapi_DisandriaObjectShare::removeObject);
    mod->addClassMethod(disandriaObjectShareClass, "isObjectAvailable", &dfsapi_DisandriaObjectShare::isObjectAvailable);

    /* sf::Keyboard */
    Falcon::Symbol* sfKeyboardSingleton = mod->addSingleton("sfKeyboard");
    Falcon::Symbol* sfKeyboardClass = sfKeyboardSingleton->getInstance();
    mod->addClassMethod(sfKeyboardClass, "isKeyPressed", &dfsapi_sf_Keyboard_isKeyPressed);

    /* "RenderWindow" Input */
    Falcon::Symbol* inputSingleton = mod->addSingleton("Input");
    Falcon::Symbol* inputClass = inputSingleton->getInstance();
    mod->addClassMethod(inputClass, "addAction", &dfsapi_Input_addAction);
    mod->addClassMethod(inputClass, "addCallback", &dfsapi_Input_addCallback);
    mod->addClassMethod(inputClass, "addActionCallback", &dfsapi_Input_addActionCallback);
    mod->addClassMethod(inputClass, "removeCallback", &dfsapi_Input_removeCallback);
    mod->addClassMethod(inputClass, "clearCallbacks", &dfsapi_Input_clearCallbacks);
}
