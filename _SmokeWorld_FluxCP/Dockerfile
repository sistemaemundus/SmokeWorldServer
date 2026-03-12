FROM php:8.1-apache

# Instala extensões PHP necessárias
RUN apt-get update && apt-get install -y \
    libpng-dev libjpeg-dev libfreetype6-dev \
    && docker-php-ext-configure gd --with-freetype --with-jpeg \
    && docker-php-ext-install -j$(nproc) \
        pdo_mysql \
        mysqli \
        gd \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Habilita mod_rewrite
RUN a2enmod rewrite

# Copia configuração do Apache
COPY _SmokeWorld_FluxCP/apache-config.conf /etc/apache2/sites-available/000-default.conf

# Copia arquivos do FluxCP
COPY _SmokeWorld_FluxCP/ /var/www/html/

# Ajusta permissões
RUN chown -R www-data:www-data /var/www/html \
    && chmod -R 755 /var/www/html

# Script de entrypoint
COPY _SmokeWorld_FluxCP/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

ENTRYPOINT ["entrypoint.sh"]
CMD ["apache2-foreground"]