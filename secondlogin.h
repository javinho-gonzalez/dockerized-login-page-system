#ifndef SECONDLOGIN_H
#define SECONDLOGIN_H

#include <QWidget>

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>

class SecondLogin : public QWidget {
    Q_OBJECT
public:
    explicit SecondLogin(QWidget *parent = nullptr);

private:

    QVBoxLayout *layout;
    QLabel *title;
    QLineEdit *tokenEdit;
    QLineEdit *emailEdit;
    QLineEdit *passEdit;
    QPushButton *confirmBtn;
    QGraphicsDropShadowEffect *shadow;
    QWidget *card;
    QWidget *firstWindow;
    QPushButton *loginBtn2;
};

#endif // SECONDLOGIN_H