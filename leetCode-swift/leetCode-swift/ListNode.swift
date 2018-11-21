//
//  ListNode.swift
//  leetCode-swift
//
//  Created by liyoucheng on 2018/11/21.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

import Foundation

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}
