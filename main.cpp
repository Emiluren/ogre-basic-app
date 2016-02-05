#include <iostream>
#include <OGRE/Ogre.h>

using namespace std;
using namespace Ogre;

int main() {
    Root* ogre = new Root("plugins.cfg", "ogre.cfg");

    const RenderSystemList& lRenderSystemList = ogre->getAvailableRenderers();
    if( lRenderSystemList.size() == 0 )
    {
        Ogre::LogManager::getSingleton().logMessage("Sorry, no rendersystem was found.");
        return 1;
    }

    Ogre::RenderSystem* renderSystem = lRenderSystemList[0];
    ogre->setRenderSystem(renderSystem);

    ogre->initialise(false);
    RenderWindow* window = ogre->createRenderWindow("test", 640, 480, false);
    cout << "Hello, World!" << endl;

    while(!window->isClosed()) {
        //window->update(false);
        ogre->renderOneFrame();

        WindowEventUtilities::messagePump();
    }
    return 0;
}