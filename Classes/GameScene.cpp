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
    
    // マップノード
    mapNode = CCNode::create();
    // マップピース設置位置の基点
    mapNode->setPosition(ccp(MapPieceManager::CELL_WIDTH / 2, MapPieceManager::CELL_HEIGHT / 2));
    addChild(mapNode);

    // マップマネージャー
    mapPieceMgr = MapPieceManager::create();
    mapPieceMgr->makeMapForNode(mapNode);

    //キャラクター配置
    player = PlayerSprite::create("player_nomal.png");
    player->myInit(100,CCDirector::sharedDirector()->getWinSize().height);
    this->addChild(player);
    
    //タップイベントを取得する
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);
    return true;
    
}

void GameScene::ccTouchesBegan(cocos2d::CCSet *touches,
                               cocos2d::CCEvent *event)
{
    player->jump();
    CCLog("pAction %d ",player->getpStatus());
}