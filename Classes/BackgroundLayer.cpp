//
//  BackgroundLayer.cpp
//  背景レイヤー
//  teamB
//
//  Created by Yuto Yoshinari on 2014/02/02.
//
//

#include "BackgroundLayer.h"

/**
 * 初期化メソッド
 * @public
 */
bool BackgroundLayer::init() {
    // 親クラスを初期化できているかの確認
    if (!CCLayer::init()) {
        return false;
    }
        
    // 同じ背景画像を何個も描画するが、
    // 何個描画しても描画回数を１回で済ますためにCCSpriteBatchNodeを用いる
    batchNode = CCSpriteBatchNode::create("background.png");
    this->addChild(batchNode);
    
    // 2ページ分描画する
    drawBackgroundAtIndex(0);
    drawBackgroundAtIndex(1);
    
    // 現在描画し終わっている最新背景のindex
    bgIndex = 1;
    
    return true;
}

/** 背景のアニメーション周りのメソッド */

/**
 * 動かし始める
 * @public
 */
void BackgroundLayer::moveStart() {
    this->schedule(schedule_selector(BackgroundLayer::move));
}
/**
 * 動いているのを止める
 * @public
 */
void BackgroundLayer::moveStop() {
    this->unschedule(schedule_selector(BackgroundLayer::move));
}

/**
 * 動かす
 * @private
 */
void BackgroundLayer::move() {
    CCPoint nextPosition = ccp(batchNode->getPosition().x-5, batchNode->getPosition().y);
    batchNode->setPosition(nextPosition);
    if (-nextPosition.x > bgSpriteSize.width * bgIndex) {
        bgIndex++;
        updateBackgroundAtIndex(bgIndex);
    }
}

/** 背景の描画周りのメソッド */

/**
 * 背景を更新する
 * @private
 */
void BackgroundLayer::updateBackgroundAtIndex(int index) {
    drawBackgroundAtIndex(index);
    removeBackgroundAtIndex(index-2);
}
/**
 * 指定したIndexの背景を描画する
 * @private
 */
void BackgroundLayer::drawBackgroundAtIndex(int index) {
    //CCSpriteBatchNodeからスプライトを作成して表示する
    CCSprite* pImg = CCSprite::createWithTexture(batchNode->getTexture());
    if (index == 0) {
        // 初回だけサイズを保持
        bgSpriteSize = pImg->getContentSize();
    }
    pImg->setPosition(ccp(bgSpriteSize.width*index, 0));
    pImg->setTag(index);
    batchNode->addChild(pImg);
}
/**
 * 指定したIndexの背景を取り除く
 * @private
 */
void BackgroundLayer::removeBackgroundAtIndex(int index) {
    CCSprite* pImg = (CCSprite*)batchNode->getChildByTag(index);
    pImg->removeFromParentAndCleanup(true);
}