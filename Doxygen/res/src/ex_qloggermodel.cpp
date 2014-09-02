//! [0]
  QLoggerModel *log = new QLoggerModel(this);
  QListView *listView = new QListView(this);
  listView->setModel(log);
  
  log->info("Application start.", "Init");
  log->warning("No 'config.ini' found.", "ConfigManager");
  log->critical("Faild to load plugin 'libpng'", "PluginLoader");
//! [0]