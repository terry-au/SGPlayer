//
//  SGVector.h
//  SGPlayer
//
//  Created by C.W. Betts on 3/2/20.
//  Copyright © 2020 single. All rights reserved.
//

#ifndef SGVector_h
#define SGVector_h

#include <simd/simd.h>

static inline float SGDegreesToRadians(float degrees) { return degrees * (M_PI / 180); };

static inline matrix_float4x4 SGMatrix4x4MakeLookAt(float eyeX, float eyeY, float eyeZ,
                                                    float centerX, float centerY, float centerZ,
                                                    float upX, float upY, float upZ)
{
    vector_float3 ev = { eyeX, eyeY, eyeZ };
    vector_float3 cv = { centerX, centerY, centerZ };
    vector_float3 uv = { upX, upY, upZ };
    vector_float3 n = vector_normalize(ev + -cv);
    vector_float3 u = vector_normalize(vector_cross(uv, n));
    vector_float3 v = vector_cross(n, u);
    
    matrix_float4x4 m = simd_matrix((vector_float4){ u[0], v[0], n[0], 0.0f},
                     (vector_float4){u[1], v[1], n[1], 0.0f},
                     (vector_float4){u[2], v[2], n[2], 0.0f},
                     (vector_float4){vector_dot(-u, ev),
                     vector_dot(-v, ev),
                     vector_dot(-n, ev),
                     1.0f });
    
    return m;
}

static inline matrix_float4x4 SGMatrix4x4MakePerspective(float fovyRadians, float aspect, float nearZ, float farZ)
{
    float cotan = 1.0f / tan(fovyRadians / 2.0f);
    
    matrix_float4x4 m = simd_matrix((vector_float4){cotan / aspect, 0.0f, 0.0f, 0.0f},
                     (vector_float4){0.0f, cotan, 0.0f, 0.0f},
                     (vector_float4){0.0f, 0.0f, (farZ + nearZ) / (nearZ - farZ), -1.0f},
                     (vector_float4){0.0f, 0.0f, (2.0f * farZ * nearZ) / (nearZ - farZ), 0.0f});
    
    return m;
}

static inline matrix_float4x4 SGMatrix4x4MakeXRotation(float radians)
{
    float cos = cos(radians);
    float sin = sin(radians);
    
    matrix_float4x4 m = simd_matrix((vector_float4){ 1.0f, 0.0f, 0.0f, 0.0f},
        (vector_float4){0.0f, cos, sin, 0.0f},
        (vector_float4){0.0f, -sin, cos, 0.0f},
        (vector_float4){0.0f, 0.0f, 0.0f, 1.0f});
    
    return m;
}

static inline matrix_float4x4 SGMatrix4x4MakeYRotation(float radians)
{
    float cos = cos(radians);
    float sin = sin(radians);
    
    matrix_float4x4 m = simd_matrix((vector_float4){cos, 0.0f, -sin, 0.0f},
                     (vector_float4){0.0f, 1.0f, 0.0f, 0.0f},
                     (vector_float4){sin, 0.0f, cos, 0.0f},
                     (vector_float4){0.0f, 0.0f, 0.0f, 1.0f});
    
    return m;
}

static inline matrix_float4x4 SGMatrix4x4MakeZRotation(float radians)
{
    float cos = cos(radians);
    float sin = sin(radians);
    
    matrix_float4x4 m = simd_matrix((vector_float4){cos, sin, 0.0f, 0.0f},
        (vector_float4){-sin, cos, 0.0f, 0.0f},
        (vector_float4){0.0f, 0.0f, 1.0f, 0.0f},
        (vector_float4){0.0f, 0.0f, 0.0f, 1.0f});
    
    return m;
}

static inline matrix_float4x4 SGMatrix4x4RotateX(matrix_float4x4 matrix, float radians)
{
    matrix_float4x4 rm = SGMatrix4x4MakeXRotation(radians);
    return matrix_multiply (matrix, rm);
}

static inline matrix_float4x4 SGMatrix4x4RotateY(matrix_float4x4 matrix, float radians)
{
    matrix_float4x4 rm = SGMatrix4x4MakeYRotation(radians);
    return matrix_multiply(matrix, rm);
}

static inline matrix_float4x4 SGMatrix4x4RotateZ(matrix_float4x4 matrix, float radians)
{
    matrix_float4x4 rm = SGMatrix4x4MakeZRotation(radians);
    return matrix_multiply(matrix, rm);
}

#endif /* SGVector_h */
