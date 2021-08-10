#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt16.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

std::string command;
std::string command_stop1;
std::string command_stop2;
std::string command_stop3;
std::string command_stop4;
std::string command_stop5;
std::string command_stop6;

const char *c;

const char *a;
const char *d;
const char *o;
const char *p;
const char *s;

const char *m;


void mission_Callback(const std_msgs::UInt16 msg)
{
    if(msg.data == 1){
        ROS_INFO("Mission: AutoDriving");

        command = "gnome-terminal -- rosrun autodriving_state autodriving_state";
        command_stop1 = "rosnode kill /autodriving_state";
    }

    else if(msg.data == 2){
        ROS_INFO("Mission: Door");

        command = "gnome-terminal -- rosrun door_state door_state";
        command_stop2 = "rosnode kill /door_state";
    }

    else if(msg.data == 3){
        ROS_INFO("Mission: Obstacle");
        //command = "gnome-terminal -- rosrun lidar_range wall_following";
        //command_stop3 = "rosnode kill /wall_following";
        command = "gnome-terminal -- rosrun turtlesim turtlesim_node";
        command_stop3 = "rosnode kill /turtlesim";
    }

    else if(msg.data == 4){
        ROS_INFO("Mission: Parking");

        command = "gnome-terminal -- rosrun lidar_range drok3_parking";
        command_stop4 = "rosnode kill /drok3_parking";
    }

    else if(msg.data == 5){
        ROS_INFO("Mission: Stair");
        //command = "roslaunch ";
    }

    else if(msg.data == 60){
        ROS_INFO("md_driver start");

        command = "gnome-terminal -- rosrun md_driver md_driver_demo_node";
        command_stop6 = "rosnode kill /md_driver_node";
    }

    else if(msg.data == 0){
        ROS_INFO("Mission Start!!");

        c = command.c_str();
        system(c);
    }

    else if(msg.data == 9){
        ROS_INFO("Mission All Stop!!");

        a = command_stop1.c_str();
        d = command_stop2.c_str();
        o = command_stop3.c_str();

        system(a);
        system(d);
        system(o);
        //system(p);
        //system(s);
    }



    if(msg.data == 11){
        //command_stop1 = "rosnode kill /autodriving_state";
        a = command_stop1.c_str();
        system(a);
    }
    else if(msg.data == 12){
        //command_stop2 = "rosnode kill /door_state";
        d = command_stop2.c_str();
        system(d);
    }
    else if(msg.data == 13){
        //command = "rosnode kill /wall_following";
        o = command_stop3.c_str();
        system(o);
    }
    else if(msg.data == 14){
        //command = "rosnode kill /drok3_parking";
        p = command_stop4.c_str();
        system(p);
    }
    else if(msg.data == 15){
        //command = "rosnode kill /door_state";
        //system(command);
    }

    else if(msg.data == 61){
        //command_stop2 = "rosnode kill /door_state";
        m = command_stop6.c_str();
        system(m);
    }

    if(msg.data == 99){

    }


}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "getmission");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("mission", 10, mission_Callback);

    ros::spin();

    return 0;
}
