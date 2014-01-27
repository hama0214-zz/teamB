#include "Gamescene.h"
#include "Menuscene.h"
#include "GameMaster.h"

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

    /*
    メニューに戻るときに、落ちるのでいったんコメントアウト
    //キャラクター配置
    player = PlayerSprite::create("player_nomal.png");
    player->myInit(100,CCDirector::sharedDirector()->getWinSize().height);
    this->addChild(player);
    */
    
    //タップイベントを取得する
    this->setTouchMode(kCCTouchesAllAtOnce);
    this->setTouchEnabled(true);

    // マップ移動開始
    moveStart();
    
    //スコア類 (あとでrelease!!!!!!!!)
    gMaster= new GameMaster();
    gMaster->show();
    
    scoreLabel= CCLabelTTF::create("Touch Layer", "arial", 48);
    scoreLabel->setString(gMaster->scoreStr->getCString());

    scoreLabel->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width * 0.1, CCDirector::sharedDirector()->getWinSize().height * 0.95));

    this->addChild(scoreLabel);

    materLabel= CCLabelTTF::create("Touch Layer", "arial", 48);
    materLabel->setString(gMaster->scoreStr->getCString());
    materLabel->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width * 0.5, CCDirector::sharedDirector()->getWinSize().height * 0.95));
    
    this->addChild(materLabel);

    materDLabel = CCLabelTTF::create("Touch Layer", "arial", 48);
    materDLabel->setString(gMaster->materDStr->getCString());
    materDLabel->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width * 0.5, CCDirector::sharedDirector()->getWinSize().height * 0.05));
    
    this->addChild(materDLabel);
    iMater = 0;
    //スケジュール
    this->schedule(schedule_selector(GameScene::upScore), 0.3f);
    
    
    return true;
    
}
void GameScene::upScore() {
    iMater++;
    //    CCLog("iMater -> %d", iMater);
    if (iMater > 10) {
        gMaster->showPop(0);
        moveStop();
        this->addChild(gMaster->pPop);
    } else {
        CCString *str = CCString::createWithFormat("%d M", iMater);
        
        materLabel->setString(str->getCString());
        materDLabel->setString(str->getCString());
    }
}

void GameScene::ccTouchesBegan(cocos2d::CCSet *touches,
                               cocos2d::CCEvent *event)
{
    CCScene* scene = MenuScene::scene();
    //            CCTransitionFadeBL* tran = CCTransitionFadeBL::create(1, scene);
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->replaceScene(scene);
    
    CCTouch *pTouch = (CCTouch *)touches->anyObject();
    CCPoint touchPoint = pDirector->convertToGL(pTouch->getLocationInView());
    
    //戻るボタン
    CCRect rect;
    if (gMaster->pPop != NULL){
        rect= gMaster->pPop->boundingBox();
        if (rect.containsPoint(touchPoint))
        {
            gMaster->release();

            CCScene* scene = MenuScene::scene();
//            CCTransitionFadeBL* tran = CCTransitionFadeBL::create(1, scene);
            pDirector->replaceScene(scene);

            return;
        }
    }

    
    player->jump();
    CCLog("pAction %d ",player->getpStatus());
}

void GameScene::moveStart() {
    CCMoveBy* move = CCMoveBy::create(GameScene::MAP_MOVE_SPEED, ccp(-MapPieceManager::CELL_WIDTH, 0));
    CCCallFuncO* removeLastLineFunc = CCCallFuncO::create((CCObject*)mapPieceMgr, callfuncO_selector(MapPieceManager::removeLastLineMapPieces), mapNode);
    CCSequence* moveSeq = CCSequence::create(move, removeLastLineFunc, NULL);
    CCRepeatForever* moveRep = CCRepeatForever::create(moveSeq);
    moveRep->setTag(GameScene::TAG_MAP_MOVE_EVENT);
    mapNode->runAction(moveRep);
}

void GameScene::moveStop() {
    mapNode->stopActionByTag(GameScene::TAG_MAP_MOVE_EVENT);
}
