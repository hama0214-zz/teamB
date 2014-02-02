//
//  MapPieceManager.cpp
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/01/19.
//
//

#include "MapPieceManager.h"
#include "MapPieceFactory.h"
#include "MapPiece.h"
#include "PieceData.h"
#include "EmptyPiece.h"

const int MapPieceManager::CELL_WIDTH = 80;
const int MapPieceManager::CELL_HEIGHT = 80;
const int MapPieceManager::MAP_HEIGHT = 8;

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

void MapPieceManager::makeMapForNode(CCNode* mapNode) {
    CCAssert(mapNode != NULL, "指定されたノードが存在しない。");

    // マップピース管理配列
    m_mapPieceMatrix = CCArray::create();
    CCAssert(m_mapPieceMatrix != NULL, "配列の生成に失敗した。");
    CC_SAFE_RETAIN(m_mapPieceMatrix);

    // ダミーのマップデータ。ゆくゆくは外部ツールで作りたいが、時間次第ではここで手打ちになるかもしれない。
    int dammyMapData[MAP_HEIGHT][100] = {
        
        {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        
        {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0,   0,   0, 200, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0, 200, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        {  0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        
        {  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 200,   0,   0,   0, 200,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0 },
        {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 },
        {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 }
    };
    
    // マップデータの横の長さ取得
    const int columnNum = sizeof dammyMapData[0] /sizeof dammyMapData[0][0];
    // マップデータの縦の長さ取得
    const int lineNum = sizeof dammyMapData /sizeof dammyMapData[0];

    for (int i = 0; i < columnNum; i++) {
        // 1列あたりのオブジェクト群を格納する
        CCArray* linePieces = CCArray::create();
        CCAssert(m_mapPieceMatrix != NULL, "配列の生成に失敗した。");

        // 1列あたりのマップデータ群を格納する
        std::vector<int> linedatas;

        for (int j = lineNum - 1; j >= 0; j--) {
            // マップデータからピース生成に必要な情報を生成
            int mapData = dammyMapData[j][i];
            PieceData* pieceData = PieceData::create(mapData);

            // マップピースオブジェクトの生成
            MapPiece* mapObject = MapPieceFactory::create(pieceData->getPieceType(), pieceData->getImageType());
            CCAssert(mapObject != NULL, "マップピースオブジェクトの生成に失敗した。");

            // 空のマップピースの場合、設置はせず、データだけ追加する。
            if (mapObject == EmptyPiece::getInstese()) {
                // マップピースオブジェクトを追加
                linePieces->addObject(mapObject);
                // マップデータを追加
                linedatas.push_back(mapData);
                continue;
            }

            // 座標の設定
            mapObject->setPosition(ccp(i * CELL_WIDTH, (lineNum - 1 - j) * CELL_HEIGHT));
            mapNode->addChild(mapObject);

            // マップピースオブジェクトを追加
            linePieces->addObject(mapObject);

            // マップデータを追加
            linedatas.push_back(mapData);
        }

        // 1列あたりのオブジェクト群をマップピース管理配列に追加
        m_mapPieceMatrix->addObject(linePieces);

        // 1列あたりのマップデータ群をマップデータ管理配列に追加
        m_mapDatas.push_back(linedatas);
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
            CCAssert(mapPiece != NULL, "マップピースオブジェクト配列内のデータがマップピースでない。");

            // 空オブジェクトは飛ばす
            if (mapPiece == EmptyPiece::getInstese()) {
                continue;
            }

            mapPieces->addObject(mapPiece);
        }
    }

    return mapPieces;
}

void MapPieceManager::removeLastLineMapPieces(CCObject* mapNodeObj) {
    CCAssert(mapNodeObj != NULL, "指定されたオブジェクトが存在しない。");

    CCNode* mapNode = dynamic_cast<CCNode*>(mapNodeObj);
    CCAssert(mapNode != NULL, "指定されたオブジェクトがノードでない。");

    CCArray* mapLine = dynamic_cast<CCArray*>(m_mapPieceMatrix->objectAtIndex(0));
    CCAssert(mapLine != NULL, "マップピースオブジェクト管理配列内のデータがオブジェクト配列でない。");

    // オブジェクトを削除するので、配列の後ろからfor文をまわす
    for (int i = MapPieceManager::MAP_HEIGHT - 1; i >= 0; i--) {
        MapPiece* mapPiece = dynamic_cast<MapPiece*>(mapLine->objectAtIndex(i));
        CCAssert(mapPiece != NULL, "オブジェクト配列内のデータがマップピースでない。");

        // 空オブジェクトは飛ばす
        if (mapPiece == EmptyPiece::getInstese()) {
            mapLine->removeObjectAtIndex(i);
            continue;
        }

        mapNode->removeChild(mapPiece);
        mapLine->removeObject(mapPiece);
    }

    m_mapPieceMatrix->removeObject(mapLine);
}
