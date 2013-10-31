#ifndef RADEON_PROFILE_H
#define RADEON_PROFILE_H

#include <QMainWindow>
#include <QString>
#include "qcustomplot.h"
#include <QVector>
#include <QSystemTrayIcon>
#include <QEvent>

namespace Ui {
class radeon_profile;
}

class radeon_profile : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit radeon_profile(QWidget *parent = 0);
    ~radeon_profile();
    QString appHomePath;

    QSystemTrayIcon *trayIcon;
    QAction *closeApp, *dpmSetBattery, *dpmSetBalanced, *dpmSetPerformance,*changeProfile, *refreshWhenHidden;
    QMenu *dpmMenu, *trayMenu, *optionsMenu, *forcePowerMenu;

private slots:
    void on_chProfile_clicked();
    void timerEvent();
    void on_btn_dpmBattery_clicked();
    void on_btn_dpmBalanced_clicked();
    void on_btn_dpmPerformance_clicked();
    void changeTimeRange();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_cb_showFreqGraph_clicked(bool checked);
    void on_cb_showTempsGraph_clicked(bool checked);
    void on_cb_showVoltsGraph_clicked(bool checked);
    void showLegend(bool checked);
    void resetGraphs();
    void forceAuto();
    void forceLow();
    void forceHigh();
    void resetMinMax();

private:
    Ui::radeon_profile *ui;
    QString getPowerMethod();
    QStringList getClocks(const QString);
    QString getCurrentPowerProfile(const QString);
    void setValueToFile(const QString, const QStringList);
    void setValueToFile(const QString, const QString);
    QString getGPUTemp();
    QStringList fillGpuDataTable(const QString);
    QStringList getGLXInfo();
    void setupGraphs();
    void setupTrayIcon();
    void setupOptionsMenu();
    void refreshTooltip();
    void setupForcePowerLevelMenu();
    void testSensor();
    void changeEvent(QEvent *event);
    void getModuleInfo();
};

#endif // RADEON_PROFILE_H
