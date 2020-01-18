//
//  SGMetalRenderPipeline.h
//  MetalTest
//
//  Created by Single on 2019/6/26.
//  Copyright © 2019 Single. All rights reserved.
//

#import <Metal/Metal.h>

NS_ASSUME_NONNULL_BEGIN

@interface SGMetalRenderPipeline : NSObject

- (instancetype)initWithDevice:(id<MTLDevice>)device library:(id<MTLLibrary>)library;

@property (nonatomic, strong) id<MTLDevice> device;
@property (nonatomic, strong) id<MTLLibrary> library;
@property (nonatomic, strong, nullable) id<MTLRenderPipelineState> state;
@property (nonatomic, strong, nullable) MTLRenderPipelineDescriptor *descriptor;

@end

NS_ASSUME_NONNULL_END
