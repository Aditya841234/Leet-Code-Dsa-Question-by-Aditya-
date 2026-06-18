class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hours_angel = (hour*60+minutes)*0.5;
        double minutes_angel = minutes*6;

        double angel = abs(hours_angel-minutes_angel);

        if(angel <= 180.0){
                  return angel;
        }
        else{
           return 360.0-angel;
        }
    }
};