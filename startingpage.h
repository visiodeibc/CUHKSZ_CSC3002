#ifndef STARTINGPAGE_H
#define STARTINGPAGE_H

#include <QWidget>
#include <QMediaPlayer>

namespace Ui {
class StartingPage;
}

class StartingPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartingPage(QWidget *parent = nullptr);
    ~StartingPage();

private slots:

    void on_pushButton_clicked();

    void on_radioButton1_clicked();

    void on_radioButton2_clicked();

    void on_radioButton3_clicked();

private:
    Ui::StartingPage *ui;

    // Setup for the soundtrack
    QMediaPlayer * music_sp;
};

#endif // STARTINGPAGE_H
