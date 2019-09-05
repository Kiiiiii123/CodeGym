'''
题目：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。保证base和exponent不同时为0。
'''

'''
方法一：使用循环。exponent是整数，可能是0、正数或者负数。当其为正数时直接使用循环；当其为负数先求出其绝对值的结果，再取倒数；当其为0时直接返回base。
运行时间：
占用内存：
'''
