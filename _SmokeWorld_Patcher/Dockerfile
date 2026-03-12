FROM nginx:alpine

# Remove configuração padrão
RUN rm /etc/nginx/conf.d/default.conf

# Copia configuração customizada
COPY _SmokeWorld_Patcher/nginx.conf /etc/nginx/nginx.conf

EXPOSE 80

CMD ["nginx", "-g", "daemon off;"]