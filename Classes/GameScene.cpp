#include "Gamescene.h"

#include "PlayerSprite.h"

using namespace cocos2d;
using namespace std;

//キャラクターの作成
PlayerSprite *player;

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
    
    //キャラクター配置
    player = PlayerSprite::create("player_nomal.png");
    player->myInit(100,250);
    this->addChild(player);
    
    
    //タップイベントを取得する
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);

    // マップ管理者
    mapPieceMgr = MapPieceManager::create();
    mapPieceMgr->makeMapForNode(this);

    return true;
    
}

void GameScene::ccTouchesBegan(cocos2d::CCSet *touches,
                               cocos2d::CCEvent *event)
{
    player->jump();
    CCLog("pAction %d ",player->getpStatus());
}