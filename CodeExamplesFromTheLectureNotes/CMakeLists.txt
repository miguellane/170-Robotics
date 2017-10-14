cmake_minimum_required(VERSION 2.8.3)
project(simple)

find_package(catkin REQUIRED COMPONENTS  roscpp geometry_msgs turtlesim tf2 actionlib move_base_msgs actionlib_msgs)
catkin_package()

include_directories(  ${catkin_INCLUDE_DIRS} )

add_executable(chatter src/chatter.cpp)
add_executable(listener src/listener.cpp)
add_executable(drawsquare src/drawsquare.cpp)
add_executable(republishpose src/republishpose.cpp)
add_executable(followplan src/followplan.cpp)
add_executable(servicecall src/servicecall.cpp)
add_executable(movearound src/movearound.cpp)
add_executable(movearoundwithfeedback src/movearoundwithfeedback.cpp)

target_link_libraries(chatter ${catkin_LIBRARIES})
target_link_libraries(listener ${catkin_LIBRARIES})
target_link_libraries(drawsquare ${catkin_LIBRARIES})
target_link_libraries(republishpose ${catkin_LIBRARIES})
target_link_libraries(followplan ${catkin_LIBRARIES})
target_link_libraries(servicecall ${catkin_LIBRARIES})
target_link_libraries(movearound ${catkin_LIBRARIES})
target_link_libraries(movearoundwithfeedback ${catkin_LIBRARIES})

