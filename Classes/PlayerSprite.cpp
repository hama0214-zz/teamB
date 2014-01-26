#include "PlayerSprite.h"

using namespace cocos2d;

/*
■変数設定（コンストラクタの中で変数を宣言したら、ほかのところで正しい数字がはいったり、はいらなかったりした
 todo
 ３、落下させる
 ４、地面をみる]
 
 */


PlayerSprite::PlayerSprite()
{

}

//creat
PlayerSprite *PlayerSprite::create(const char* pszFileName)
{
    PlayerSprite *pobSprite = new PlayerSprite();
    if (pobSprite && pobSprite->initWithFile(pszFileName)) {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}


//↓もともとコンストラクタでやっていたものを、自分用init作った
void PlayerSprite::myInit(int x,int y)
{
    this->pStatus=0;
    this->pAction=0;
//    this->initWithFile("player_nomal.png");
    this->autorelease();
    this->setPosition(ccp(x,y));
    this->setTag(1);
    
    //サイズを設定
    this->setScale(0.5);
    
    //サイズを取得してログ表示
    CCSize imgSize = this->getContentSize();
//    CCLog("pImgの幅は%f pImgの高さは%f", imgSize.width, imgSize.height);
    
    this->schedule(schedule_selector(PlayerSprite::update));
}



/**
 *  スプライトの範囲を取得
 *  @return CCRect
 */
CCRect PlayerSprite::getRect()
{
    // スプライトの座標（画像の真ん中の座標のこと）
    CCPoint point = this->getPosition();

    int w = this->getContentSize().width;
    int h = this->getContentSize().height;
    
    // スプライトの範囲を返す
    return CCRectMake(point.x-(w/2), point.y-(h/2), w, h);
}

/**
 *  引数の座標がスプライトの範囲内かどうかを返す（タッチ時の座標情報を渡す）
 *  @param point 座標ポイント
 *  @return ture or false
 */
bool PlayerSprite::isTouchPoint(CCPoint point)
{
    return this->getRect().containsPoint(point);
}

/**
 *  引数の座標がスプライトの範囲内かどうかを返す（タッチ時の座標情報を渡す）
 *  @param point 座標ポイント
 *  @return ture or false
 */
bool PlayerSprite::jump()
{

    if(pStatus==2)
    {

        CCCallFuncN *actionMoveDone =
                            CCCallFuncN::create(this,
                                               callfuncN_selector(PlayerSprite::playerMoveFinished));
        
//        CCMoveBy *jumpAct = CCMoveBy::create(0.5f,ccp(0,130));
        CCJumpTo *jumpAct = CCJumpTo::create(1.0f,ccp(100,0),300,1 );

        CCActionInterval *easingAct = CCEaseOut::create(jumpAct,2.0f);
        this->runAction(CCSequence::create(
                                           easingAct,actionMoveDone,NULL));

        this->pStatus=1;
        CCLog("じゃんぷ！（Player側のイベント受け取り成功）");
        
    }else if(pStatus==1){
        landing();
        CCLog("緊急脱出");
        
    }
    return true;
}

/**
 * 内部用。キャラクターがいるとき毎フレーム処理されるもの
 */

void PlayerSprite::update(float dt)
{
    //位置を取得
    CCPoint point = this->getPosition();
//    CCLog("x座標：%f, y座標：%f", point.x, point.y);

    switch (pStatus) {
        case 2://着地中
            
            //地面がなくなる判定をかく
            
            break;
            
        case 1://空中
            //床の高さをみて待機させる
            if (point.y < 100 + (this->getContentSize().height * this->getScaleY()) / 2)
            {
                landing();
                this->setPosition(ccp(point.x , 101 + (this->getContentSize().height * this->getScaleY()) / 2));
            }
            break;
        
        case 0://落下開始
            CCLog("らっかなう");
            pStatus=1;
            
            CCCallFuncN *actionMoveDone =
            CCCallFuncN::create(this,
                                callfuncN_selector(PlayerSprite::playerMoveFinished));
            
            //        CCMoveBy *jumpAct = CCMoveBy::create(0.5f,ccp(0,130));
            CCJumpTo *jumpAct = CCJumpTo::create(1.0f,ccp(100,0),0,1 );
            
            CCActionInterval *easingAct = CCEaseOut::create(jumpAct,2.0f);
            this->runAction(CCSequence::create(
                                               easingAct,actionMoveDone,NULL));
            
            
            break;
    
    }
}

/**
 *  引数の座標がスプライトの範囲内かどうかを返す（タッチ時の座標情報を渡す）
 *  @return アクションの状態
 */
int PlayerSprite::getpAction()
{
    return pAction;
}

/**
 *  引数の座標がスプライトの範囲内かどうかを返す（タッチ時の座標情報を渡す）
 *  @return プレイヤーの状態
 */
int PlayerSprite::getpStatus()
{
    return pStatus;
}

//jump
void PlayerSprite::landing()
{
    this->stopAllActions();
    pStatus=2;
}


//jump終了メソッド。
void PlayerSprite::playerMoveFinished()
{
    pStatus=2;
}


PlayerSprite::~PlayerSprite()
{

}

bool PlayerSprite::init() {
    return true;
}



