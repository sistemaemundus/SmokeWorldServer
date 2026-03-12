FROM mariadb:10

# Copia configuração customizada
COPY my.cnf /etc/mysql/conf.d/my.cnf

# COPIA OS SQLs DA PASTA CORRETA
# O caminho é relativo ao contexto de build (raiz do projeto)
COPY _SmokeWorld_rAthena/_SmokeWorld_Database/sql-files/ /docker-entrypoint-initdb.d/

EXPOSE 3306