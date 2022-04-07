#!/usr/bin/python
# -*- coding: utf-8 -*-

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
