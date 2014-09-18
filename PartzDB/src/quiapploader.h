#ifndef QUIAPPLOADER_H
#define QUIAPPLOADER_H

#include "quiabout.h"

class QUiAppLoader : public QUiAbout
{
  Q_OBJECT

public:
  explicit QUiAppLoader(QWidget *parent = 0);
  ~QUiAppLoader();

  enum LoadState
  {
    PREINIT,
    INIT,
    CONFIG,
    PLUGINS,
    TRAY,
    MAINWINDOW,
    SETUP,
    DONE
  };

protected:
  void load(void);

private slots:
  void processLoading(void);

public slots:
  void instanceMessage(const QString &message);

private:
  LoadState _state;   //!< Current loading state
  quint32 _progress;  //!< Loading progress value
  quint32 _max;       //!< Maximum progress value
};

inline QUiAppLoader::LoadState& operator++(QUiAppLoader::LoadState &v)
{
  if (v != QUiAppLoader::DONE)
    v = static_cast<QUiAppLoader::LoadState>(static_cast<int>(v)+1);

  return v;
}

#endif // QUIAPPLOADER_H
