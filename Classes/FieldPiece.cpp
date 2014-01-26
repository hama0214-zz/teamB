//
//  FieldPiece.cpp
//  teamB
//
//  Created by Yuto Yoshinari on 2014/01/19.
//
//

#include "FieldPiece.h"

/**
 * FieldPieceを生成するクラスメソッド
 * @static
 * @param {Variables::PIECE_IMAGE} image
 * @return {FieldPiece*}
 */
FieldPiece* FieldPiece::create(Variables::PIECE_IMAGE image) {
    FieldPiece *pobSprite = new FieldPiece();
    if (pobSprite && pobSprite->initWithFile(pobSprite->getPszFileName(image))) {
        pobSprite->pieceImage = image;
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

/**
 * 対象の画像名を返すメソッド
 * @private
 * @param {Variables::PIECE_IMAGE} image
 * @return {const char*}
 */
const char* FieldPiece::getPszFileName(Variables::PIECE_IMAGE image) {
    const char* pszFileName;
    switch (image) {
        case Variables::FIELD_PIECE_IMAGE_0:
            pszFileName = "field_piece_00.png";
            break;
        case Variables::FIELD_PIECE_IMAGE_1:
            pszFileName = "Icon-72.png";
            break;
        case Variables::FIELD_PIECE_IMAGE_2:
            pszFileName = "Icon-72.png";
            break;
        default:
            break;
    }
    return pszFileName;
}

/**
 * コンストラクタ
 */
FieldPiece::FieldPiece() {
    pieceType = Variables::FIELD_PIECE;
}