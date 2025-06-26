#ifndef _Signal_H_
#define _Signal_H_

#include <jsoncpp/json/json.h>

class Signal
{
public:
  std::string name;

  Signal();
  Signal(std::string);
  bool operator<(const Signal& another) const;
  virtual Json::Value *dump2JSON(void);
};

#endif /* _Signal_H_ */
