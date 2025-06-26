#ifndef _TIME_H_
#define _TIME_H_

#include <jsoncpp/json/json.h>

class Time
{
public:
  int time_sec;

  Time();
  Time(int);

  const int getTime();
  virtual Json::Value *dump2JSON(void);
};

#endif /* _TIME_H_ */
