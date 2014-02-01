#include "FalconSAPI.h"
#include "lib/GameManager.h"
//#include "DisandriaFalconSAPI.h"
//#include "CEGUI/CEGUIFalconBinding.h"
#include <iostream>

void FalconSAPI::initialize()
{
    Falcon::Engine::init();
    vm = new Falcon::VMachine();
    proc = vm->createProcess();
    modloader = proc->modSpace()->modLoader();
    modloader->addDirectoryFront(GameManager::getGameFolderName().c_str());
    modloader->addFalconPath();
    proc->modSpace()->add(new Falcon::CoreModule);
    //proc->modSpace()->add(DisandriaFalconSAPI::createBinding());
    //proc->modSpace()->add(CEGUIFalconBinding::createBinding());
}

void FalconSAPI::createBindings()
{
}

int FalconSAPI::scriptRequests()
{
    return SubmitType_FILENAME;
}

void FalconSAPI::scriptByFilename(std::string fileName)
{
    try {
        std::cout << std::boolalpha << proc->startScript(Falcon::URI((GameManager::getGameFolderName() + fileName).c_str())) << std::noboolalpha << std::endl;
        //Falcon::WVMContext* ctx = new Falcon::WVMContext(proc);
        //std::cout << std::boolalpha << modloader->loadFile(ctx, (GameManager::getGameFolderName() + fileName).c_str()) << std::noboolalpha << std::endl;
        //ctx->startEvaluation("x = 3; > x");
        //Falcon::VMContext* pctx = proc->mainContext();
        //pctx->terminate();
        //pctx = ctx;
        //proc->startContext(ctx);
        //std::cout << std::boolalpha << (proc->mainContext() == ctx);
        proc->start();
        //ctx->terminate();
    } catch(Falcon::Error* err) {
        // = proc->error();
        Falcon::AutoCString edesc(err->describe());
        std::cerr << edesc.c_str() << std::endl;
        err->decref();
        return;
    }
    /*#ifdef FALCON1
    #else
        Falcon::Runtime rt(modloader, vm);
        try {
            rt.loadFile(fileName.c_str());
            vm->link(&rt);
            vm->launch();
        } catch(Falcon::Error* err) {
            Falcon::AutoCString edesc(err->toString());
            std::cerr << edesc.c_str() << std::endl;
            err->decref();
            return;
        }
        vm->unlink(&rt);
    #endif*/
}

void FalconSAPI::destroyBindings()
{
}

void FalconSAPI::uninitialize()
{
    try {
        vm->quit();
        //proc->terminate();
        proc = NULL;
        vm = NULL;
        Falcon::Engine::shutdown();
    } catch(Falcon::Error* err) {
        Falcon::AutoCString edesc(err->describe());
        std::cerr << edesc.c_str() << std::endl;
        err->decref();
        return;
    }
}

void FalconSAPI::reset()
{
    /*#ifndef FALCON1
        vm->reset();
    #endif*/
}
