// Auto-generated. Do not edit!

// (in-package husky_msgs.msg)


"use strict";

let _serializer = require('../base_serialize.js');
let _deserializer = require('../base_deserialize.js');
let _finder = require('../find.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class HuskyStatus {
  constructor() {
    this.header = new std_msgs.msg.Header();
    this.uptime = 0;
    this.ros_control_loop_freq = 0.0;
    this.mcu_and_user_port_current = 0.0;
    this.left_driver_current = 0.0;
    this.right_driver_current = 0.0;
    this.battery_voltage = 0.0;
    this.left_driver_voltage = 0.0;
    this.right_driver_voltage = 0.0;
    this.left_driver_temp = 0.0;
    this.right_driver_temp = 0.0;
    this.left_motor_temp = 0.0;
    this.right_motor_temp = 0.0;
    this.capacity_estimate = 0;
    this.charge_estimate = 0.0;
    this.timeout = false;
    this.lockout = false;
    this.e_stop = false;
    this.ros_pause = false;
    this.no_battery = false;
    this.current_limit = false;
  }

  static serialize(obj, bufferInfo) {
    // Serializes a message object of type HuskyStatus
    // Serialize message field [header]
    bufferInfo = std_msgs.msg.Header.serialize(obj.header, bufferInfo);
    // Serialize message field [uptime]
    bufferInfo = _serializer.uint32(obj.uptime, bufferInfo);
    // Serialize message field [ros_control_loop_freq]
    bufferInfo = _serializer.float64(obj.ros_control_loop_freq, bufferInfo);
    // Serialize message field [mcu_and_user_port_current]
    bufferInfo = _serializer.float64(obj.mcu_and_user_port_current, bufferInfo);
    // Serialize message field [left_driver_current]
    bufferInfo = _serializer.float64(obj.left_driver_current, bufferInfo);
    // Serialize message field [right_driver_current]
    bufferInfo = _serializer.float64(obj.right_driver_current, bufferInfo);
    // Serialize message field [battery_voltage]
    bufferInfo = _serializer.float64(obj.battery_voltage, bufferInfo);
    // Serialize message field [left_driver_voltage]
    bufferInfo = _serializer.float64(obj.left_driver_voltage, bufferInfo);
    // Serialize message field [right_driver_voltage]
    bufferInfo = _serializer.float64(obj.right_driver_voltage, bufferInfo);
    // Serialize message field [left_driver_temp]
    bufferInfo = _serializer.float64(obj.left_driver_temp, bufferInfo);
    // Serialize message field [right_driver_temp]
    bufferInfo = _serializer.float64(obj.right_driver_temp, bufferInfo);
    // Serialize message field [left_motor_temp]
    bufferInfo = _serializer.float64(obj.left_motor_temp, bufferInfo);
    // Serialize message field [right_motor_temp]
    bufferInfo = _serializer.float64(obj.right_motor_temp, bufferInfo);
    // Serialize message field [capacity_estimate]
    bufferInfo = _serializer.uint16(obj.capacity_estimate, bufferInfo);
    // Serialize message field [charge_estimate]
    bufferInfo = _serializer.float64(obj.charge_estimate, bufferInfo);
    // Serialize message field [timeout]
    bufferInfo = _serializer.bool(obj.timeout, bufferInfo);
    // Serialize message field [lockout]
    bufferInfo = _serializer.bool(obj.lockout, bufferInfo);
    // Serialize message field [e_stop]
    bufferInfo = _serializer.bool(obj.e_stop, bufferInfo);
    // Serialize message field [ros_pause]
    bufferInfo = _serializer.bool(obj.ros_pause, bufferInfo);
    // Serialize message field [no_battery]
    bufferInfo = _serializer.bool(obj.no_battery, bufferInfo);
    // Serialize message field [current_limit]
    bufferInfo = _serializer.bool(obj.current_limit, bufferInfo);
    return bufferInfo;
  }

  static deserialize(buffer) {
    //deserializes a message object of type HuskyStatus
    let tmp;
    let len;
    let data = new HuskyStatus();
    // Deserialize message field [header]
    tmp = std_msgs.msg.Header.deserialize(buffer);
    data.header = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [uptime]
    tmp = _deserializer.uint32(buffer);
    data.uptime = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [ros_control_loop_freq]
    tmp = _deserializer.float64(buffer);
    data.ros_control_loop_freq = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [mcu_and_user_port_current]
    tmp = _deserializer.float64(buffer);
    data.mcu_and_user_port_current = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [left_driver_current]
    tmp = _deserializer.float64(buffer);
    data.left_driver_current = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [right_driver_current]
    tmp = _deserializer.float64(buffer);
    data.right_driver_current = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [battery_voltage]
    tmp = _deserializer.float64(buffer);
    data.battery_voltage = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [left_driver_voltage]
    tmp = _deserializer.float64(buffer);
    data.left_driver_voltage = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [right_driver_voltage]
    tmp = _deserializer.float64(buffer);
    data.right_driver_voltage = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [left_driver_temp]
    tmp = _deserializer.float64(buffer);
    data.left_driver_temp = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [right_driver_temp]
    tmp = _deserializer.float64(buffer);
    data.right_driver_temp = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [left_motor_temp]
    tmp = _deserializer.float64(buffer);
    data.left_motor_temp = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [right_motor_temp]
    tmp = _deserializer.float64(buffer);
    data.right_motor_temp = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [capacity_estimate]
    tmp = _deserializer.uint16(buffer);
    data.capacity_estimate = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [charge_estimate]
    tmp = _deserializer.float64(buffer);
    data.charge_estimate = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [timeout]
    tmp = _deserializer.bool(buffer);
    data.timeout = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [lockout]
    tmp = _deserializer.bool(buffer);
    data.lockout = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [e_stop]
    tmp = _deserializer.bool(buffer);
    data.e_stop = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [ros_pause]
    tmp = _deserializer.bool(buffer);
    data.ros_pause = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [no_battery]
    tmp = _deserializer.bool(buffer);
    data.no_battery = tmp.data;
    buffer = tmp.buffer;
    // Deserialize message field [current_limit]
    tmp = _deserializer.bool(buffer);
    data.current_limit = tmp.data;
    buffer = tmp.buffer;
    return {
      data: data,
      buffer: buffer
    }
  }

  static datatype() {
    // Returns string type for a message object
    return 'husky_msgs/HuskyStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fd724379c53d89ec4629be3b235dc10d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    # MCU Uptime, in ms
    uint32 uptime
    
    # ROS Control loop frequency (PC-side)
    float64 ros_control_loop_freq
    
    # Current draw of platform components, in amps
    float64 mcu_and_user_port_current
    float64 left_driver_current
    float64 right_driver_current
    
    # Voltage of platform components, in volts
    float64 battery_voltage
    float64 left_driver_voltage
    float64 right_driver_voltage
    
    # Component temperatures, in C
    float64 left_driver_temp
    float64 right_driver_temp
    float64 left_motor_temp
    float64 right_motor_temp
    
    # Battery capacity (Wh) and charge (%) estimate
    uint16 capacity_estimate
    float64 charge_estimate
    
    # Husky error/stop conditions
    bool timeout
    bool lockout
    bool e_stop
    bool ros_pause
    bool no_battery
    bool current_limit
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    `;
  }

};

module.exports = HuskyStatus;
