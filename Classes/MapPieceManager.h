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
#include "MapPieceFactory.h"
#include "Variables.h"

USING_NS_CC;

class MapPiece;

/**
 * マップパーツを管理するクラス。
 */
class MapPieceManager : CCObject{
public:
    /** 1マスの横幅 */
    static const int CELL_WIDTH;

    /** 1マスの縦幅 */
    static const int CELL_HEIGHT;

    /** マップの縦のマス数 */
    static const int MAP_HEIGHT;

    // TODO: マップデータからマネージャーを作る
    /** クリエイトメソッド */
    static MapPieceManager* create();

    /**
     * 指定したノードにマップパーツを配置する。
     * @param マップピースの配置するノード。
     */
    void makeMapForNode(CCNode* mapNode);

    /**
     * 全てのマップピースオブジェクトを取得する。
     * @return 全てのマップピースオブジェクト。
     */
    CCArray* getAllMapPieces();

    /**
     * 現在一番左側の列のマップピースオブジェクトを全て削除する。
     * @param マップピースの配置されているノード。
     */
    void removeLastLineMapPieces(CCObject* mapNodeObj);

private:
    /** マップデータ。 */
    std::vector< std::vector<int> > m_mapDatas;

    /** 全てのマップピースオブジェクトを管理する配列 */
    CCArray* m_mapPieceMatrix;

    /** デストラクタ */
    ~MapPieceManager();

    /**
     * 初期化する
     * @return 初期化に成功したかどうか。
     */
    bool init();
};

#endif /* defined(__teamB__MapPieceManager__) */
