#include "Gamescene.h"

#include "PlayerSprite.h"

using namespace cocos2d;
using namespace std;

CCScene* GameScene::scene()
{
    CCScene* scene = CCScene::create();
    GameScene* layer = GameScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init()
{
    //親クラスwのinitを呼ぶ
    if (!CCLayer::init())
    {
        return false;
    }
    
    //ここから
    PlayerSprite* player = new PlayerSprite(100,199);
    this->addChild(player);

    return true;
    
}