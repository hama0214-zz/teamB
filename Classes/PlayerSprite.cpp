#include "PlayerSprite.h"

using namespace cocos2d;


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
    this->pGigantic=0;
    this->pAbsorption=0;
    this->pFlight=0;
    
    //    this->initWithFile("player_nomal.png");
    this->autorelease();
    this->setPosition(ccp(x,y));
    this->setTag(1);
    
    //    CCLog("ポジション %f %f",this->getAnchorPoint().x,this->getAnchorPoint().y);
    //アンカーポイントを足下に設定
    this->setAnchorPoint(ccp(0.5,0));
    
    //サイズを設定
    this->setScale(0.363);
    
    
    //サイズを取得してログ表示
    CCSize imgSize = this->getContentSize();
    CCLog("pImgの幅は%f pImgの高さは%f", imgSize.width, imgSize.height);
    
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
    
    if(pAction==2)
    {
        
        CCCallFuncN *actionMoveDone =
        CCCallFuncN::create(this,
                            callfuncN_selector(PlayerSprite::playerMoveFinished));
        
        CCJumpTo *jumpAct = CCJumpTo::create(1.0f,ccp(100,-200),300,1 );        
        CCActionInterval *easingAct = CCEaseOut::create(jumpAct,2.0f);

        CCSequence *jumpAnimeSet=CCSequence::create(easingAct,actionMoveDone,NULL);
        jumpAnimeSet->setTag(10);
        this->runAction(jumpAnimeSet);

        this->pAction=1;
        
    }else if(pAction==1){
        
        //landing();
        
        if (pGigantic==0){
            pGigantic=1;
        }
        
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
    
    //-------ジャンプ系処理
    switch (pAction) {
        case 2://着地中
            
            //地面がなくなる判定をかく
            
            break;
            
        case 1://空中
            //床の高さをみて待機させる
            if (point.y < 100 )
            {
                landing();
                this->setPosition(ccp(point.x , 101));
                // + (this->getContentSize().height * this->getScaleY()) / 2)//自分のサイズとったり
            }
            break;
            
        case 0://落下開始
            CCLog("らっかなう");

            pAction=1;
            
            CCCallFuncN *actionMoveDone =
            CCCallFuncN::create(this,
                                callfuncN_selector(PlayerSprite::playerMoveFinished));
            
            
            CCJumpTo *jumpAct = CCJumpTo::create(2.0f,ccp(100,-200),0,1 );
            CCActionInterval *easingAct = CCEaseOut::create(jumpAct,2.0f);
            CCSequence *jumpAnimeSet=CCSequence::create(easingAct,actionMoveDone,NULL);
            jumpAnimeSet->setTag(10);
            this->runAction(jumpAnimeSet);
            
            
            break;
            
    }
    //------巨大化処理
    if (pGigantic==1){
        pGigantic++;
        CCScaleTo *changeBig1 =CCScaleTo::create( 0.1f, 0.55f);
        CCScaleTo *changeBig2 =CCScaleTo::create( 0.1f, 0.45f);
        CCScaleTo *changeBig3 =CCScaleTo::create( 0.7f, 0.66f);
        
        CCActionInterval *easingAct = CCEaseOut::create(changeBig3,2.0f);
        this->runAction(CCSequence::create(
                                           changeBig1,changeBig2,easingAct,NULL));
        
    }
    else if (pGigantic>=300)
    {
        pGigantic=0;
        CCScaleTo *changeBig1 =CCScaleTo::create( 0.1f, 0.45f);
        CCScaleTo *changeBig2 =CCScaleTo::create( 0.1f, 0.55f);
        CCScaleTo *changeBig3 =CCScaleTo::create( 0.7f, 0.363f);
        
        CCActionInterval *easingAct = CCEaseOut::create(changeBig3,2.0f);
        this->runAction(CCSequence::create(
                                           changeBig1,changeBig2,easingAct,NULL));
    }
    else if (pGigantic>=1)
    {
        pGigantic++;
    }
    
    //-------
}




/**
 *  引数の座標がスプライトの範囲内かどうかを返す（タッチ時の座標情報を渡す）
 *  @return 巨大化しているか。
 */
bool PlayerSprite::getpGigantic()
{
    if (pGigantic==0){
        return false;
    }
    else
    {
        return true;
    }
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
    //this->stopAllActions();
        this->stopActionByTag(10);
    
    pAction=2;
}


//jump終了メソッド。
void PlayerSprite::playerMoveFinished()
{
    pAction=2;
}


PlayerSprite::~PlayerSprite()
{
    
}

bool PlayerSprite::init() {
    return true;
}



