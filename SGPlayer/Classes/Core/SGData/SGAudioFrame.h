//
//  SGAudioFrame.h
//  SGPlayer
//
//  Created by Single on 2018/1/19.
//  Copyright © 2018年 single. All rights reserved.
//

#import "SGFrame.h"
#import "SGAudioDescriptor.h"

NS_ASSUME_NONNULL_BEGIN

@interface SGAudioFrame : SGFrame

/**
 *
 */
@property (nonatomic, strong, readonly) SGAudioDescriptor *descriptor;

/**
 *
 */
@property (nonatomic, readonly) int numberOfSamples;

/**
 *
 */
@property (readonly) int *linesize NS_RETURNS_INNER_POINTER;

/**
 *
 */
@property (readonly) uint8_t *_Nullable*_Nonnull data NS_RETURNS_INNER_POINTER;

@end

NS_ASSUME_NONNULL_END
