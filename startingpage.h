#ifndef STARTINGPAGE_H
#define STARTINGPAGE_H

#include <QWidget>

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

//    void on_radioButton_clicked(bool checked);

private:
    Ui::StartingPage *ui;
};

#endif // STARTINGPAGE_H
