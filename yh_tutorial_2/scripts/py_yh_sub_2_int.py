#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_tutorial_2.msg import yh_msg_2

def msgCallback(msg):
    if msg.data%2 == 1 :
        rospy.loginfo("receieve message: %d", msg.stamp.secs)
        rospy.loginfo("receieve message: %d", msg.stamp.nsecs)
        rospy.loginfo("receieve message: %d", msg.data)

def listner():
    rospy.init_node("py_yh_sub_2_int", anonymous=True)
    rospy.Subscriber("yh_topic_2", yh_msg_2, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()
