#ifndef QPRIVATEAPPLICATIONPOINTER_H
#define QPRIVATEAPPLICATIONPOINTER_H

#include <QtCore/qglobal.h>

/*!
    \class QPrivateApplicationPointer
    \brief The %QIntSingleApplication class holds a reference to a pointer.

    Can only destroyed by the friend class QIntSingleApplication.
*/
template <typename T>
class QPrivateApplicationPointer
{
  friend class QIntSingleApplication;

public:
  /*!
    Creates a QPrivateApplicationPointer that points to \a p.
  */
  explicit inline QPrivateApplicationPointer(T *p = 0) : _d(p)
  {
  }

  /*!
    Assigns a new value \a p to pointer's members.
  */
  inline void set(T *p)
  { 
    if (!_d)
      _d = p; 
  }

  /*!
    Provides access to the pointer's members.
  */
  inline T *operator->() const
  {
    Q_ASSERT(_d);
    return _d;
  }

  /*!
    Provides access to the pointer's members.
  */
  inline T &operator*() const
  {
    Q_ASSERT(_d);
    return *_d;
  }

protected:
  /*!
    Destroys the %QPrivateApplicationPointer object and the associated pointer reference.
  */
  inline ~QPrivateApplicationPointer()
  {
    free();
  }

  /*!
    Provides access to the pointer's members.
  */
  inline void free()
  { 
    delete _d; 
    _d = 0;
  };

private:
  T *_d;  //!< Pointer Member
  Q_DISABLE_COPY(QPrivateApplicationPointer);
};

#endif

