//
//  SGDemuxable.h
//  SGPlayer iOS
//
//  Created by Single on 2018/9/25.
//  Copyright © 2018 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGDemuxerOptions.h"
#import "SGPacket.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SGDemuxableDelegate;

@protocol SGDemuxable <NSObject>

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy) SGDemuxerOptions *options;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, weak) id<SGDemuxableDelegate> delegate;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSArray<SGTrack *> *tracks;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy, readonly, nullable) NSArray<SGTrack *> *finishedTracks;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSDictionary *metadata;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, readonly) CMTime duration;

/**
 *
 */
- (nullable id<SGDemuxable>)sharedDemuxer;

/**
 *
 */
- (nullable NSError *)open;

/**
 *
 */
- (nullable NSError *)close;

/**
 *
 */
- (nullable NSError *)seekable;

/**
 *
 */
- (nullable NSError *)seekToTime:(CMTime)time;

/**
 *
 */
- (nullable NSError *)seekToTime:(CMTime)time toleranceBefor:(CMTime)toleranceBefor toleranceAfter:(CMTime)toleranceAfter;

/**
 *
 */
- (nullable NSError *)nextPacket:(SGPacket *_Nullable*_Nullable)packet;

@end

@protocol SGDemuxableDelegate <NSObject>

/**
 *
 */
- (BOOL)demuxableShouldAbortBlockingFunctions:(id<SGDemuxable>)demuxable;

@end

NS_ASSUME_NONNULL_END
