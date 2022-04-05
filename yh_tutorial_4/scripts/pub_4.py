#!/usr/bin/python
# -*- coding: utf-8 -*-


import rospy
from yh_tutorial_4.msg import yh_msg_4

def talker():
   
    pub = rospy.Publisher("yh_topic_4",yh_msg_4,queue_size=100)
    rospy.init_node("pub_4",anonymous=True)
    loop_rate = rospy.Rate(10)
    cnt = 0
    msg = yh_msg_4()


    while not rospy.is_shutdown():
        msg.stamp = rospy.get_rostime()
        msg.data = cnt 
        rospy.loginfo("send message: %d", msg.stamp.secs)
        rospy.loginfo("send message: %d", msg.stamp.nsecs)
        rospy.loginfo("send message: %d", msg.data)

        cnt += 1
        pub.publish(msg)
        loop_rate.sleep() 
        
if __name__=="__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass