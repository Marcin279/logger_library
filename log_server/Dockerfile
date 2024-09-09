FROM python:3.9-slim

# Skopiuj plik serwera do kontenera
COPY log_server.py /app/log_server.py

# Ustaw katalog roboczy
WORKDIR /app

# Uruchom serwer Pythonowy
CMD ["python3", "log_server.py"]