#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include "main.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include "secondlogin.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);



    // Janela Principal
    QWidget window;
    window.setWindowTitle("Login Moderno C++");
    window.setFixedSize(400, 500);
    window.setStyleSheet("background-color: #e3f2fd;"); // Azul claro de fundo

    // Container central (o "Card" branco)
    QWidget *card = new QWidget(&window);
    card->setFixedSize(320, 400);
    card->move(40, 50);
    card->setStyleSheet(
        "QWidget {"
        "   background-color: white;"
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
    QLabel *title = new QLabel("Bem-vindo");
    title->setStyleSheet("font-size: 24px; font-weight: bold; color: #1976d2; border: none;");
    title->setAlignment(Qt::AlignCenter);

    // Campo de Email
    QLineEdit *emailEdit = new QLineEdit();
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
    QLineEdit *passEdit = new QLineEdit();
    passEdit->setPlaceholderText("Senha");
    passEdit->setEchoMode(QLineEdit::Password);
    passEdit->setStyleSheet(emailEdit->styleSheet());

    // Botão de Login
    QPushButton *loginBtn = new QPushButton("ENTRAR");
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

    // Adicionando Widgets ao Layout
    layout->addWidget(title);
    layout->addStretch();
    layout->addWidget(emailEdit);
    layout->addWidget(passEdit);
    layout->addStretch();
    layout->addWidget(loginBtn);

    // Lógica do Botão
    QObject::connect(loginBtn, &QPushButton::clicked, [&]() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName("db");
        db.setDatabaseName("escola_db");
        db.setUserName("user_login");
        db.setPassword("senha_login_123");

        if (db.open()) {
            QSqlQuery query;
            query.prepare("SELECT nome FROM usuarios WHERE email = :email");
            query.bindValue(":email", emailEdit->text());

            if (query.exec() && query.next()) {



            SecondLogin *segunda = new SecondLogin();
            segunda -> show();
            window.hide();
            } else {
            QMessageBox::warning(&window, "Erro", "E-mail ou senha incorretos.");
            }

        } else {

            qDebug() << "ERRO DE CONEXAO:" << db.lastError().text();
            QMessageBox::critical(&window, "Erro", "Falha ao conectar nobanco!");
        }
    });

    window.show();
    return app.exec();
}
