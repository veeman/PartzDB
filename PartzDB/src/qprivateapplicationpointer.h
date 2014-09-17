#ifndef QPRIVATEAPPLICATIONPOINTER_H
#define QPRIVATEAPPLICATIONPOINTER_H

#include <QtCore/qglobal.h>

template <typename T>
class QPrivateApplicationPointer
{
  friend class QIntSingleApplication;

public:
  explicit inline QPrivateApplicationPointer(T *p = 0) : _d(p)
  {
  }

  inline void set(T *p)
  { 
    if (!_d)
      _d = p; 
  }

  inline T *operator->() const
  {
    Q_ASSERT(_d);
    return _d;
  }

  inline T &operator*() const
  {
    Q_ASSERT(_d);
    return *_d;
  }

protected:
  inline ~QPrivateApplicationPointer()
  {
    free();
  }

  inline void free()
  { 
    delete _d; 
    _d = 0;
  };

private:
  T *_d;
  Q_DISABLE_COPY(QPrivateApplicationPointer);
};

#endif

