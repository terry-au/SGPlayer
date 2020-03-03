//
//  SGMetalProjection.h
//  SGPlayer
//
//  Created by Single on 2019/6/28.
//  Copyright © 2019 single. All rights reserved.
//

#import <Metal/Metal.h>
#import <simd/simd.h>

@interface SGMetalProjection : NSObject

- (instancetype)initWithDevice:(id<MTLDevice>)device;

@property (nonatomic) matrix_float4x4 matrix;
@property (nonatomic, strong) id<MTLDevice> device;
@property (nonatomic, strong) id<MTLBuffer> matrixBuffer;

@end
