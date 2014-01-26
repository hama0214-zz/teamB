//
//  Variables.h
//  teamB
//
//  Created by cocos2d-x on 2014/01/19.
//
//

#ifndef teamB_Variables_h
#define teamB_Variables_h

class Variables {
public:
    
    // ピースのタイプ
    enum PIECE_TYPE {
        NONE_PIECE  = 0, // 空
        FIELD_PIECE = 1, // フィールド
        ENEMY_PIECE = 2, // 敵
        ITEM_PIECE  = 3  // アイテム
    };
    
    // ピースの画像（画像名自体は書くMapPieceを継承したクラスで指定）
    enum PIECE_IMAGE {
        
        // フィールド画像（名前はまだ適当）
        FIELD_PIECE_IMAGE_0 = 100,
        FIELD_PIECE_IMAGE_1 = 101,
        FIELD_PIECE_IMAGE_2 = 102,
        
        // 敵画像
        ENEMY_PIECE_IMAGE_0 = 200,
        
        // アイテム画像
        ITEM_PIECE_IMAGE_0 = 300,
        ITEM_PIECE_IMAGE_1 = 301,
        ITEM_PIECE_IMAGE_2 = 302
    };
    
};

#endif
