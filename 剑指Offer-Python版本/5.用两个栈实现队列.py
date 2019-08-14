'''
题目：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
'''

'''
方法：两个栈stack1和stack2， push的时候直接push进stack1，pop时需要判断stack1和stack2中的情况。如果stack2不为空的话，直接从stack2中pop，如果stack2为空，把stack1中的值push到stack2中，然后再pop stack2中的值。
运行时间：68ms
占用内存：5792k
'''
