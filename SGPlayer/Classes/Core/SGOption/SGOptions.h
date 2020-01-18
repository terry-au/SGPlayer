//
//  SGOptions.h
//  SGPlayer iOS
//
//  Created by Single on 2018/10/29.
//  Copyright © 2018 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGProcessorOptions.h"
#import "SGDecoderOptions.h"
#import "SGDemuxerOptions.h"

NS_ASSUME_NONNULL_BEGIN

@interface SGOptions : NSObject <NSCopying>

/*!
 @property sharedOptions
 @abstract
    Globally shared configuration options.
 */
@property (class, strong, readonly) SGOptions *sharedOptions;

/*!
 @property demuxer
 @abstract
    The options for demuxer.
 */
@property (nonatomic, strong) SGDemuxerOptions *demuxer;

/*!
 @property decoder
 @abstract
    The options for decoder.
 */
@property (nonatomic, strong) SGDecoderOptions *decoder;

/*!
 @property processor
 @abstract
    The options for processor.
 */
@property (nonatomic, strong) SGProcessorOptions *processor;

@end

NS_ASSUME_NONNULL_END
