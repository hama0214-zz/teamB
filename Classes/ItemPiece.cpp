//
//  ItemPiece.cpp
//  teamB
//
//  Created by cocos2d-x on 2014/01/26.
//
//

#include "ItemPiece.h"

/**
 * FieldPieceを生成するクラスメソッド
 * @static
 * @param {Variables::PIECE_IMAGE} image
 * @return {FieldPiece*}
 */
ItemPiece* ItemPiece::create(Variables::PIECE_IMAGE image) {
    ItemPiece *pobSprite = new ItemPiece();
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
const char* ItemPiece::getPszFileName(Variables::PIECE_IMAGE image) {
    const char* pszFileName;
    switch (image) {
        case Variables::ITEM_PIECE_IMAGE_0:
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
ItemPiece::ItemPiece() {
    isUsed = false;
    pieceType = Variables::ITEM_PIECE;
}

/**
 * アイテムを使用する際に呼ばれるメソッド
 */
void ItemPiece::use() {
    isUsed = true;
    
    // 見た目上画面から消す
    CCScaleTo* action1 = CCScaleTo::create(1, 0.0f);
    runAction(action1);
    
    // Todo: 効果を発動する
}