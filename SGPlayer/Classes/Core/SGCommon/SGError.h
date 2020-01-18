//
//  SGError.h
//  SGPlayer
//
//  Created by Single on 2018/1/16.
//  Copyright © 2018年 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGDefines.h"

NS_ASSUME_NONNULL_BEGIN

SGPLAYER_EXTERN NSErrorDomain const SGErrorDomain;
SGPLAYER_EXTERN NSErrorUserInfoKey const SGErrorUserInfoKeyOperation;

typedef NS_ERROR_ENUM(SGErrorDomain, SGErrorCode) {
    SGErrorCodeUnknown = 0,
    SGErrorImmediateExitRequested,
    SGErrorCodeNoValidFormat,
    SGErrorCodeFormatNotSeekable,
    SGErrorCodePacketOutputCancelSeek,
    SGErrorCodeDemuxerEndOfFile,
    SGErrorCodeInvlidTime,
};

typedef NS_ENUM(NSUInteger, SGActionCode) {
    SGActionCodeUnknown = 0,
    SGActionCodeFormatCreate,
    SGActionCodeFormatOpenInput,
    SGActionCodeFormatFindStreamInfo,
    SGActionCodeFormatSeekFrame,
    SGActionCodeFormatReadFrame,
    SGActionCodeFormatGetSeekable,
    SGActionCodeCodecSetParametersToContext,
    SGActionCodeCodecOpen2,
    SGActionCodePacketOutputSeek,
    SGActionCodeURLDemuxerFunnelNext,
    SGActionCodeMutilDemuxerNext,
    SGActionCodeSegmentDemuxerNext,
    SGActionCodeNextFrame,
};

SGPLAYER_EXTERN NSError *_Nullable SGGetFFError(int result, SGActionCode operation);
SGPLAYER_EXTERN NSError * SGCreateError(NSUInteger code, SGActionCode operation);

NS_ASSUME_NONNULL_END
