#include "secondlogin.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QMessageBox>


SecondLogin::SecondLogin(QWidget *parent) : QWidget(parent){

    //firstWindow = parentWindow;

    //loginBtn2 = new QPushButton("VOLTAR",this);

    //emailEdit = new QLineEdit(card);

    //passEdit = new QLineEdit(card);

    //Janela Principal
    //QWidget (this);
    this->setWindowTitle("Login Moderno C++");
    this->setFixedSize(400, 500);
    this->setStyleSheet("background-color: #e3f2fd;"); // Azul claro de fundo

    // Container central (o "Card" branco)
    card = new QWidget(this);
    card->setFixedSize(320, 400);
    card->move(40, 50);
    card->setStyleSheet(
        "QWidget {"
        "   background-color: green;"
        "   border-radius: 15px;"
        "}"
        );

    // Efeito de Sombra no Card
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setXOffset(0);
    shadow->setYOffset(5);
    shadow->setColor(QColor(0, 0, 0, 50));
    card->setGraphicsEffect(shadow);

    // Layout Interno do Card
    QVBoxLayout *layout = new QVBoxLayout(card);
    layout->setContentsMargins(30, 40, 30, 40);
    layout->setSpacing(20);

    // Título
    QLabel *title = new QLabel("STUDENT HUB");
    title->setStyleSheet("font-size: 24px; font-weight: bold; color: #1976d2; border: none;");
    title->setAlignment(Qt::AlignCenter);

    // Campo de Email
    emailEdit = new QLineEdit(card);
    emailEdit->setPlaceholderText("E-mail");
    emailEdit->setStyleSheet(
        "QLineEdit {"
        "   border: 2px solid #e0e0e0;"
        "   border-radius: 8px;"
        "   padding: 10px;"
        "   background-color: #f9f9f9;"
        "   font-size: 14px;"
        "}"
        "QLineEdit:focus { border: 2px solid #2196f3; }"
        );

    // Campo de Senha
    passEdit = new QLineEdit(card);
    passEdit->setPlaceholderText("Senha");
    passEdit->setEchoMode(QLineEdit::Password);
    passEdit->setStyleSheet(emailEdit->styleSheet());

    // Botão de Login
    QPushButton *loginBtn = new QPushButton("ENTRAR",card);
    loginBtn->setCursor(Qt::PointingHandCursor);
    loginBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: #2196f3;"
        "   color: white;"
        "   font-weight: bold;"
        "   border-radius: 8px;"
        "   padding: 12px;"
        "   font-size: 14px;"
        "}"
        "QPushButton:hover { background-color: #1e88e5; }"
        "QPushButton:pressed { background-color: #1565c0; }"
        );

    // Botão voltar
    QPushButton *loginBtn2 = new QPushButton("VOLTAR",card);
    loginBtn2->setCursor(Qt::PointingHandCursor);
    loginBtn2->setStyleSheet(
        "QPushButton {"
        "   background-color: #2196f3;"
        "   color: white;"
        "   font-weight: bold;"
        "   border-radius: 8px;"
        "   padding: 12px;"
        "   font-size: 14px;"
        "   min-width: 50px;"
        "   min-height: 10px;"
        "}"
        "QPushButton:hover { background-color: #1e88e5; }"
        "QPushButton:pressed { background-color: #1565c0; }"
        );

    // Adicionando Widgets ao Layout
    layout->addWidget(title);
    layout->addStretch();
    layout->addWidget(emailEdit);
    layout->addWidget(passEdit);
    layout->addStretch();
    layout->addWidget(loginBtn);
    layout->addWidget(loginBtn2);

    // Lógica do Botão loginBtn
    QObject::connect(loginBtn, &QPushButton::clicked, this, [this]() {

        if (emailEdit->text().isEmpty() || passEdit->text().isEmpty()) {
            QMessageBox::warning(this,"Campos vazios","Por favo, preecha o e-mail e a senha.");
        }
        QRegularExpression emailRegex("^[a-z09._%+-]+@[a-z0-9.-]+\\.[a-z]{2,}$",QRegularExpression::CaseInsensitiveOption);
        if (!emailRegex.match(emailEdit->text()).hasMatch()) {
            QMessageBox::warning(this,"/e-mail Invalido","O formato do e-mail não é valido.");
            return;
        }
        QRegularExpression senhaRegex("^(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$5^&*()_+\\-=\\[\\]{};':\'\\\\|,.<>\\/?]).+$");
        if (!senhaRegex.match(passEdit->text()).hasMatch()) {
            QMessageBox::warning(this, "Senha Fraca","A senha deve conter pelo menos:\n- 1 Letra maiuscula\n- 1 número\n- 1 símbolo");
            return;
        }
        if (emailEdit->text() == "admin@email.com" && passEdit->text() == "Admin@123") {
            QMessageBox::information(this, "Sucesso", "Login realizado!");
        }
        else {
            QMessageBox::warning(this, "Erro", "E-mail ou senha incorretos.");
        }
    });

    // Lógica do Botão loginBtn2
    QObject::connect(loginBtn2, &QPushButton::clicked, this, [this]() {

        //QWidget *primeira = new QWidget();
        //primeira -> show();
        if (this -> firstWindow) {
            this -> firstWindow -> show();
            this->close();
        }
    });

    this->show();
};