import math

def reward_function(params):
    # Example of rewarding the agent to follow center line
    
    rew_MIN = -1e5
    rew_MAX = 1e5

    # Read input parameters
    track_width = params['track_width']
    distance_from_center = params['distance_from_center']
    progress = params["progress"]
    steering = params["steering_angle"]
    waypoints = params["waypoints"]
    closest_waypoints = params["closest_waypoints"]
    heading = params["heading"]
    speed = params["speed"]
    car_orientation = params["heading"]

    # Calculate 3 markers that are at varying distances away from the center line
    marker_1 = 0.1 * track_width
    marker_2 = 0.25 * track_width
    marker_3 = 0.7 * track_width
    
    
    # on-track
    if params["is_offtrack"]:
        reward = rew_MIN
    elif progress == 1:
        reward = rew_MAX
    else:
        reward = reward * progress
        
    # steering
    ABS_STEERING_THRESHOLD = 0.9
        
    next_waypoint_yaw = waypoints[min(closest_waypoints[0], len(waypoints)-1)][-1]
    if abs(car_orientation - next_waypoint_yaw) >= math.radians(10):
        reward *= 1 - (abs(car_orientation - next_waypoint_yaw) / 180)
    elif abs(car_orientation - next_waypoint_yaw) < math.radians(10) and abs(steering) > ABS_STEERING_THRESHOLD:    # penalize if stearing to much
        reward *= ABS_STEERING_THRESHOLD / abs(steering)
    else:
        reward *= 1 + (10 - (abs(car_orientation - next_waypoint_yaw) / 10))
        
    if abs(steering) > .5 and abs(steering > speed):
        reward *= 1 - (steering - speed)
    else:
        reward *= 1 + speed

    # Give higher reward if the car is closer to center line and vice versa
    if distance_from_center <= marker_1:
        reward *= 1.0
    elif distance_from_center <= marker_2:
        reward *= 0.7
    elif distance_from_center <= marker_3:
        reward *= 0.3
    # elif distance_from_center > track_width:
    #     reward *= rew_MIN
    
    reward = max(reward, rew_MIN)
    reward = min(reward, rew_MAX)

    return float(reward)
