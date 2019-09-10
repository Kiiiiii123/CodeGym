'''
题目：输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
'''

'''
方法：递归法
运行时间：26ms
占用内存：5732k
'''

'''
递归算法运行逻辑看着复杂,但是形式上都是简单的.每一层都表达了"当前结点要做的任务"。
思考递归算法的步骤应该是：
    明确每一层要做的任务,例如,选择链表中较小值作为当前结点；
    明确每一层的任务的完结点和递归连接点,例如,在pres.next处进行下一层递归；
    明确return条件,例如,当p1,p2其中有一个为空时,递归任务结束；
几乎所有的递归算法都可以沿着这三个要求思考构造,很自然不怕写递归算法,三个问题能自己在脑里回答出来,稍加修饰就是一个完整的递归算法。
'''

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        if not pHead1:
            return pHead2
        if not pHead2:
            return pHead1
        mergeHead=None
        if pHead1.val<pHead2.val:
            mergeHead=pHead1
            mergeHead.next=self.Merge(pHead1.next,pHead2)
        else:
            mergeHead=pHead2
            mergeHead.next=self.Merge(pHead1,pHead2.next)
        return mergeHead
