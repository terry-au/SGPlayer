//
//  SGVRProjection.m
//  SGPlayer iOS
//
//  Created by Single on 2018/8/23.
//  Copyright © 2018 single. All rights reserved.
//

#import "SGVRProjection.h"
#import "SGPLFTargets.h"
#if SGPLATFORM_TARGET_OS_IPHONE
#import "SGMotionSensor.h"
#endif
#import "SGVector.h"

@interface SGVRProjection ()

#if SGPLATFORM_TARGET_OS_IPHONE
@property (nonatomic, strong) SGMotionSensor * sensor;
#endif
@property (nonatomic) matrix_float4x4 lastMatrix11;
@property (nonatomic) matrix_float4x4 lastMatrix21;
@property (nonatomic) matrix_float4x4 lastMatrix22;
@property (nonatomic) BOOL lastMatrix1Available;
@property (nonatomic) BOOL lastMatrix2Available;

@end

@implementation SGVRProjection

- (instancetype)init
{
    if (self = [super init]) {
        self.viewport = [[SGVRViewport alloc] init];
    }
    return self;
}

- (void)dealloc
{
    [self stop];
}

- (void)start
{
#if SGPLATFORM_TARGET_OS_IPHONE
    if (!self.sensor) {
        self.sensor = [[SGMotionSensor alloc] init];
        [self.sensor start];
    }
#endif
}

- (void)stop
{
#if SGPLATFORM_TARGET_OS_IPHONE
    if (self.sensor) {
        [self.sensor stop];
        self.sensor = nil;
        self.lastMatrix1Available = NO;
        self.lastMatrix2Available = NO;
    }
#endif
}

- (BOOL)ready
{
#if SGPLATFORM_TARGET_OS_IPHONE
    if (self.viewport.sensorEnable) {
        [self start];
        return self.sensor.ready;
    }
#endif
    return YES;
}

- (BOOL)matrixWithAspect:(Float64)aspect matrix1:(matrix_float4x4 *)matrix1
{
#if SGPLATFORM_TARGET_OS_IPHONE
    if (self.viewport.sensorEnable) {
        [self start];
        if (!self.sensor.ready) {
            if (self.lastMatrix1Available) {
                * matrix1 = self.lastMatrix11;
                return YES;
            }
            return NO;
        }
    }
#endif
    matrix_float4x4 modelMatrix = matrix_identity_float4x4;
    modelMatrix = SGMatrix4x4RotateX(modelMatrix, SGDegreesToRadians(self.viewport.y) * (self.viewport.flipY ? -1 : 1));
#if SGPLATFORM_TARGET_OS_IPHONE
    if (self.viewport.sensorEnable) {
        modelMatrix = matrix_multiply(modelMatrix, self.sensor.matrix);
    }
#endif
    modelMatrix = SGMatrix4x4RotateY(modelMatrix, SGDegreesToRadians(self.viewport.x) * (self.viewport.flipX ? -1 : 1));
    matrix_float4x4 viewMatrix = SGMatrix4x4MakeLookAt(0, 0, 0.0, 0, 0, -1000, 0, 1, 0);
    matrix_float4x4 projectionMatrix = SGMatrix4x4MakePerspective(SGDegreesToRadians(self.viewport.degress), aspect, 0.1f, 400.0f);
    matrix_float4x4 modelViewProjectionMatrix = matrix_multiply(projectionMatrix, viewMatrix);
    modelViewProjectionMatrix = matrix_multiply(modelViewProjectionMatrix, modelMatrix);
    *matrix1 = modelViewProjectionMatrix;
    self.lastMatrix1Available = YES;
    self.lastMatrix11 = modelViewProjectionMatrix;
    return YES;
}

- (BOOL)matrixWithAspect:(Float64)aspect matrix1:(matrix_float4x4 *)matrix1 matrix2:(matrix_float4x4 *)matrix2
{
#if SGPLATFORM_TARGET_OS_IPHONE
    if (self.viewport.sensorEnable) {
        [self start];
        if (!self.sensor.ready) {
            if (self.lastMatrix2Available) {
                * matrix1 = self.lastMatrix21;
                * matrix2 = self.lastMatrix22;
                return YES;
            }
            return NO;
        }
    }
#endif
    float distance = 0.012;
    matrix_float4x4 modelMatrix = matrix_identity_float4x4;
    modelMatrix = SGMatrix4x4RotateX(modelMatrix, SGDegreesToRadians(self.viewport.y) * (self.viewport.flipY ? -1 : 1));
#if SGPLATFORM_TARGET_OS_IPHONE
    if (self.viewport.sensorEnable) {
        modelMatrix = matrix_multiply(modelMatrix, self.sensor.matrix);
    }
#endif
    matrix_float4x4 leftViewMatrix = SGMatrix4x4MakeLookAt(-distance, 0, 0.0, 0, 0, -1000, 0, 1, 0);
    matrix_float4x4 rightViewMatrix = SGMatrix4x4MakeLookAt(distance, 0, 0.0, 0, 0, -1000, 0, 1, 0);
    matrix_float4x4 projectionMatrix = SGMatrix4x4MakePerspective(SGDegreesToRadians(self.viewport.degress), aspect, 0.1f, 400.0f);
    matrix_float4x4 modelViewProjectionMatrix1 = matrix_multiply(projectionMatrix, leftViewMatrix);
    matrix_float4x4 modelViewProjectionMatrix2 = matrix_multiply(projectionMatrix, rightViewMatrix);
    modelViewProjectionMatrix1 = matrix_multiply(modelViewProjectionMatrix1, modelMatrix);
    modelViewProjectionMatrix2 = matrix_multiply(modelViewProjectionMatrix2, modelMatrix);
    *matrix1 = modelViewProjectionMatrix1;
    *matrix2 = modelViewProjectionMatrix2;
    self.lastMatrix2Available = YES;
    self.lastMatrix21 = modelViewProjectionMatrix1;
    self.lastMatrix22 = modelViewProjectionMatrix2;
    return YES;
}

@end
