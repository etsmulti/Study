#!/usr/bin/python
# -*- coding: utf-8 -*-

################ !/usr/bin/python3  파이썬 3버전으로 실행할 경우
################ #!/home/min/anaconda3/bin/python3  아나콘다 사용할 경우

import rospy
from yh_sum.msg import yh_sum_msg

sum = 0
def msgCallback(msg):
    rospy.loginfo("receieve message: %d", msg.stamp.secs)
    rospy.loginfo("receieve message: %d", msg.stamp.nsecs)
    rospy.loginfo("receieve message: %d", msg.data)
    global sum
    sum = sum + msg.data
    print(sum)
   

def listner():
    rospy.init_node("yh_sum_sub", anonymous=True)
    rospy.Subscriber("yh_sum_topic", yh_sum_msg, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()
