 ## Platform block

 This facility is conceived as a platform for transporting mobs and players.  
 The platform changes the direction of movement when faced with any other blocks.

 **Configuration block example:**

    [PlatformBlock]
    POSITION = 210:500
    SIZE = 80:40
    ANGLE = 0
    SPEED = 1:0
    ELASTIC_COEFFICIENT = 0.2
    FRICTION_COEFFICIENT = 0.4
    IS_FIXED = 1
    TEXTURE = [image-path]
    COLLISION_ANALYSIS_STEP = 5

 ### Explanation:

 * `POSITION` - The parameter sets the position of the block's physical area on the screen. It has the following format - `X:Y`.
 * `SIZE` - The parameter sets the size of the block's physical area on the screen. It has the following format - `WIDTH:HEIGHT`.
 * `ANGLE` - The parameter sets the angle of the block's physical area on the screen.
 * `SPEED` - The parameter sets material object's speed. It has the following format - `X_SPEED:Y_SPEED`.
 * `ELASTIC_COEFFICIENT` - This coefficient uses in jumps calculations.
 * `FRICTION_COEFFICIENT` - This coefficient uses in movement calculations.
 * `IS_FIXED` - If this flag is not set, the obstacle will be affected by static effects.
 * `TEXTURE` - Path to image file in the appropriate directory.
 * `COLLISION_ANALYSIS_STEP` - The collision frequency factor depends on the accuracy of the collision, but the performance suffers.