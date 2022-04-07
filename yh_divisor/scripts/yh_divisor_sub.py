#!/usr/bin/python
# -*- coding: utf-8 -*-

import rospy
from yh_divisor.msg import yh_divisor_msg

def msgCallback(msg):
    rospy.loginfo("receieve message: %d", msg.stamp.secs)
    rospy.loginfo("receieve message: %d", msg.stamp.nsecs)
    rospy.loginfo("receieve message: %d", msg.data)

    
    for i in range(1, msg.data):
        if(msg.data % i == 0):
            print "{0}".format(i),
    print("")


    

def listner():
    rospy.init_node("yh_divisor_sub", anonymous=True)
    rospy.Subscriber("yh_divisor_topic", yh_divisor_msg, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listner()
