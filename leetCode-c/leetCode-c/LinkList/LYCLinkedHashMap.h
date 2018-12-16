//
//  LYCLinkedHashMap.h
//  leetCode-c
//
//  Created by liyoucheng on 2018/12/10.
//  Copyright © 2018年 Giga. All rights reserved.
//

#ifndef LYCLinkedHashMap_h
#define LYCLinkedHashMap_h

#include <stdio.h>
//
//// 双向链表节点
//struct list_head {
//    struct list_head *next, *prev;
//};
//
//// 初始化节点：设置name节点的前继节点和后继节点都是指向name本身。
//#define LIST_HEAD_INIT(name) { &(name), &(name) }
//
//// 定义表头(节点)：新建双向链表表头name，并设置name的前继节点和后继节点都是指向name本身。
//#define LIST_HEAD(name) \
//struct list_head name = LIST_HEAD_INIT(name)
//
//// 初始化节点：将list节点的前继节点和后继节点都是指向list本身。
//static inline void INIT_LIST_HEAD(struct list_head *list)
//{
//    list->next = list;
//    list->prev = list;
//}
//
//// 添加节点：将new插入到prev和next之间。
//static inline void __list_add(struct list_head *new,
//                              struct list_head *prev,
//                              struct list_head *next)
//{
//    next->prev = new;
//    new->next = next;
//    new->prev = prev;
//    prev->next = new;
//}
//
//// 添加new节点：将new添加到head之后，是new称为head的后继节点。
//static inline void list_add(struct list_head *new, struct list_head *head)
//{
//    __list_add(new, head, head->next);
//}
//
//// 添加new节点：将new添加到head之前，即将new添加到双链表的末尾。
//static inline void list_add_tail(struct list_head *new, struct list_head *head)
//{
//    __list_add(new, head->prev, head);
//}
//
//// 从双链表中删除entry节点。
//static inline void __list_del(struct list_head * prev, struct list_head * next)
//{
//    next->prev = prev;
//    prev->next = next;
//}
//
//// 从双链表中删除entry节点。
//static inline void list_del(struct list_head *entry)
//{
//    __list_del(entry->prev, entry->next);
//}
//
//// 从双链表中删除entry节点。
//static inline void __list_del_entry(struct list_head *entry)
//{
//    __list_del(entry->prev, entry->next);
//}
//
//// 从双链表中删除entry节点，并将entry节点的前继节点和后继节点都指向entry本身。
//static inline void list_del_init(struct list_head *entry)
//{
//    __list_del_entry(entry);
//    INIT_LIST_HEAD(entry);
//}
//
//// 用new节点取代old节点
//static inline void list_replace(struct list_head *old,
//                                struct list_head *new)
//{
//    new->next = old->next;
//    new->next->prev = new;
//    new->prev = old->prev;
//    new->prev->next = new;
//}
//
//// 双链表是否为空
//static inline int list_empty(const struct list_head *head)
//{
//    return head->next == head;
//}
//
//// 获取"MEMBER成员"在"结构体TYPE"中的位置偏移
//#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
//
//// 根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针
//#define container_of(ptr, type, member) ({          \
//const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
//(type *)( (char *)__mptr - offsetof(type,member) );})
//
//// 遍历双向链表
//#define list_for_each(pos, head) \
//for (pos = (head)->next; pos != (head); pos = pos->next)
//
//#define list_for_each_safe(pos, n, head) \
//for (pos = (head)->next, n = pos->next; pos != (head); \
//pos = n, n = pos->next)
//
//#define list_entry(ptr, type, member) \
//container_of(ptr, type, member)
//
//#pragma mark - 实现
//
//
///*数据存放节点*/
//typedef struct _lisked_hash_map_node
//{
//    void *key; /*键*/
//    void *data; /*数据*/
//    struct _lisked_hash_map_node *next; /*哈希冲突时，用来挂接后续节点*/
//    struct list_head Dlist_node;/*用来挂接双向链表*/
//}LiskedHashMapNode;
//
//typedef struct _lisked_hash_map
//{
//    LiskedHashMapNode **hTabs;/*哈希桶*/
//    struct list_head header;/*双向循环链表头*/
//    int size; /**/
//    int nel_max; /*支持最大节点数*/
//    int nel;   /*当前节点数*/
//    int (*hash_value)(struct _lisked_hash_map *h,const void *key); /*哈希函数*/
//    int (*keycmp)(struct _lisked_hash_map *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
//    void (*hash_node_free)(LiskedHashMapNode *node,int flg);/*用来释放节点内存*/
//    
//}LinkedHashMap;
//
//typedef int (*hash_value_func)(struct _lisked_hash_map *h,const void *key); /*哈希函数*/
//typedef int (*keycmp_func)(struct _lisked_hash_map *h,const void *key1,const void *key2);/*哈希key比较函数，当哈希数值一致时使用*/
//typedef void (*hash_node_free_func)(LiskedHashMapNode *node,int flg);
//
//LiskedHashMapNode * LinkedHashMap_delete(LinkedHashMap *h,void *key);

#endif /* LYCLinkedHashMap_h */
