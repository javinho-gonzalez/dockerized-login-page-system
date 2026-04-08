# 🏫 Sistema de Login Escolar (C++ & Docker)

Este projeto é uma aplicação de login moderna desenvolvida em *C++/Qt, utilizando **PostgreSQL* como banco de dados e *Docker* para garantir que todos na equipe rodem o mesmo ambiente, sem necessidade de instalações locais complexas.

## 🚀 Como Rodar o Projeto (Quick Start)

Para rodar este projeto, você precisará apenas do *Docker Desktop* e de um *X-Server* (MobaXterm ou VcXsrv).

### 1. Pré-requisitos
*   [Docker Desktop](https://docker.com) instalado e rodando.
*   [MobaXterm](https://mobatek.net) (Recomendado) ou XLaunch instalado.

## 🌿 Branches do Projeto
Para manter a organização, utilizamos o seguinte padrão:
*   *main*: Versão estável e funcional (não mexer diretamente).
*   *desenvolvimento*: Branch para testes e novas funcionalidades. 
> *Atenção:* Se você for um colaborador, certifique-se de trabalhar sempre na branch desenvolvimento antes de solicitar um merge para a main.

### 2. Configuração do Monitor (X11)
Antes de iniciar os containers, você deve abrir o *MobaXterm* para que a interface gráfica do Docker possa aparecer no seu Windows:
1. Abra o MobaXterm.
2. Certifique-se de que o ícone *X11* no topo está verde.
3. Nas configurações de X11, garanta que "X11 remote access" esteja em *Full*.

### 3. Iniciando o Sistema
No terminal da pasta do projeto, execute:
```bash
docker-compose up --build
Use o código com cuidado.

🛠️ Estrutura do Projeto
/main.cpp: Lógica da interface e conexão com o banco de dados.
Dockerfile: Configuração do ambiente Linux (instalação de Qt5 e Drivers SQL).
docker-compose.yml: Orquestração entre o App e o Banco de Dados.
init.sql: Script de criação das tabelas e permissões de segurança.
🔑 Dados para Teste
O banco de dados já nasce com um usuário pré-cadastrado para testes:
E-mail: aline@escola.com
Usuário de DB: user_login (focado apenas em autenticação).
🛡️ Segurança
Implementamos uma hierarquia de Roles no PostgreSQL:
user_login: Possui acesso apenas à tabela de usuários para validação de e-mail.
user_estudante: Acesso limitado a conteúdos e notas.
Desenvolvido por Javier Gonzalez 🚀