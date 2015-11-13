//PIN CONFIGURATION
  #define RELAY_A_PIN          0
  #define RELAY_B_PIN          1
  #define PAUSE_SWITCH_PIN     2    //has to be either 2 or 3 for edgetriggered interrupts
  #define SWITCH_1_PIN         3
  #define ODOR_ARM_B_PIN       13
  #define LARVAE_ARM_B_PIN     5
  #define ODOR_ARM_A_PIN       6
  #define LARVAE_ARM_A_PIN     7
  #define PUMP_PIN             8        
  #define TURNTABLE_PIN        9   
  #define LED_PIN              10

//MOTOR POSITIONS
  //Turntable Positions
    #define REST_PLATE_A 121
    #define WASH_PLATE_A 121  
    #define DRY_PLATE 8    
    #define VOID_PLATE 121 
    #define ODOR_SHOCK_PLATE_A 165 
    #define REST_PLATE_B REST_PLATE_A
    #define WASH_PLATE_B 35
    #define DRY_PLATE_B 71 
    #define ODOR_PLATE_B 107
    #define SHOCK_PLATE_B 137 
    
  //Larvae Arm Positions
    #define GA_ARM_HIGH 80    
    #define GA_ARM_LOW 10
    #define GB_ARM_HIGH 100
    #define GB_ARM_LOW 175

  //Odor Arm Positions
    #define GA_ODOR_ARM_LOW 1
    #define GA_ODOR_ARM_HIGH 100 
    #define GB_ODOR_ARM_LOW 38  
    #define GB_ODOR_ARM_HIGH 85

//Other
  #define DEBOUNCE_COUNT 500
  #define NUMBER_OF_ITERATIONS 4
