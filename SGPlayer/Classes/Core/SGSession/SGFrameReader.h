//
//  SGFrameReader.h
//  SGPlayer
//
//  Created by Single on 2019/11/12.
//  Copyright © 2019 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGDemuxerOptions.h"
#import "SGDecoderOptions.h"
#import "SGAsset.h"
#import "SGFrame.h"

@protocol SGFrameReaderDelegate;

@interface SGFrameReader : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 *
 */
- (instancetype)initWithAsset:(SGAsset *)asset;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy) SGDemuxerOptions *demuxerOptions;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy) SGDecoderOptions *decoderOptions;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, weak) id<SGFrameReaderDelegate> delegate;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSArray<SGTrack *> *tracks;

/**
 *
 */
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSArray<SGTrack *> *selectedTracks;

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
- (NSError *)open;

/**
 *
 */
- (NSError *)close;

/**
 *
 */
- (NSError *)seekable;

/**
 *
 */
- (NSError *)seekToTime:(CMTime)time;

/**
 *
 */
- (NSError *)seekToTime:(CMTime)time toleranceBefor:(CMTime)toleranceBefor toleranceAfter:(CMTime)toleranceAfter;

/**
 *
 */
- (NSError *)selectTracks:(NSArray<SGTrack *> *)tracks;

/**
 *
 */
- (NSError *)nextFrame:(__kindof SGFrame **)frame;

@end

@protocol SGFrameReaderDelegate <NSObject>

/**
 *
 */
- (BOOL)frameReaderShouldAbortBlockingFunctions:(SGFrameReader *)frameReader;

@end
