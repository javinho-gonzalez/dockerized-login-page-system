# 🏫 Dockerized Login Page System (Containerization Project)

Beginner containerization project demonstrating how to deploy a login application using Docker and PostgreSQL.

## Objective
This project demonstrates how to containerize and deploy a simple application using Docker

## Description
In this project, I used Docker to create and manage containers for a login page application integratedwith a PostgreSQL database. The goal was to understand how applications can be isolated, deployed, and run consistently across environments.

## What I implemented
- Created Docker containers for application and database
- Created PostgreSQL data base specifying roles and permissions
- Set up application environment using Docker
- Managed container lifecycle with Docker compose
- Tested application development and functionality

## Tools used
- Docker
- Docker Compose
- PostgreSQL
- C++ / QT

## Key concepts demonstrated
- Containerization
- Environment Isolation
- Multi-container orchestration
- Basic database security (roles and permissions)
- Deployment consistency

---

## 🚀 How to run the program (Quick Start)

### Requirements
-  Docker Desktop installed and running
- X-Server (MobaXterm ou VcXsrv for Windows).


### 1. Start X Server
Before running the containers:
- Open **MobaXterm** or **VcXsrv**
- Ensure X11 is enabled (for GUI display)

---

### 2. Run the application
In the terminal execute:
```bash
docker-compose up --build

🛠️ Project Structure
main.cpp → Application logic and database connection
Dockerfile → Environment setup(Qt5 + dependencies).
docker-compose.yml → Orquestration between app and database.
init.sql → Database schema and role configuration.

🔑 Testing login credentials
Pre-configured test user:
E-mail → aline@escola.com
Action → click on login.

🛡️ Security
Implemented role-based access control in PostgreSQL:
user_login → Access to user table and  email validation.
user_estudante → Limitted acces to content and scores.

🌿 Branches 
main → Stable version
desenvolvimento → Development branch befor merging to main

🧠 What I Learned
- How to containerize applications using Docker
- How to manage multi-container environments with Docker Compose
- Basics of database role-based access control
- Importance of environment consistency in development

👨‍💻 Author
Developed  by Javier Gonzalez 🚀
