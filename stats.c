#include "stats.h"
#include "declaration.h"
#include "math.h"
/*struct stats{
  int average;
  int min;
  int max;
};*/
struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
  if(setlength==NAN || numberset ==NAN)
  {
    s.average = 0;
    s.min = 0;
    s.max = 0;
    return s;
  }
  int count;
    float min = numberset[0], max = numberset[0], add=0;
    float average =0;
    for(count=0;count<setlength;count++)
    {
        if(numberset[count] > max)
        {
            max=numberset[count];
        }
        if(numberset[count]<min)
        {
            min=numberset[count];
        }
        add+=numberset[count];
        average =add/setlength;
    }
    s.average = average;
    s.min = min;
    s.max = max;
    return s;
}
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter()
{
  emailAlertCallCount =1;
}
void ledAlerter()
{
 ledAlertCallCount =1; 
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
{
  if(computedstats.max>maxThreshold)
  {
     *alerters();//email alert
    *(alerters+1)();//led alert
  }
}
  
  
  
