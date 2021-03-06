#!/usr/bin/python
# -*- coding: utf-8 -*-

################ !/usr/bin/python3  파이썬 3버전으로 실행할 경우
################ #!/home/min/anaconda3/bin/python3  아나콘다 사용할 경우

import rospy
from yh_sum.msg import yh_sum_msg

class MyClass:
    def __init__(self):
        self.sub = rospy.Subscriber("yh_sum_topic", yh_sum_msg, self.msgCallback)
        self.old_data = 0

    def msgCallback(self, msg):
        print(self.old_data + msg.data)
        self.old_data = msg.data
        
  

def listner():
    rospy.init_node("yh_sum_sub", anonymous=True)
    my_class = MyClass()
    rospy.spin()

if __name__ == "__main__":
    listner()
