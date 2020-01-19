//
//  SGRenderable.h
//  SGPlayer
//
//  Created by Single on 2018/1/19.
//  Copyright © 2018年 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGCapacity.h"
#import "SGFrame.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SGRenderableDelegate;

/**
 *
 */
typedef NS_ENUM(NSUInteger, SGRenderableState) {
    SGRenderableStateNone      = 0,
    SGRenderableStateRendering = 1,
    SGRenderableStatePaused    = 2,
    SGRenderableStateFinished  = 3,
    SGRenderableStateFailed    = 4,
};

@protocol SGRenderable <NSObject>

/**
 *
 */
@property (nonatomic, weak) id<SGRenderableDelegate> delegate;

/**
 *
 */
@property (nonatomic, readonly) SGRenderableState state;

/**
 *
 */
@property (nonatomic, readonly) SGCapacity capacity;

/**
 *
 */
- (BOOL)open;

/**
 *
 */
- (BOOL)close;

/**
 *
 */
- (BOOL)pause;

/**
 *
 */
- (BOOL)resume;

/**
 *
 */
- (BOOL)flush;

/**
 *
 */
- (BOOL)finish;

@end

@protocol SGRenderableDelegate <NSObject>

/**
 *
 */
- (void)renderable:(id<SGRenderable>)renderable didChangeState:(SGRenderableState)state;

/**
 *
 */
- (void)renderable:(id<SGRenderable>)renderable didChangeCapacity:(SGCapacity)capacity;

/**
 *
 */
- (__kindof SGFrame *_Nullable)renderable:(id<SGRenderable>)renderable fetchFrame:(nullable SGTimeReader)timeReader;

@end

NS_ASSUME_NONNULL_END
