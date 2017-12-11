#pragma config(Sensor, S1,     TouchSensor,    sensorTouch)
#pragma config(Sensor, S2,     RGBSensor,      sensorColorNxtFULL)
#pragma config(Sensor, S3,     SoundSensor,    sensorSoundDB)z

void go()
{
   nxtDisplayTextLine(4, "Go");
   motor[motorA]=30;
   motor[motorB]=-30;
   motor[motorC]=-30;
   wait1Msec(1000);
}

void red_turn()
{
   nxtDisplayTextLine(4, "Stop Car");
   motor[motorA]=0;
   motor[motorB]=-30;
   motor[motorC]=30;
   wait1Msec(3000);
}

void blue_backwards()
{
   nxtDisplayTextLine(4, "Go Car");
   back();
}

void notouch_dangerous()
{
   nxtDisplayTextLine(4, "Dangerous!!");
   motor[motorA]=0;
   motor[motorB]=0;
   motor[motorC]=0;
   wait1Msec(1000);
   
   motor[motorA]=-15;
   motor[motorB]=15;
   motor[motorC]=15;
   wait1Msec(4000);
   
   motor[motorA]=0;
   motor[motorB]=-20;
   motor[motorC]=20;
   wait1Msec(750);
}

task main()
{
   while(1){
      go();
      nxtDisplayTextLine(4, "Safe Zone");
      if(SensorValue[RGBSensor] == REDCOLOR){
         red_turn();
         continue;
      }
      else if(SensorValue[RGBSensor] == BLUECOLOR){
         blue_backwards();
         continue;
      }
      else if(SensorValue[SoundSensor]>90){
         break;      
      }
      else if(SensorValue[TouchSensor] == 0){
         notouch_dangerous();
         continue;
      }
   }
}