//
//  MapPieceManager.cpp
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#include "MapPieceManager.h"
#include "MapPieceFactory.h"
#include "MapPiece.h"

const int MapPieceManager::CELL_WIDTH = 80;
const int MapPieceManager::CELL_HEIGHT = 80;

MapPieceManager::~MapPieceManager() {}

MapPieceManager* MapPieceManager::create() {
    MapPieceManager *ret = new MapPieceManager();
    if (ret != NULL && ret->init()) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return NULL;
}

bool MapPieceManager::init() {
    return true;
}

void MapPieceManager::makeMapForNode(CCNode* node) {
    CCAssert(node != NULL, "指定されたノードが存在しない。");

    // マップピース管理配列
    m_mapPieceMatrix = CCArray::create();
    CCAssert(m_mapPieceMatrix != NULL, "配列の生成に失敗した。");

    // ダミーのマップデータ
    int dammyMapData[][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    // マップデータの長さ取得
    const int lineNum = sizeof dammyMapData /sizeof dammyMapData[0];
    const int columnNum = sizeof dammyMapData[0] /sizeof dammyMapData[0][0];

    for (int i = 0; i < lineNum; i++) {
        // 1列あたりのオブジェクト群を格納する
        CCArray* linePieces = CCArray::create();
        CCAssert(m_mapPieceMatrix != NULL, "配列の生成に失敗した。");

        for (int j = 0; j < columnNum; j++) {
            // マップデータからピース生成に必要な情報を生成
            int mapData = dammyMapData[i][j];
            PieceData pieceData = PieceData(mapData);

            // マップピースオブジェクトの生成
            MapPiece* mapObject = MapPieceFactory::create(pieceData.getPieceType(), pieceData.getImageType());
            CCAssert(mapObject != NULL, "マップピースオブジェクトの生成に失敗した。");

            // 座標の設定
            mapObject->setPosition(ccp(i * CELL_WIDTH, j * CELL_HEIGHT));
            node->addChild(mapObject);

            // マップピースオブジェクトを追加
            linePieces->addObject(mapObject);
        }

        // 1列あたりのオブジェクト群をマップピース管理配列に追加
        m_mapPieceMatrix->addObject(linePieces);
    }

}

CCArray* MapPieceManager::getAllMapPieces() {
    CCArray* mapPieces = CCArray::create();
    CCAssert(mapPieces != NULL, "配列の生成に失敗した。");

    CCObject* mapLineObj = NULL;
    CCARRAY_FOREACH(m_mapPieceMatrix, mapLineObj) {
        CCArray* mapLine = NULL;
        mapLine = dynamic_cast<CCArray*>(mapLineObj);
        CCAssert(mapLine != NULL, "マップ管理配列内のデータがオブジェクト配列でない。");

        CCObject* mapPieceObj = NULL;
        CCARRAY_FOREACH(mapLine, mapPieceObj) {
            MapPiece* mapPiece = NULL;
            mapPiece = dynamic_cast<MapPiece*>(mapPieceObj);
            CCAssert(mapLine != NULL, "マップピースオブジェクト配列内のデータがマップピースでない。");

            mapPieces->addObject(mapPiece);
        }
    }

    return mapPieces;
}
