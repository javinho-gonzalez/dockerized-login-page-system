-- 1. CRIAÇÃO DAS TABELAS E ESTRUTURA
CREATE TABLE IF NOT EXISTS usuarios (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    tipo VARCHAR(20) CHECK (tipo IN ('admin', 'estudante')) NOT NULL
);

CREATE TABLE IF NOT EXISTS professores (
    id SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    disciplina VARCHAR(50)
);

CREATE TABLE IF NOT EXISTS biblioteca_virtual (
    id SERIAL PRIMARY KEY,
    titulo VARCHAR(255) NOT NULL,
    tipo VARCHAR(50) CHECK (tipo IN ('video_aula', 'livro')),
    url_acesso TEXT,
    data_publicacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS notas_provas (
    id SERIAL PRIMARY KEY,
    estudante_id INT REFERENCES usuarios(id),
    materia VARCHAR(100),
    nota DECIMAL(4,2),
    tipo_avaliacao VARCHAR(50) -- Ex: 'Prova 1', 'Trabalho Final'
);

-- 2. CRIAÇÃO DOS PAPÉIS (ROLES) DE SEGURANÇA
-- Limpa roles existentes para evitar erros em re-execução
DO $$ 
BEGIN
    IF NOT EXISTS (SELECT FROM pg_catalog.pg_roles WHERE rolname = 'role_admin') THEN
        CREATE ROLE role_admin;
    END IF;
    IF NOT EXISTS (SELECT FROM pg_catalog.pg_roles WHERE rolname = 'role_estudante') THEN
        CREATE ROLE role_estudante;
    END IF;
END $$;

-- 3. DEFINIÇÃO DE PERMISSÕES PARA O ESTUDANTE
-- Estudante: Somente leitura (SELECT) em conteúdos e professores
GRANT SELECT ON biblioteca_virtual TO role_estudante;
GRANT SELECT ON professores TO role_estudante;
GRANT SELECT ON notas_provas TO role_estudante;
-- Estudante não tem acesso à tabela 'usuarios' (privacidade)

-- 4. DEFINIÇÃO DE PERMISSÕES PARA O ADMIN
-- Admin: Acesso total (CRUD) em todas as tabelas
GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA public TO role_admin;
GRANT ALL PRIVILEGES ON ALL SEQUENCES IN SCHEMA public TO role_admin;

-- 5. CRIAÇÃO DOS USUÁRIOS DE CONEXÃO (Para o seu Backend/Docker)
-- Usuário que o aluno usará para logar
DROP USER IF EXISTS user_estudante;
CREATE USER user_estudante WITH PASSWORD 'senha_estudante_123';
GRANT role_estudante TO user_estudante;

-- Usuário que o administrador usará
DROP USER IF EXISTS user_admin;
CREATE USER user_admin WITH PASSWORD 'senha_admin_789';
GRANT role_admin TO user_admin;

-- 6. INSERÇÃO DE DADOS INICIAIS (TESTE)
INSERT INTO professores (nome, disciplina) VALUES ('Dr. Roberto Martins', 'Inteligência Artificial');
INSERT INTO biblioteca_virtual (titulo, tipo, url_acesso) VALUES ('Manual de Redes', 'livro', 'http://biblioteca.com/redes.pdf');
INSERT INTO biblioteca_virtual (titulo, tipo, url_acesso) VALUES ('Aula de Python 01', 'video_aula', 'http://video.com/python01');
INSERT INTO usuarios (nome, email, tipo) VALUES ('Aline','aline@escola.com','estudante');
CREATE USER user_login WITH PASSWORD 'senha_login_123';
GRANT SELECT ON usuarios TO user_login;