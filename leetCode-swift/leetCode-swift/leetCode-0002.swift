//
//  leetCode-0002.swift
//  leetCode-swift
//
//  Created by liyoucheng on 2018/11/21.
//  Copyright © 2018年 齐家科技. All rights reserved.
//

import Foundation

func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
    var t1 = l1;
    var t2 = l2;
    let root = ListNode(0)
    var p = root;
    
    var carry = 0;
    while (t1 != nil) || (t2 != nil) {
        
        let x = t1?.val ?? 0
        let y = t2?.val ?? 0
        let sum = x + y + carry
        
        t1 = t1?.next
        t2 = t2?.next
        
        let temp = ListNode(sum % 10)
        carry = sum / 10
        
        p.next = temp
        p = temp;
    }
    
    if carry == 1 {
        let temp = ListNode(1)
        
        p.next = temp
        p = temp;
    }
    
    return root.next
}

func createNode(nums: [Int]) -> ListNode? {
    let root = ListNode(0)
    var p = root
    
    for (_, num) in nums.enumerated() {
        let temp = ListNode(num)
        
        p.next = temp
        p = temp
    }
    
    return root.next
}
//, terminator: <#T##String#>
func printNode( node: ListNode?) {
    var p = node
    while (p != nil) {
        print(p!.val, terminator: "")
        if p?.next != nil {
            print("->", terminator: "")
        }
        p = p?.next
    }
    print("")
}

func test_0002() {
    let l1 = createNode(nums: [2, 4, 3])
    printNode(node: l1)
    let l2 = createNode(nums: [5, 6, 4])
    printNode(node: l2)
    let ret = addTwoNumbers(l1, l2)
    printNode(node: ret)
}
