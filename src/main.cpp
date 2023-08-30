#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <loguru/loguru.hpp>

#include "database_service.hpp"

int main(int argc, char *argv[])
{
    loguru::init(argc, argv);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("EquisetumReivew", "Main");

    const auto& databaseInstance =  DatabaseService::GetInstance();

    return QGuiApplication::exec();
}
