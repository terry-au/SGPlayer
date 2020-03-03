//
//  SGAudioPlayer.h
//  SGPlayer
//
//  Created by Single on 2018/1/16.
//  Copyright © 2018年 single. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

@class SGAudioPlayer;

@protocol SGAudioPlayerDelegate <NSObject>

/**
 *
 */
- (void)audioPlayer:(SGAudioPlayer *)player render:(const AudioTimeStamp *)timeStamp data:(AudioBufferList *)data numberOfFrames:(UInt32)numberOfFrames;

@optional
/**
 *
 */
- (void)audioPlayer:(SGAudioPlayer *)player willRender:(const AudioTimeStamp *)timestamp;

/**
 *
 */
- (void)audioPlayer:(SGAudioPlayer *)player didRender:(const AudioTimeStamp *)timestamp;

@end

@interface SGAudioPlayer : NSObject

/**
 *  Delegate.
 */
@property (NS_NONATOMIC_IOSONLY, weak) id<SGAudioPlayerDelegate> delegate;

/**
 *  Rate.
 */
@property (NS_NONATOMIC_IOSONLY) float rate;

/**
 *  Pitch.
 */
@property (NS_NONATOMIC_IOSONLY) float pitch;

/**
 *  Volume.
 */
@property (NS_NONATOMIC_IOSONLY) float volume;

/**
 *  ASBD.
 */
@property (NS_NONATOMIC_IOSONLY) AudioStreamBasicDescription asbd;

/**
 *  Playback.
 */
@property (NS_NONATOMIC_IOSONLY, readonly, getter=isPlaying) BOOL playing;

/**
 *  Play.
 */
- (void)play;

/**
 *  Pause.
 */
- (void)pause;

/**
 *  Flush.
 */
- (void)flush;

@end
