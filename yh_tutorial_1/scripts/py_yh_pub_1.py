#!/usr/bin/python
# -*- coding: utf-8 -*-


""" 필수 상황

#!/usr/bin/python
# -*- coding: utf-8 -*-
한글을 쓸며면 이렇게 해야 됩니다. 
 """
import rospy
from yh_tutorial_1.msg import yh_msg_1

def talker():
   
    pub = rospy.Publisher("yh_topic_1",yh_msg_1,queue_size=100)
    rospy.init_node("py_yh_pub_1",anonymous=True)
    loop_rate = rospy.Rate(2)
    cnt = 0
    msg = yh_msg_1()


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