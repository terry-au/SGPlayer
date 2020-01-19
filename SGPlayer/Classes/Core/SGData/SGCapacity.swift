//
//  SGCapacity.swift
//  SGPlayer
//
//  Created by C.W. Betts on 1/18/20.
//  Copyright © 2020 single. All rights reserved.
//

import Foundation

public extension SGCapacity {
    @inlinable static func +(_ lhs: SGCapacity, _ rhs: SGCapacity) -> SGCapacity {
        return SGCapacityAdd(lhs, rhs)
    }
    
    @inlinable static func +=(_ lhs: inout SGCapacity, _ rhs: SGCapacity) {
        lhs = SGCapacityAdd(lhs, rhs)
    }
    
    @inlinable var isEmpty: Bool {
        return SGCapacityIsEmpty(self)
    }
    
    @inlinable var isEnough: Bool {
        return SGCapacityIsEnough(self)
    }
}

extension SGCapacity: Equatable {
    @inlinable public static func == (lhs: SGCapacity, rhs: SGCapacity) -> Bool {
        return SGCapacityIsEqual(lhs, rhs)
    }
}
