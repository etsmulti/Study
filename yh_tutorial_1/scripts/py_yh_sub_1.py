#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_tutorial_1.msg import yh_msg_1

def msgCallback(msg):
    rospy.loginfo("receieve message: %d", msg.stamp.secs)
    rospy.loginfo("receieve message: %d", msg.stamp.nsecs)
    rospy.loginfo("receieve message: %d", msg.data)

def listner():
    rospy.init_node("py_yh_sub_1", anonymous=True)
    rospy.Subscriber("yh_topic_1", yh_msg_1, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()
