//
//  MapPieceManager.h
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#ifndef __teamB__MapPieceManager__
#define __teamB__MapPieceManager__

#include "cocos2d.h"

USING_NS_CC;

/**
 * マップパーツを管理するクラス。
 */
class MapPieceManager : CCObject{
public:
    // TODO: マップデータからマネージャーを作る
    /** クリエイトメソッド */
    static MapPieceManager* create();

    /**
     * 指定したノードにマップパーツを配置する。
     * @param node ノード
     */
    void makeMapForNode(CCNode* node);

private:
    /** デストラクタ */
    ~MapPieceManager();

    /**
     * 初期化する
     * @return 初期化に成功したかどうか。
     */
    bool init();

    CCArray* m_column;
    CCArray* m_line;
};

#endif /* defined(__teamB__MapPieceManager__) */
