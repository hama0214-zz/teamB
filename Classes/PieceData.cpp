//
//  PieceData.cpp
//  teamB
//
//  Created by C15 川辺兼嗣 on 2014/02/02.
//
//

#include "PieceData.h"

PieceData* PieceData::create(int dataValue) {
    PieceData *ret = new PieceData();
    if (ret != NULL && ret->init(dataValue)) {
        ret->autorelease();
        return ret;
    }
    
    CC_SAFE_DELETE(ret);
    return NULL;
}

bool PieceData::init(int dataValue) {
    // 上2桁をピースタイプとして扱う
    m_pieceType = convertToPieceType(dataValue / 100);
    
    // 下2桁を画像タイプとして扱う
    m_imageType = convertToImageType(dataValue % 100);
    
    return true;
}

Variables::PIECE_TYPE PieceData::convertToPieceType(int pieceTypeValue) {
    switch (pieceTypeValue) {
        case 0:
            // TODO: 空白のマスオブジェクトタイプを返す。現状フィールドタイプを返している。
            return Variables::FIELD_PIECE;
        case 1:
            return Variables::FIELD_PIECE;
        case 2:
            return Variables::ITEM_PIECE;
        default:
            CCAssert(false, "不正な数を指定された。");
            break;
    }
}

Variables::PIECE_IMAGE PieceData::convertToImageType(int imageTypeValue) {
    switch (imageTypeValue) {
        case 0:
            // TODO: 空白の画像タイプを返す。現状フィールド画像タイプを返している。
            return Variables::FIELD_PIECE_IMAGE_0;
        case 1:
            return Variables::FIELD_PIECE_IMAGE_1;
        case 2:
            return Variables::FIELD_PIECE_IMAGE_2;
        case 3:
            return Variables::ITEM_PIECE_IMAGE_0;
        case 4:
            return Variables::ITEM_PIECE_IMAGE_1;
        case 5:
            return Variables::ITEM_PIECE_IMAGE_2;
        default:
            CCAssert(false, "不正な数を指定された。");
            break;
    }
}
