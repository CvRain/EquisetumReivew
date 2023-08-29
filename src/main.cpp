#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <SQLiteCpp/SQLiteCpp.h>
#include <loguru/loguru.hpp>

int main(int argc, char *argv[])
{
    loguru::init(argc, argv);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("EquisetumReivew", "Main");

    LOG_F(INFO, "sqlite3 version: %s(%s)", SQLite::VERSION, SQLite::getLibVersion());
    LOG_F(INFO, "sqliteC++ Version: %s", SQLITECPP_VERSION);

    return app.exec();
}
