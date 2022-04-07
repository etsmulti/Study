#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_star.msg import yh_star_msg

def msgCallback(msg):
    rospy.loginfo("receieve message: %d", msg.stamp.secs)
    rospy.loginfo("receieve message: %d", msg.stamp.nsecs)
    rospy.loginfo("receieve message: %d", msg.data)

    for i in range(1, msg.data):
        if(msg.data / 2 >= i):
            stra = '*' * i
            print(stra)
        else:
            strb = '*' * (msg.data - i)
            print(strb)

    

def listner():
    rospy.init_node("yh_star_sub", anonymous=True)
    rospy.Subscriber("yh_star_topic", yh_star_msg, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()
