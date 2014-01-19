#include "PlayerSprite.h"

using namespace cocos2d;

PlayerSprite::PlayerSprite(int x,int y)
{
    this->initWithFile("player_nomal.png");
    this->autorelease();
    this->setPosition(ccp(x,y));
    this->setTag(1);
}

/**
 *  スプライトの範囲を取得
 *  @return CCRect
 */
CCRect PlayerSprite::getRect()
{
    // スプライトの座標（画像の真ん中の座標のこと）
    CCPoint point = this->getPosition();
    
    // スプライトの幅と高さ
    int w = this->getContentSize().width;
    int h = this->getContentSize().height;
    


    // スプライトの範囲を返す
    return CCRectMake(point.x-(w/2), point.y-(h/2), w, h);
}

/**
 *  引数の座標がスプライトの範囲内かどうかを返す（タッチ時の座標情報を渡す）
 *
 *  @param point 座標ポイント
 *
 *  @return ture or false
 */
bool PlayerSprite::isTouchPoint(CCPoint point)
{
    return this->getRect().containsPoint(point);
}