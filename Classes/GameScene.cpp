#include "Gamescene.h"

#include "PlayerSprite.h"

using namespace cocos2d;
using namespace std;

// TODO:スピードアップの機能ができた場合、スタート時のスピードの定数として扱う
// 1マス分の距離を何秒で移動するかの定数
const float GameScene::MAP_MOVE_SPEED = 0.2f;

// マップの移動アクションのタグ
// 値の100は適当。アクションの数字が被らなければ何でもいい。数が多くなってくるようならルールを決める。
const int GameScene::TAG_MAP_MOVE_EVENT = 100;

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
    player->myInit(100,200);
    this->addChild(player);
    
    //タップイベントを取得する
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);

    // マップ移動開始
    moveStart();

    return true;
    
}

void GameScene::ccTouchesBegan(cocos2d::CCSet *touches,
                               cocos2d::CCEvent *event)
{
    player->jump();
    CCLog("pAction %d ",player->getpStatus());
}

void GameScene::moveStart() {
    CCMoveBy* move = CCMoveBy::create(GameScene::MAP_MOVE_SPEED, ccp(-MapPieceManager::CELL_WIDTH, 0));
    CCRepeatForever* moveRep = CCRepeatForever::create(move);
    moveRep->setTag(GameScene::TAG_MAP_MOVE_EVENT);
    mapNode->runAction(moveRep);
}

void GameScene::moveStop() {
    mapNode->stopActionByTag(GameScene::TAG_MAP_MOVE_EVENT);
}
