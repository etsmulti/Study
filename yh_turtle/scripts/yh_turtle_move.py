#!/home/min/anaconda3/bin/python
# -*- coding: utf8 *-*

import rospy
from geometry_msgs.msg import Twist

def talker():
    rospy.init_node("yh_tutle_move")
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size=100)
    msg = Twist()

    msg.linear.x = 0.1
    loop_rate = rospy.Rate(1)
 
    while not rospy.is_shutdown():    
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

