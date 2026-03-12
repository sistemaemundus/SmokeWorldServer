#!/bin/bash
set -e

echo "========================================="
echo "Iniciando entrypoint do FluxCP SmokeWorld"
echo "========================================="

# Função para aguardar banco de dados
wait_for_db() {
    echo "Aguardando banco de dados em $DB_HOST:$DB_PORT..."
    until nc -z $DB_HOST $DB_PORT; do
        echo "Banco de dados não disponível ainda - aguardando 2 segundos..."
        sleep 2
    done
    echo "? Banco de dados disponível!"
}

# Executa wait_for_db
wait_for_db

echo "Configurando arquivos do FluxCP..."

# Verifica se a pasta config existe e tem permissão de escrita
if [ ! -d "/var/www/html/config" ]; then
    echo "Criando pasta config..."
    mkdir -p /var/www/html/config
fi

# Se existir um arquivo de template, cria o config real
if [ -f "/var/www/html/config/servers.php.template" ]; then
    echo "Gerando servers.php a partir do template..."
    
    # Substitui as variáveis no template
    sed -e "s/\${DB_HOST}/$DB_HOST/g" \
        -e "s/\${DB_PORT}/$DB_PORT/g" \
        -e "s/\${DB_USER}/$DB_USER/g" \
        -e "s/\${DB_PASS}/$DB_PASS/g" \
        -e "s/\${DB_NAME}/$DB_NAME/g" \
        -e "s/\${SERVER_HOST}/$SERVER_HOST/g" \
        /var/www/html/config/servers.php.template > /var/www/html/config/servers.php
    
    echo "? servers.php gerado"
fi

# Se não existir servers.php, tenta criar um básico
if [ ! -f "/var/www/html/config/servers.php" ]; then
    echo "Criando servers.php básico..."
    cat > /var/www/html/config/servers.php << EOF
<?php
// Configuração gerada automaticamente pelo entrypoint - SmokeWorld
// Data: $(date)

return [
    'database' => [
        'default' => [
            'host' => '$DB_HOST',
            'port' => $DB_PORT,
            'user' => '$DB_USER',
            'pass' => '$DB_PASS',
            'db'   => '$DB_NAME',
        ],
    ],
    'servers' => [
        'servidor' => [
            'name' => 'SmokeWorld',
            'loginServer' => [
                'host' => '$SERVER_HOST',
                'port' => 6900,
            ],
            'charServer' => [
                'host' => '$SERVER_HOST',
                'port' => 6121,
            ],
            'mapServer' => [
                'host' => '$SERVER_HOST',
                'port' => 5121,
            ],
        ],
    ],
];
EOF
    echo "? servers.php criado"
fi

# Ajusta permissões
echo "Ajustando permissões..."
chown -R www-data:www-data /var/www/html
chmod -R 755 /var/www/html

echo "? Permissões ajustadas"

echo ""
echo "========================================="
echo "Iniciando Apache para o FluxCP SmokeWorld"
echo "========================================="

# Executa o comando original do PHP-Apache
exec "$@"