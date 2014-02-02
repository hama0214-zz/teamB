//
//  MapPiece.h
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#ifndef __teamB__MapPiece__
#define __teamB__MapPiece__

#include "cocos2d.h"
#include "Variables.h"

USING_NS_CC;

class MapPiece : public CCSprite {
public:
    /** ピースタイプを取得する */
    virtual Variables::PIECE_TYPE getPieceType() const = 0;
    
    // TODO:ぶつかったのが上か横かなどの判定をするときは、引数にCCRectを入れて内部判断するといいかも
    /** プレイヤーにぶつかったときの処理 */
    virtual void hitPlayer() = 0;
    
    /**
     * 活動状態を取得する。
     * @return 活動状態かどうか
     */
    virtual bool getIsLive() const = 0;
    
    /**
     * 当たり判定を取得する。
     * @return 当たり判定。
     */
    virtual const CCRect& getRect() = 0;
};

#endif /* defined(__teamB__MapPiece__) */
