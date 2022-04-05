#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_tutorial_4.msg import yh_msg_4

def msgCallback(msg):

    rospy.loginfo("receieve message: %d", msg.stamp.secs)
    rospy.loginfo("receieve message: %d", msg.stamp.nsecs)
    rospy.loginfo("receieve message: %d", msg.data)

def listner():
    rospy.init_node("sub_4", anonymous=True)
    rospy.Subscriber("topic_4", yh_msg_4, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()
