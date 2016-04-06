//
//  PATabbarView.h
//
//  Created by Inba on 2016/03/05.
//  Copyright (c) 2016年 Inba. All rights reserved.
//

#import <UIKit/UIKit.h>


@class PATabbarView;
@class PATabbarPushedView;

@protocol PATabbarViewDelegate <NSObject>

@optional
-(void)finishedAdjustAnimationAtForcusedView:(PATabbarPushedView *)forcusedView;
-(void)deletedLastPushedView;

@end

@interface PATabbarView : UIView

#define PATabbarViewRatioOfEmphasisedWidth 0.9
#define PATabbarViewSumOfEmphasisPushedView 3
#define PATabbarViewSumOfDisplayedView 4

#define PATabbarViewDurationForDeleteAnime 0.3
#define PATabbarViewDurationForRepositionAnime 0.5
#define PATabbarViewLatencyUpToRepositionFromDelete 0.7

@property (weak) NSObject<PATabbarViewDelegate> *delegate;

@property (weak,readonly,nonatomic) PATabbarPushedView *head;//Leftmost PushedView.If not exist It is nil.
@property (weak,readonly,nonatomic) PATabbarPushedView *tail;//Rightmost PushedView.If not exist It is nil.

-(void)addToTailView:(PATabbarPushedView *)view;

/**
 In order near the centerView,It will be set to currentStatus ,first Emphasis,next Displayed and notDisplayed.
 */
-(void)adjustPositionWithAForcusOnView:(PATabbarPushedView *)centerView;

-(void)deleteView:(PATabbarPushedView *)deleteView;
@end