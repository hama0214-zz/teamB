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
        FIELD_PIECE = 0,  // フィールド
        ITEM_PIECE  = 1   // アイテム
    };
    
    // ピースの画像（画像名自体は書くMapPieceを継承したクラスで指定）
    enum PIECE_IMAGE {
        
        // フィールド画像（名前はまだ適当）
        FIELD_PIECE_IMAGE_0 = 0,
        FIELD_PIECE_IMAGE_1 = 1,
        FIELD_PIECE_IMAGE_2 = 2,
        
        // アイテム画像
        ITEM_PIECE_IMAGE_0 = 100,
        ITEM_PIECE_IMAGE_1 = 101,
        ITEM_PIECE_IMAGE_2 = 102
    };
    
    // アイテムの画像
    enum ITEM_PIECE_IMAGE {
    };
    
};

#endif
