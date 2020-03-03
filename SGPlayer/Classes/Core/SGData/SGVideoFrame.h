//
//  SGVideoFrame.h
//  SGPlayer
//
//  Created by Single on 2018/1/22.
//  Copyright © 2018年 single. All rights reserved.
//

#import "SGFrame.h"
#import "SGPLFImage.h"
#import "SGVideoDescriptor.h"

NS_ASSUME_NONNULL_BEGIN

@interface SGVideoFrame : SGFrame

/**
 *
 */
@property (nonatomic, strong, readonly) SGVideoDescriptor *descriptor;

/**
 *
 */
@property (readonly) int *linesize NS_RETURNS_INNER_POINTER;

/**
 *
 */
@property (readonly) uint8_t *_Nullable*_Nonnull data NS_RETURNS_INNER_POINTER;

/**
 *
 */
@property (readonly, nullable) CVPixelBufferRef pixelBuffer;

/**
 *
 */
- (nullable SGPLFImage *)image;

@end

NS_ASSUME_NONNULL_END
